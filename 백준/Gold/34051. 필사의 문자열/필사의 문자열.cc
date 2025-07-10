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
    string rsort_s = s;
    sort(rsort_s.begin(), rsort_s.end());
    reverse(rsort_s.begin(), rsort_s.end());

    function<string()> f = [&](){
        string ret = s;
        for(int i=0;i<n;i++){
            if(rsort_s[i] != s[i]){
                for(int j=i+1;j<n;j++){
                    if(rsort_s[i] == s[j]){
                        string t = s;
                        reverse(t.begin()+i, t.begin()+j+1);
                        if(ret < t) ret = t;
                    }
                }
                return ret;
            }
        }
        return ret;
    };

    string res = f();
    cout << res;
}