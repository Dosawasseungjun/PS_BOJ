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

struct sfxarr{
    // counting sort를 이용하여 
	vector<int> getSA(const string& str) {
        int n = (int)str.size(), c = 0;
        vector<int> tmp(n), G(n), posG(n),  Gpos(n), ret(n);
        for (int i = 0; i < n; i++) ret[i] = i;
        sort(ret.begin(), ret.end(), [&](int a, int b) { return str[a] < str[b]; });
        for (int i = 0; i < n; i++) {
            G[i] = c;
            if (i + 1 == n || str[ret[i]] != str[ret[i + 1]]) c++;
        }
        for (int h = 1; h < n && c < n; h <<= 1) {
            for (int i = 0; i < n; i++) posG[ret[i]] = G[i];
            for (int i = n - 1; i >= 0; i--) Gpos[G[i]] = i;
            for (int i = 0; i < n; i++)
                if (ret[i] >= n - h) tmp[Gpos[G[i]]++] = ret[i];
            for (int i = 0; i < n; i++)
                if (ret[i] >= h) tmp[Gpos[posG[ret[i] - h]]++] = ret[i] - h;
            c = 0;
            for (int i = 0; i + 1 < n; i++) {
                int a = (G[i] != G[i + 1]) || (tmp[i] >= n - h)
                        || (posG[tmp[i + 1] + h] != posG[tmp[i] + h]);
                G[i] = c;
                c += a;
                }
                G[n - 1] = c++;
                tmp.swap(ret);
        }
        return ret;
}
    vector<int> lcp(const string& in, const vector<int>& sa) {
        int n = (int)in.size();
        if (n == 0) return vector<int>();
        vector<int> rank(n), height(n - 1);
        for (int i = 0; i < n; i++) rank[sa[i]] = i;
        for (int i = 0, h = 0; i < n; i++) {
            if (rank[i] == 0) continue;
            int j = sa[rank[i] - 1];
            while (i + h < n && j + h < n && in[i + h] == in[j + h]) h++;
            height[rank[i] - 1] = h;
            if (h > 0) h--;
        }
        return height;
    }
}sfx;

vector<int> Z_algorithm(const string &S){
    int n = S.size();
    vector<int> Z(n, 0);
    int L = 0, R = 0;    // 현재 윈도우 [L,R]

    for(int i = 1; i < n; i++){
        if(i > R){
            // 1) 윈도우 밖: 직접 비교
            int len = 0;
            while(i + len < n && S[len] == S[i + len]) len++;
            Z[i] = len;
            if(len > 0){
                L = i;
                R = i + len - 1;
            }
        } else {
            // 2) 윈도우 안: 기존 Z값 재활용
            int k = i - L;  // 윈도우 시작 대비 오프셋
            Z[i] = min(R - i + 1, Z[k]);
            // 필요하면 연장
            while(i + Z[i] < n && S[Z[i]] == S[i + Z[i]]){
                Z[i]++;
            }
            if(i + Z[i] - 1 > R){
                L = i;
                R = i + Z[i] - 1;
            }
        }
    }
    return Z;
}


int main(){
    fast_io
    string s; cin >> s;
    vector<int> SA = sfx.getSA(s);
    vector<int> LCP = sfx.lcp(s, SA);
    vector<int> Z = Z_algorithm(s);
    
    int n = s.length();
    Z[0] = n;
    int idx = -1;
    for(int i=0;i<n;i++) if(SA[i] == 0) idx = i;
    vector<int> cand;
    cand.push_back(n);
    int x = (idx-1 >=0 ? LCP[idx-1] : n);
    while(idx-1 >= 0 && x){
        x = min(x, LCP[idx-1]);
        int sz = n-SA[idx-1];
        if(sz == x) cand.push_back(x);
        idx--;
    }
    sort(cand.begin(), cand.end());
    vector<int> ans(n+1);
    for(int i=0;i<n;i++){
        int idx = upper_bound(cand.begin(), cand.end(), Z[i]) - cand.begin() - 1;
        if(idx >= 0) ans[cand[idx]]++;
    }
    int res = 0;
    int S = 0;
    for(int i=n;i>=1;i--){
        if(ans[i]){
            res += 1;
            S += ans[i];
            ans[i] = S;
        }
    }
    cout << res << '\n';
    for(int i=1;i<=n;i++){
        if(ans[i]){
            cout << i << ' ' << ans[i] << '\n';
        }
    }
}