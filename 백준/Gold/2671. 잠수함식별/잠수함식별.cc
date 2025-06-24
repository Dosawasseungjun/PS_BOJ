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
    int md = 3; 
    int i = 0;
    bool ok = true;
    int prevz = 0;
    while(i < s.length()){
        if(md == 3){
            md = (s[i] == '1' ? 1 : 0);
            if(i+1 < s.length() && !md && s[i+1] == '1'){
                i += 2;
                md = 3;
                continue;
            }else i++;
        }

        if(md){
            int zc = prevz;
            while(i<s.length() && s[i] == '0') {i++; zc++;}
            if(zc < 2){
                ok = false;
                break;
            }
            int oc = 0;
            while(i < s.length()&& s[i] == '1') {i++; oc++;}
            if(oc < 1){
                ok = false;
                break;
            }
            if(i+1 < s.length()) {
                if(s[i+1] == '1') i += 2, md = 3;
                else{
                    if(oc > 1 && s[i-1] == '1' && s[i+1] == '0'){
                        prevz = 2;
                        i += 2;
                        md = 1;
                    }else{
                        ok = false;
                        break;
                    }
                }
            }else{
                if(i == s.length()){
                    break;
                }
                ok = false;
                break;
            }
        }else{
            ok = false;
            break;

        }
    }

    cout << (ok ? "SUBMARINE" : "NOISE");
}