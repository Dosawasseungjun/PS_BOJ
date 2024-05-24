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

int n;
string s;
int dp[200][200];

bool type1(int l, int r){
    int idx = l;
    if(s[idx++] != '1') return false;
    int zero_cnt = 0;
    while(idx <= r && s[idx] == '0') zero_cnt++, idx++;
    if(zero_cnt < 2) return false;
    zero_cnt = 0;
    int one_cnt = 0;
    while(idx <= r) {
        if (s[idx++] == '0') zero_cnt++;
        else one_cnt++;
    }
    if(zero_cnt || !one_cnt) return false;
    return true;
}

bool type2(int l, int r){
    int idx = l;
    int cnt = 0;
    while(idx <= r){
        if(cnt & 1 && s[idx] == '0') return false;
        if(!(cnt & 1) && s[idx] == '1') return false;
        cnt += 1;
        idx++;
    }
    return !(cnt & 1);
}

int memo(int l, int r){
    int &ret = dp[l][r];
    if(ret != -1) return ret;
    if(l == r) return 0;
    ret = (type1(l, r) || type2(l, r));
    for(int i=l;i<r;i++){
        ret |= memo(l, i) && memo(i+1, r);
    }
    return ret;
}

void solv(){
    cin >> s;
    n = s.length();
    memset(dp, -1, sizeof(dp));
    if(memo(0, n-1)) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    fast_io
    int tt; cin >> tt;
    while(tt--) solv();
}