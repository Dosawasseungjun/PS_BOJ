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

int get_idx(char x){
    int ret =0;
    if(x >= 'A' && x <= 'Z')  ret = x - 'A';
    if(x >= 'a' && x <= 'z') ret = x- 'a' + 26;
    return ret;
}

bool is_val(vector<int> & a, vector<int> & b){
    for(int i=0;i<a.size();i++){
        if(a[i] != b[i]) return false;
    }
    return true;
}
int main(){
    fast_io
    int n, m;
    cin >> n >> m;
    string w, s;
    cin >> w >> s;
    vector<int> G(52, 0);
    for(char c : w) {
        G[get_idx(c)]++;
    }
    vector<int> C(52, 0);
    for(int i=0;i<w.size();i++){
        C[get_idx(s[i])]++;
    }
    int res = 0;
    if(is_val(G, C)) res++;
    for(int i=w.size();i<s.size();i++){
        C[get_idx(s[i-w.size()])]--;
        C[get_idx(s[i])]++;
        if(is_val(G, C)) res++;
    }
    cout << res;
}