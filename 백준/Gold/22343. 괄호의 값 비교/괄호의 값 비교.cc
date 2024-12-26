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

char f(vector<int> &a, vector<int> &b){
    int sz = a.size();
    for(int i=0;i<sz;i++){
        a[i+1] += a[i] / 2;
        a[i] %= 2;
        b[i+1] += b[i] / 2;
        b[i] %= 2;
    }
    while(!a.empty()){
        if(a.back() != b.back()){
            if(a.back() > b.back()) return '>';
            else return '<';
        }
        a.pop_back();
        b.pop_back();
    }
    return '=';
}

void solv(){
    string s, t;
    cin >> s >> t;
    int n = s.length(), m = t.length();
    const int MAX = 1500001;
    vector<int> ps1(n + 1), ps2(m + 1), coe1(MAX, 0), coe2(MAX, 0);
    for(int i=0;i<n;i++){
        ps1[i+1] = ps1[i] + (s[i] == '(' ? 1 : -1);
    }
    for(int i=0;i<m;i++){
        ps2[i+1] = ps2[i] + (t[i] == '(' ? 1 : -1);
    }
    for(int i=1;i<n;i++){
        if(s[i-1]=='(' && s[i] == ')'){
            coe1[ps1[i+1]]++;
        }
    }
    for(int i=1;i<m;i++){
        if(t[i-1]=='(' && t[i] == ')'){
            coe2[ps2[i+1]]++;
        }
    }

    cout << f(coe1, coe2) << '\n';
}

int main(){
    fast_io
    int tt; cin >> tt;
    while(tt--) solv();
}