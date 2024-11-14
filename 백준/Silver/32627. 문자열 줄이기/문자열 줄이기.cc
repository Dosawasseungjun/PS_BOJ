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
    int n, m; cin >> n >> m;
    string s; cin >> s;
    vector<int> v(n);
    int r=0;
    for(int i=0;i<26;i++){
        for(int j=0;j<n;j++){
            if(r < m && s[j] == (char)('a'+i)){
                r++;
                v[j] = 1;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(!v[i]) cout << s[i];
    }
}