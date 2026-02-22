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
    if(s[s.length()-1] == '5' || s[s.length()-1] == '0'){
        ll N = stoll(s.substr(0, s.length()-2));
        ll res = 0;
        if(s[s.length()-1] == '5'){
            N -= 4;
            res += 1;
        }

        ll Y = 900;
        ll a = N / Y;
        ll b = N % Y;
        vector<int> D(Y * 2 +1, -1);
        D[Y] = 0;
        queue<int> q; q.push(Y);
        while(!q.empty()){
            int now = q.front();
            q.pop();

            if(now + 9 <= 2 * Y && D[now + 9] == -1){
                D[now + 9] = D[now] + 1;
                q.push(now + 9);
            }
            if(now + 7 <= 2 * Y && D[now + 7] == -1){
                D[now + 7] = D[now] + 1;
                q.push(now + 7);
            }
            if(now - 2 >= 0 && D[now - 2] == -1){
                D[now-2] = D[now] + 1;
                q.push(now - 2);
            }
        }
        res += a * 100 + D[b + Y];
        cout << res << '\n';
    }else{
        cout << -1;
    }
}