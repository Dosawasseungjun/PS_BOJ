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

template<class T>
void zip_oneToN(vector<T> &ori, vector<T> &com ){
    const T minusINF = numeric_limits<T>().lowest();
    ori[0] = minusINF;
    int n = ori.size();
    sort(ori.begin(), ori.end());
    ori.erase(unique(ori.begin(), ori.end()), ori.end());
    for(int i=1;i<n;i++){
        com[i] = lower_bound(ori.begin(), ori.end(), com[i])-ori.begin();
    }
}

int main(){
    fast_io
    int n; cin >> n;
    vector<int> a(n+1), b;
    for(int i=1;i<=n;i++) cin >> a[i];
    b = a;
    zip_oneToN(b, a);
    int q; cin >> q;
    vector<pair<pii, int>> query;
    int ori_q = q;
    while(q--){
        int l, r;
        cin >> l >> r;
        query.push_back({{l, r}, ori_q - q});
    }

    const int sqrtN = sqrt(n);
    sort(query.begin(), query.end(), [sqrtN](auto &a, auto &b){
        int L = a.xx.xx / sqrtN, R = b.xx.xx / sqrtN;
        if(L != R) return L < R;
        if(L & 1) return a.xx.yy > b.xx.yy;
        else return a.xx.yy < b.xx.yy;
    });
    vector<int> cnt(1000001, 0);
    vector<int> ans(ori_q+1, 0);
    int L = 1, R = 1; 
    int res = 0;
    if (++cnt[a[1]] == 1) res++;
    for(auto &Q : query){
        int nl = Q.xx.xx, nr = Q.xx.yy;
        if(nl < L) for(int i=L-1;i>=nl;i--) if(++cnt[a[i]] == 1) res++;
        if(R < nr) for(int i=R+1;i<=nr;i++) if(++cnt[a[i]] == 1) res++;
        if(L < nl) for(int i=L;i<nl;i++) if(--cnt[a[i]] == 0) res--;
        if(nr < R) for(int i=R;i>nr;i--) if(--cnt[a[i]] == 0) res--;
        L = nl; R = nr;
        ans[Q.yy] = res;
    }

    for(int i=1;i<=ori_q;i++) cout << ans[i] << '\n';
}