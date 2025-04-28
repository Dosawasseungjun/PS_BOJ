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


int main(){
    fast_io
    int n; cin >> n;
    string a, b; cin >> a >> b;
    bool is_minus = (a[0] == '~') ^ (b[0] == '~');
    if(a[0] == '~') a = a.substr(1, a.length()-1);
    if(b[0] == '~') b = b.substr(1, b.length()-1);
    

    int asz = a.length();
    reverse(a.begin(), a.end());
    int bsz = b.length();
    reverse(b.begin(), b.end());
    vector<int> c(asz + bsz);
    for(int i=0;i<asz;i++){
        for(int j=0;j<bsz;j++){
            c[i + j] += (a[i]-'!') * (b[j]-'!');
        }
    }
    int N = abs(n);
    string res = "";
    int i = 0;
    for(;i<asz+bsz-1;i++){
        int rem = c[i] % abs(n);
        if(rem < 0) rem += abs(n);
        int qu = (c[i] - rem) / n;
        c[i] = rem;
        c[i+1] += qu;
        res += c[i] + '!';
    }
    while(c.back()){
        int rem = c.back() % abs(n);
        if(rem < 0) rem += abs(n);
        int qu = (c.back() - rem) / n;

        c.back() = rem;
        res += c.back() + '!';
        c.push_back(qu);
    }
    while(res.back() == '!') res.pop_back();
    reverse(res.begin(), res.end());
    if(res == "") is_minus = false, res = "!";
    if(is_minus) res = "~" + res;
    cout << res;
}