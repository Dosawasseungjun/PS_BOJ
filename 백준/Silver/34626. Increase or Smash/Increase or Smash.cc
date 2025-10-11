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

void solv(){
    int n; cin >> n;
    set<int> st;
    for(int i=0;i<n;i++){
        int x; cin >> x;
        st.insert(x);
    }
    cout << 2*st.size()-1 << '\n';
}

int main(){
    fast_io
    int tt; cin >> tt;
    while(tt--) solv();
}