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
    vector<int> a(n), b(n);
    for(int i=0;i<n;i++) cin >> a[i], b[i] = a[i];
    sort(b.begin(),b.end());
    vector<int> oddA, oddB, evenA, evenB;
    for(int i=0;i<n;i++){
        if(a[i] & 1) oddA.push_back(a[i]);
        else evenA.push_back(a[i]);
        if(b[i] & 1) oddB.push_back(b[i]);
        else evenB.push_back(b[i]);
    }
    bool ok1=(oddA == oddB && evenA == evenB), ok2=1;
    for(int i=0;i<n;i++){
        if((a[i] & 1) != (b[i] & 1)){
            ok2 = 0;
        }
    }
    
    cout << (ok1 ? "So Lucky\n" : "Unlucky\n");
    cout << (ok2 ? "So Lucky\n" : "Unlucky\n");
}