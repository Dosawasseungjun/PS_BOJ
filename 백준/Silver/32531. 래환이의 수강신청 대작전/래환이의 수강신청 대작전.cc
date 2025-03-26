#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<int> a(m+1);
    for(int i=0;i<n-1;i++){
        int k; cin >> k;
        for(int j=0;j<k;j++){
            int x; cin >> x;
            a[x] |= (1 <<i);
        }
    }
    map<int, int> mp;
    for(int i=1;i<=m;i++) mp[a[i]] += 1;
    int res = 1;
    for(auto [key, value] : mp){
        if(value > 2 || (key == 0 && value == 2)){
            res = 0;
            break;
        }
        if(key == 0 && value == 1) continue;
        res *= 2;
    }

    cout << res << '\n';
}