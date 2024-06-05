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
    map<string, vector<string>> mp;
    for(int i=0;i<n;i++){
        string s, p; cin >> s >> p;
        if(p != "-") mp[p].push_back(s);
    }
    vector<pair<string, string>> ans;
    for(auto [key, val] : mp){
        if(val.size() == 2){
            ans.push_back({val[0], val[1]});
        }
    }
    cout << ans.size() << '\n';
    for(auto [a, b] : ans){
        cout << a << ' ' << b << '\n';
    }
}