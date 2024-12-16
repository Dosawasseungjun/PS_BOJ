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

class Data{
public:
    int p, f, s, v, c;
    Data() : p(0), f(0), s(0), v(0), c(0) {}
    Data(int p, int f, int s, int v, int c){
        this->p = p;
        this->f = f;
        this->s = s;
        this->v = v;
        this->c = c;
    }
};

bool cmp(vector<int> a, vector<int> b){
    for(int i=0;i<min(a.size(), b.size());i++){
        if(a[i] != b[i]) return a[i] < b[i];
    }
    return a.size() < b.size();
}
int main(){
    fast_io
    int n; cin >> n;
    int mp, mf, ms, mv;
    cin >> mp >> mf >> ms >> mv;
    vector<Data> a(n);
    for(int i=0;i<n;i++){
        int p, f, s, v, c; cin >> p >> f >> s >> v >> c;
        a[i] = Data(p, f, s, v, c);
    }
    int res = 1e9;
    vector<int> ans;
    for(int i=0;i<(1<<n);i++){
        int ap=0,af=0,as=0,av=0,ac=0;
        vector<int> tmp;
        for(int j=0;j<n;j++){
            if(i & (1 << j)){
                ap += a[j].p;
                af += a[j].f;
                as += a[j].s;
                av += a[j].v;
                ac += a[j].c;
                tmp.push_back(j + 1);
            }
        }
        if(ap >= mp && af >= mf && as >= ms && av >= mv && res >= ac){
            if(res == ac){
                if(cmp(tmp, ans)) ans = tmp;
            }else{
                res = ac;
                ans = tmp;
            }
            
        }
    }
    if(res == 1e9) cout << "-1\n";
    else{
        cout << res << '\n';
        for(int x : ans) cout << x << ' ';
    }
    
}