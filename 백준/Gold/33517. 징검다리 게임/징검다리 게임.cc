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
    int n; cin  >> n;
    vector<int> A(n);
    for(auto &a : A) cin >> a;
    int k; cin >> k;
    vector<char> M(k);
    for(auto &m : M) cin >> m;
    vector<array<int, 2>> macro;
    array<int, 2> tmp = {0, 0};
    for(int i=0;i<k;i++){
        if(M[i] == 'J'){
            macro.push_back(tmp);
            tmp = {0, 0};
        }else if(M[i] == 'A'){
            tmp[0]++;
        }else if(M[i] == 'D'){
            if(tmp[0] && !tmp[1]) tmp[1] = 2;
            else if(!tmp[1]) tmp[1] = 1;
        }
    }
    vector<array<int, 2>> macro2;
    for(int i=0;i<k;i++){
        if(M[i] == 'J'){
            macro2.push_back(tmp);
            tmp = {0, 0};
        }else if(M[i] == 'A'){
            tmp[0]++;
        }else if(M[i] == 'D'){
            if(tmp[0] && !tmp[1]) tmp[1] = 2;
            else if(!tmp[1]) tmp[1] = 1;
        }
    }
    if(macro.size() == 0){
        cout << "NO";
        return 0;
    }
    bool die = false;
    int now = 0;
    for(auto [x, y] : macro){
        if(now == n-1 || die) break;
        if(A[now]) die = true;

        if(y == 1 && A[now+1] == -1) A[now+1] = 0;

        if(x){
            if(A[now + 1] == -1){
                die = true;
            }else{
                A[now + 1] -= min(A[now+1], x);
            }
        }

        if(y == 2 && A[now+1] == -1) A[now+1] = 0;

        now++;
    }
    int idx = 0;
    while(now < n-1){
        auto [x, y] = macro2[idx];
        idx = (idx + 1) % macro2.size();
        if(now == n-1 || die) break;
        if(A[now]) die = true;

        if(y == 1 && A[now+1] == -1) A[now+1] = 0;

        if(x){
            if(A[now + 1] == -1){
                die = true;
            }else{
                A[now + 1] -= min(A[now+1], x);
            }
        }

        if(y == 2 && A[now+1] == -1) A[now+1] = 0;

        now++;
    }
    
    cout << (die ? "NO" : "YES");
}