#include <bits/stdc++.h>
#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false);
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;
typedef tuple<ll, ll, ll> tlll;
#define xx first
#define yy second


int main(){
    fast_io
    int N, Q; cin >> N >> Q;
    vector<string> log(N);
    cin.ignore();
    vector<string> L[7];
    
    for(int i=0;i<N;i++){
        getline(cin, log[i]);
        char x = log[i].back();
        log[i].pop_back();
        log[i].pop_back();
        for(int j=1;j<=6;j++){
            if(x - '0' >= j) L[j].push_back(log[i]);
        }
    }
    while(Q--){
        string query;
        getline(cin, query);
        int sz = log[0].size();
        string lft = query.substr(0, sz);
        string rgt = query.substr(sz+1, sz);
        char lvl = query.back();
        int lv = lvl - '0';

        int left = lower_bound(L[lv].begin(), L[lv].end(), lft) - L[lv].begin();
        int right = upper_bound(L[lv].begin(), L[lv].end(), rgt) - L[lv].begin();
        cout << right - left << '\n';
    }
}