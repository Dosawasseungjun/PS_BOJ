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
    while(1){
        int B, E; cin >> B >> E;
        if(B == -1 && E == -1) break;
        string txt;
        std::getline(cin, txt);
        txt = txt.substr(1, txt.length()-1);
        // cout << B << ' ' << E << ' ' << txt << '\n';
        // cout << txt.length() << '\n';

        stack<pair<pii, string>> tags; // (0-문자열, 1-태그 ,idx)
        string tmp = "";
        for(int i=0;i<txt.length();i++){
            if(txt[i] == '<'){
                if(!tmp.empty()) tags.push({{0, i-1}, tmp});
                tmp = "";

                string tagname = ((txt[i + 1] == '/') ? "</" : "<") ;
                int idx = i + 1 + ((txt[i+1] == '/') ? 1 : 0);
                while(txt[idx] != '>'){
                    tagname += txt[idx];
                    idx++;
                }
                tagname += ">";
                
                if(txt[i+1] == '/'){ // 닫는 태그
                    vector<string> rs;
                    while(!tags.empty() && tags.top().xx.xx != 1) {
                        rs.push_back(tags.top().yy);
                        tags.pop();
                    }
                    reverse(rs.begin(), rs.end());
                    string nxt = "";
                    for(string str : rs) nxt += str;
                    nxt = tags.top().yy + nxt + tagname;
                    int open_idx = tags.top().xx.yy;
                    tags.pop();
                    if(open_idx < E && idx >= B) tags.push({{0, i}, nxt});
                }else{ //여는 태그
                    tags.push({{1, i}, tagname});
                }
                i = idx;
            }else if(i >= B && i < E){
                tmp += txt[i];
            }
        }
        if(!tmp.empty()) tags.push({{0, E}, tmp});
        vector<string> res;
        while(!tags.empty()){
            res.push_back(tags.top().yy);
            tags.pop();
        }
        reverse(res.begin(), res.end());
        for(string str : res) cout << str;
        cout << '\n';
    }
    
}