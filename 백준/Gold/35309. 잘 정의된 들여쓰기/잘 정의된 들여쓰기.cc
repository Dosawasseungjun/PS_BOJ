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

void solv(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    vector<set<int>> b(n+1);
    vector<int> c(n+1);
    if(a[0] == 1){
        b[1].insert(0);
        c[0] = 1;
    }else{
        cout << "NO\n";
        return ;
    }
    int k = 0;
    bool ok = true;
    for(int i=1;i<n;i++){
        if(a[i] == 1){ // 직전 칸보다 크게 들여쓰기함
            k += 1;
            if(c[k]) b[c[k]].erase(k);
            b[1].insert(k);
            c[k] = 1;
            continue;
        }
        if(a[i]-1 <= n && !b[a[i]-1].empty()){
            auto it = b[a[i] - 1].upper_bound(k);
            if(it == b[a[i]-1].begin())
                ok = false;
            else{
                it--;
                int kk = *it;
                b[a[i]-1].erase(kk);
                b[a[i]].insert(kk);
                c[kk] = a[i];
                k = kk;
            }
            
        }else{
            ok = false;
        }
        if(!ok) break;
    }

    cout << (ok ? "YES\n" : "NO\n");
}

int main(){
    fast_io
    int tt; cin >> tt;
    while(tt--) solv();
}