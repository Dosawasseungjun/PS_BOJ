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

string to_bi(int x){
    string ret = "";
    while(x){
        ret += (x & 1 ? '1' : '0');
        x >>= 1;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

int bi_to(string x){
    int ret = 0;
    int n = x.size();
    for(int i=0;i<n;i++){
        if(x[i] == '1') ret += 1 << (n - 1 - i);
    }
    return ret;
}

void solv(){
    int n, q; cin >> n >> q;
    vector<int> a(n+1), c(n+1), d(n+1);
    vector<string> b(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
        string bi = to_bi(a[i]);
        b[i] = bi;
        c[i] = bi.size()-1;
        string tmp = "11";
        for(int j=0;j<bi.size()-2;j++) tmp += '0';
        int idx = 1;
        while(idx < bi.size() && bi[idx] == '0') idx++;
        d[i] = idx;
    }
    vector<int> ps(n+1), sm(n+1), ls(n+1);
    for(int i=1;i<=n;i+=1){
        ps[i] = ps[i-1] + c[i];
        sm[i] = sm[i-1] + (c[i] == d[i]);
        ls[i] = ls[i-1] + (c[i] > d[i]);
    }

    while(q--){
        int l, r;
        cin >> l >> r;
        int res = ps[r]-ps[l-1] + max(0, (sm[r]-sm[l-1])/2) + (ls[r] - ls[l-1]);
        cout << res << '\n';
    }
}

int main(){
    fast_io
    int tt; cin >> tt;
    while(tt--) solv();
}