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
    int n; cin >> n;
    vector<string> s(n);
    unordered_map<string, int> d;
    for(int i=0;i<n;i++){
        int x;
        cin >> s[i] >> x;
        d[s[i]] = x;
    }
    sort(s.begin(), s.end(), [&](string &a, string &b){
        return d[a] < d[b];
    });
    vector<vector<string>> res(4);
    for(int i=0;i<n;i++){
        res[i % 4].push_back(s[i]);
    }
    for(int i=0;i<4;i++) {
        sort(res[i].begin(), res[i].end());
        cout << i + 1 << ' ';
        for(string ss : res[i]) cout << ss << ' ';
        cout << '\n';
    }
    
}