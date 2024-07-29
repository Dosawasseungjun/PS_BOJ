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
    vector<int> L_cat, R_cat, W(n);
    for(int i=0;i<n;i++){
        int x; cin >> x;
        char c; cin >> c;
        if(c == 'L'){
            L_cat.push_back(x);
        }else{
            R_cat.push_back(x);
        }
        W[i] = (c == 'L');
    }
    sort(L_cat.begin(), L_cat.end());
    sort(R_cat.begin(), R_cat.end());
    int res = 0;
    for(int i=0;i<n;i++){
        int LL = 0, LR = L_cat.size() - 1;
        int RL = 0, RR = R_cat.size() - 1;
        vector<int> arr(n);
        
        for(int j=i;j>=0;j--){
            if(W[j]) arr[j] = L_cat[LR--];
        }
        for(int j=i+1;j<n;j++){
            if(W[j]) arr[j] = L_cat[LR--];
        }
        for(int j=i;j<n;j++){
            if(!W[j]) arr[j] = R_cat[RR--];
        }
        for(int j=i-1;j>=0;j--){
            if(!W[j]) arr[j] = R_cat[RR--];
        }


        int ls = 0, rs = 0;
        int mmx = 0;
        for(int j=0;j<n;j++){
            if(W[j] && mmx < arr[j]){
                ls++;
            }
            mmx = max(mmx, arr[j]);
        }
        mmx = 0;
        for(int j=n-1;j>=0;j--){
            if(!W[j] && mmx < arr[j]){
                rs++;
            }
            mmx = max(mmx, arr[j]);
        }
        res = max(res, ls + rs);
    }
    cout << res;
}