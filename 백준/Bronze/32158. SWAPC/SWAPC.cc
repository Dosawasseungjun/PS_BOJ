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
    string s; cin >> s;
    vector<int> P, C;
    for(int i = 0;i <n;i++) if(s[i] == 'P') P.push_back(i);
    for(int i = 0;i <n;i++) if(s[i] == 'C') C.push_back(i);
    for(int i=0;i<min(P.size(), C.size());i++) swap(s[P[i]], s[C[i]]);
    cout << s;
}