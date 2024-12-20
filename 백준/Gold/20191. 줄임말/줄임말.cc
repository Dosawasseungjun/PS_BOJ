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
    string s; cin >> s;
    string t; cin >> t;
    int n = s.length(), m = t.length();
    // ps[j][i] : t에서 i-1이후에 j번째 알파벳이 언제 처음 등장하는가
    vector ps(26, vector<int>(m+1));
    for(int j=0;j<26;j++){
        int k = -1;
        for(int i=m;i>=1;i--){
            if (t[i-1] == char('a' + j)) k = i;
            ps[j][i] = k;
        }
    }
    bool ok = true;
    int now = 0, res = 1;
    for(int i=0;i<n;i++){
        if(now+1 <= m && ps[s[i]-'a'][now+1] != -1){
            now = ps[s[i]-'a'][now+1];
        }else{
            if (ps[s[i] - 'a'][1] != -1){
                res += 1;
                now = ps[s[i] - 'a'][1];
            }else{
                ok = false;
                break;
            }
        }
    }

    if(ok){
        cout << res << '\n';
    }else{
        cout << "-1";
    }
    
}