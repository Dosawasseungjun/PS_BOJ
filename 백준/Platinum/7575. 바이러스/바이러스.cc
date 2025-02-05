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

const int MOD = 1000000007;
template<ll P, ll M> struct Hashing{
    vector<ll> H, B;
    void build(const vector<ll> &S){
        H.resize(S.size()+1);
        B.resize(S.size()+1);
        B[0] = 1;
        for(int i=1;i<=S.size();i++){
            H[i] = (H[i-1]*P+S[i])%M; //누적합 느낌으로
        }
        for(int i=1;i<=S.size();i++){
            B[i] = (B[i-1]*P)%M;
        }
    }
    ll get(int s, int e){
        ll res= (H[e]-H[s-1]*B[e-s+1])%M;
        return res >= 0 ? res : res+M;
    }
};

Hashing<616327, MOD> ht;

int main(){
    fast_io
    int n, k; cin >> n >> k;
    map<int, set<int>> mp;
    for(int i=0;i<n;i++){
        int sz; cin >> sz;
        vector<ll> S(sz+1);
        for(int j=1;j<=sz;j++) cin >> S[j];
        ht.build(S);
        for(int j=1;j+k-1<=sz;j++){
            int x = ht.get(j, j+k-1);
            mp[x].insert(i);
        }
        reverse(++S.begin(), S.end());
        ht.build(S);
        for(int j=1;j+k-1<=sz;j++){
            int x = ht.get(j, j+k-1);
            mp[x].insert(i);
        }
    }
    bool ok = false;
    for(auto [x, st] : mp){
        if(st.size() == n) ok = true;
    }
    if(ok) cout << "YES\n";
    else cout << "NO\n";
}