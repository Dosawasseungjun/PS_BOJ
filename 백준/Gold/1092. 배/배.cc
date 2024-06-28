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
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    int m; cin >> m;
    
    vector<int> b(m+1);
    for(int i=1;i<=m;i++){
        cin >> b[i];
    }

    sort(++a.begin(), a.end(), greater<int>());
    sort(++b.begin(), b.end(), greater<int>());
    if(b[1] > a[1]){
        cout << -1;
    }else{
        int res = 0;
        while(b.size() > 1){
            res++;
            for(int i=1;i<=n;i++){
                if(a[i] < b[b.size()-1]) continue;
                for(int j=1;j<b.size();j++){
                    if(a[i] >= b[j]){
                        b.erase(b.begin() + j);
                        break;
                    }
                }
            }
        }
        cout << res ;
    }
    
}