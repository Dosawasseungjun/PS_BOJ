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
    string s; cin >> s;
    string t; t = "";
    bool flag = false;    
    for(int i=0;i<n;i++){
        if(s[i] == '1'){
            flag = true;
        }
        if(flag) t.push_back(s[i]);
    }
    int m = t.length();
    if(!m){
        cout << "0\n";
        return ;
    }
    int fz_idx = -1;
    int one_cnt = 0;
    int z_cnt =0;
    bool zf = false;
    for(int i=0;i<m;i++){
        if(!zf&&t[i] == '1') one_cnt++;
        else if(t[i] == '1') break;
        else if(!zf){
            zf = true;
            fz_idx = i;
            z_cnt++;
        }else{
            z_cnt++;
        }
    }
    int st = max(0, one_cnt - z_cnt);
    if(fz_idx == -1) st = m-1;
    int ed = st + ((fz_idx == -1) ? 0 : (m -fz_idx-1));
    
    string s2 = t.substr(st,ed-st+1);
    if(z_cnt == 0 && s[0] == '0'){
        s2 = '0';
    }

    string res;
    while(!s2.empty()){
        res += (s2.back() == t.back()) ? '0' : '1';
        s2.pop_back();
        t.pop_back();
    }
    while(!t.empty()){
        res += t.back();
        t.pop_back();
    }
    while(res.size()>1&&res.back() == 0) res.pop_back();
    reverse(res.begin(), res.end());
    cout << res << '\n';
}

int main(){
    fast_io
    int tt; cin >> tt;
    while(tt--) solv();
}