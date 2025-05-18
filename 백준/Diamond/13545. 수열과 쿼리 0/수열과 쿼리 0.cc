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

const int MAX = 1e5+1;

template<int SZ> struct mos{
    int n, A[SZ],ps[SZ], ans[SZ], C[SZ], ret = 0;
    deque<int> DQ[2*SZ];
    vector<pair<pii,int>> Q;
    inline void add(int k, int op){//현 구간에 k를 하나 추가해준다.
        deque<int> &dq = DQ[ps[k]+SZ];
        int now = 0;
        if(!dq.empty()){
            now = dq.back() - dq.front();
            --C[now];
        }
        if(op) dq.push_back(k);
        else dq.push_front(k);
        now = dq.back() - dq.front();
        if(++C[now]) ret = max(ret, now);
    }
    inline void pop(int k, int op){//현 구간에서 k를 하나 제거해준다.
	    deque<int> &dq = DQ[ps[k]+SZ];
        int now = dq.back() - dq.front();
        --C[now];
        if(op) dq.pop_back();
        else dq.pop_front();

        if(!dq.empty()){
            now = dq.back() - dq.front();
            if(++C[now]) ret = max(ret, now);
        }
    }
    void MOquery(){
	    const int sqrtN = sqrt(n);
	    sort(Q.begin(), Q.end(), [sqrtN](auto &a, auto &b){
		    int Ln = a.first.first/sqrtN, Rn = b.first.first/sqrtN;
		    if(Ln != Rn) return Ln < Rn;
		    //부등호를 뒤집으면 더 빨리질수도 있음.
		    if(Ln&1) return a.first.second > b.first.second;
        	else return a.first.second < b.first.second;
	    });

	    int L = 0, R = 0; add(0, 1);
	    for(auto &P : Q){
		    int nL = P.first.first, nR = P.first.second;
		    if(nL < L) for(int i=L-1; i>=nL; --i) add(i, 0);
		    if(R < nR) for(int i=R+1; i<=nR; ++i) add(i, 1);
		    if(L < nL) for(int i=L; i<nL; ++i) pop(i, 0);
		    if(nR < R) for(int i=R; i>nR; --i) pop(i, 1);
            while(!C[ret]) ret--;
		    L = nL; R = nR; ans[P.second] = ret;
	    }
    }
};

mos<MAX> ms;

int main(){
    fast_io
    cin >> ms.n;
    for(int i=1;i<=ms.n;i++){
        cin >> ms.A[i];
        ms.ps[i] = ms.ps[i-1] + ms.A[i];
    }
    int q; cin >> q;
    
    for(int i=0;i<q;i++){
        int l, r; cin >> l >> r;
        ms.Q.push_back({{l-1, r}, i});
    }

    ms.MOquery();

    for(int i=0;i<q;i++) cout << ms.ans[i] << '\n';
}