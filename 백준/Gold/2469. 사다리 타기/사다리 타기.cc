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
    int k; cin >> k;
    int n; cin >> n;
    string S = "";
    for(int i=0;i<k;i++) S += char('A'+i);
    string F; cin >> F;
    vector<string> L(n);
    for(int i=0;i<n;i++) cin >> L[i];
    for(int i=0;i<n;i++){
        if(L[i][0] == '?') break;
        for(int j=0;j<L[i].size();j++){
            if(L[i][j] == '-'){
                swap(S[j], S[j+1]);
            }
        }
    }
    for(int i=n-1;i>=0;i--){
        if(L[i][0] == '?') break;
        for(int j=0;j<L[i].size();j++){
            if(L[i][j] == '-'){
                swap(F[j], F[j+1]);
            }
        }
    }
    string res;
    for(int i=0;i<k-1;i++){
        if(S[i] == F[i]) res += '*';
        else if(S[i] == F[i+1] && S[i+1] == F[i]){
            res += "-";
            swap(S[i], S[i+1]);
        }else{
            res = "x";
            break;
        }
    }
    if(res == "x"){
        for(int i=0;i<k-2;i++) res += 'x';
    }

    cout << res;
}