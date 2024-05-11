#include <bits/stdc++.h>
#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false);
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int > tiii;

const int MAX = 5e6+1;
ll P[MAX];

int main(){
    fast_io
    int n; cin >> n;
    P[1] = 1;
    for(ll i=2;i<MAX;i++){
        if(P[i]) continue;
        P[i] = i;
        for(ll j=i*i;j<MAX;j+=i){
            if(!P[j]) P[j] = i;
        }
    }
    for(int i=0;i<n;i++){
        int k; cin >> k;
        vector<int> res;
        while(k!=1){
            res.push_back(P[k]);
            k /= P[k];
        }
        
        sort(res.begin(), res.end());
        for(int j=0;j<res.size();j++) cout << res[j] << ' ';
        cout << '\n';
    }
}
