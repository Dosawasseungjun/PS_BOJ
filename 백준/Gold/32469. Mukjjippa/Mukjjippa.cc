#include <bits/stdc++.h>
using namespace std;

#define mod 998244353LL

long long pow(long long n, long long p) {
    if(!p) return 1;
    else if(p%2) return pow(n, p-1) * n % mod;
    else {
        long long tmp = pow(n, p/2);
        return tmp*tmp%mod;
    }
}

long long inv(long long n) {
    return pow(n, mod-2);
}

long long n;
long long prob[200000][3]; // A wins, B wins, nobody wins

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>n;
    long long r[n], s[n], p[n];
    for(int i=0; i<n; i++) {
        cin>>r[i]>>s[i]>>p[i];
        long long rsp = (r[i]+s[i]+p[i])%mod;
        r[i] = r[i] * inv(rsp) % mod;
        s[i] = s[i] * inv(rsp) % mod;
        p[i] = p[i] * inv(rsp) % mod;
    }
    for(int i=0; i<n; i++) {
        long long tr, ts, tp;
        cin>>tr>>ts>>tp;
        long long rsp = (tr+ts+tp)%mod;
        tr = tr * inv(rsp) % mod;
        ts = ts * inv(rsp) % mod;
        tp = tp * inv(rsp) % mod;
        prob[i][0] = (r[i] * ts % mod + s[i] * tp % mod + p[i] * tr % mod) % mod;
        prob[i][1] = (r[i] * tp % mod + s[i] * tr % mod + p[i] * ts % mod) % mod;
        prob[i][2] = (r[i] * tr % mod + s[i] * ts % mod + p[i] * tp % mod) % mod;
    }
    long long no=1, Aa=0, Ba=0, Aw=0, Bw=0;
    for(int i=0; i<n; i++) {
        long long   nno = no * prob[i][2] % mod, 
                    nAa = (no + Aa + Ba) * prob[i][0] % mod,
                    nBa = (no + Aa + Ba) * prob[i][1] % mod,
                    nAw = (Aw + Aa*prob[i][2] % mod) % mod,
                    nBw = (Bw + Ba*prob[i][2] % mod) % mod;
        no=nno, Aa=nAa, Ba=nBa, Aw=nAw, Bw=nBw; 
    }
    cout<<Aw;
}