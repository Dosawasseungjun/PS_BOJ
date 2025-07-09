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
    if(n == 1){
        cout << -1;
        return 0;
    }
    vector<int> p = {13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    string s[11];
    for(int pp : p){
        s[pp % 11] = to_string(pp);
    }
    int d = (n-1)%11;
    string res = "";
    for(int i=1;i<n;i++){
        res += s[1];
    }
    if(d == 0){
        res.pop_back();
        res.pop_back();
        res += s[2];
        res += s[10];
    }else{
        int k = 11 - d;
        res += s[k];
    }
    cout << res;
}