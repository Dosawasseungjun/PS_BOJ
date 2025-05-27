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

// O(N^2) 풀이
const int MAX = 2e3+1;
const int MOD = 1e9+7;

int comb[MAX][MAX];

int binom(int n, int k){
    if(n == k || k == 0) return 1;
    int &ret = comb[n][k];
    if(ret) return ret;
    return (ret = (binom(n-1, k) + binom(n-1, k-1)) % MOD);
}

int main(){
    fast_io
    int n; cin >> n;
    string s; cin >> s;
    int res = 0;
    for(int i=0;i<n;i++){
        if(s[i] == '<') continue;
        int l = 1;
        int r = 0;
        bool flag = true;
        for(int j=i+1;j<n;j++){
            if(flag && s[j] == '>') l++;
            else if(flag && s[j] == '<'){
                r++;
                flag = false;
            }else if(!flag && s[j] == '<') r++;
            else break;
        }
        if(l > r) continue;
        int remove_l = i;
        int remove_r = n - (i + 2 * l);
        res += binom(remove_l + remove_r, remove_l);
        res %= MOD;
    }
    cout << res;
}