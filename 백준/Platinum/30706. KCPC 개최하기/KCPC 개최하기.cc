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

const ll MOD = 1e9+7;

int main(){
    fast_io
    int N, M, K;
    cin >> N >> M >> K;
    vector<pll> a(N), b(M), c(K);
    ll axs = 0, bxs = 0, cxs = 0;
    ll ays = 0, bys = 0, cys = 0;
    for(int i=0;i<N;i++)
        cin >> a[i].xx >> a[i].yy, axs = (axs + a[i].xx) % MOD, ays = (ays + a[i].yy) % MOD;
    for(int i=0;i<M;i++)
        cin >> b[i].xx >> b[i].yy, bxs = (bxs + b[i].xx) % MOD, bys = (bys + b[i].yy) % MOD;
    for(int i=0;i<K;i++)
        cin >> c[i].xx >> c[i].yy, cxs = (cxs + c[i].xx) % MOD, cys = (cys + c[i].yy) % MOD;
    ll res = 0;
    vector<pll> a2(N), b2(M), c2(K);
    for(int i=0;i<N;i++){
        a2[i].xx = a[i].xx * a[i].xx;
        a2[i].yy = a[i].yy * a[i].yy;
    }
    for(int i=0;i<M;i++){
        b2[i].xx = b[i].xx * b[i].xx;
        b2[i].yy = b[i].yy * b[i].yy;
    }
    for(int i=0;i<K;i++){
        c2[i].xx = c[i].xx * c[i].xx;
        c2[i].yy = c[i].yy * c[i].yy;
    }
    ll S1 = 0, S2 = 0, S3 = 0;
    for(int i=0;i<N;i++){
        S1 = ((S1 + a2[i].xx) % MOD + a2[i].yy) % MOD;
    }
    S1 = S1 * 2 % MOD * M % MOD * K % MOD;
    for(int i=0;i<M;i++){
        S2 = ((S2 + b2[i].xx) % MOD + b2[i].yy) % MOD;
    }
    S2 = S2 * 2 % MOD * N % MOD * K % MOD;
    for(int i=0;i<K;i++){
        S3 = ((S3 + c2[i].xx) % MOD + c2[i].yy) % MOD;
    }
    S3 = S3 * 2 % MOD * N % MOD * M % MOD;
    res = (((res + S1) % MOD + S2) % MOD + S3) % MOD;
    res = (res - (axs * bxs % MOD * 2 % MOD * K % MOD) + MOD) % MOD;
    res = (res - (ays * bys % MOD * 2 % MOD * K % MOD) + MOD) % MOD;
    res = (res - (bxs * cxs % MOD * 2 % MOD * N % MOD) + MOD) % MOD;
    res = (res - (bys * cys % MOD * 2 % MOD * N % MOD) + MOD) % MOD;
    res = (res - (cxs * axs % MOD * 2 % MOD * M % MOD) + MOD) % MOD;
    res = (res - (cys * ays % MOD * 2 % MOD * M % MOD) + MOD) % MOD;

    res = (res + (axs * bys % MOD * K % MOD)) % MOD;
    res = (res - (ays * bxs % MOD * K % MOD) + MOD) % MOD;
    res = (res + (bxs * cys % MOD * N % MOD)) % MOD;
    res = (res - (bys * cxs % MOD * N % MOD) + MOD) % MOD;
    res = (res + (cxs * ays % MOD * M % MOD)) % MOD;
    res = (res - (cys * axs % MOD * M % MOD) + MOD) % MOD;

    cout << res;
}