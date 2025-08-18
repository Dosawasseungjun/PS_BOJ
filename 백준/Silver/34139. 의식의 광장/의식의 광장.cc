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
    int H, N; cin >> H >> N;
    vector<tiii> A(N);
    for(int i=0;i<N;i++){
        int r, c;
        cin >> r >> c;
        A[i] = {c, r, i};
    }
    sort(A.begin(), A.end());
    int j = 1;
    vector<int> ans(N);
    for(auto [c, r, i] : A){
        ans[i] = j++;
    }
    cout << "YES\n";
    for(int a : ans){
        cout << a << ' ';
    }
}