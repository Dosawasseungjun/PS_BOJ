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
    vector A = vector(n, vector<int>(n-1));
    vector B = vector(n-1, vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            cin >> A[i][j];
        }
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n;j++){
            cin >> B[i][j];
        }
    }
    bool ok = true;
    vector vstA = vector(n, vector<int>(n-1, 0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(i < n-1 && A[i][j] && !vstA[i][j]){
                if(A[i+1][j]){
                    vstA[i][j] = 1;
                    vstA[i+1][j] = 2;
                }else{
                    ok = false;
                }
            }else if(i == n-1 && A[i][j] && !vstA[i][j]){
                ok = false;
            }
        }
    }
    vector vstB = vector(n-1, vector<int>(n, 0));
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n;j++){
            if(j < n-1 && B[i][j] && !vstB[i][j]){
                if(B[i][j+1]){
                    vstB[i][j] = 1;
                    vstB[i][j+1] = 2;
                }else{
                    ok = false;
                }
            }else if(j == n-1 && B[i][j] && !vstB[i][j]) ok = false;
        }
    }
    // A를 기준으로 교차확인
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n;j++){
            if(vstA[i][j] == 1 && vstB[i][j] == 1){
                ok = false;
            }
        }
    }

    cout << (ok ? "YES" : "NO");

}