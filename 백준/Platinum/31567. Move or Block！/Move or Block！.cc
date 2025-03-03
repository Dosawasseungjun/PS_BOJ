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

/*
벽에 박치기 하는 것 = 자살 행위
그냥 이동시키는 것 = 상대가 대칭적으로 따라하면 의미 없는 행위
따라서 이동하는건 걍 손해임
X.O.X의 상황 선공이 뭘해도 짐
X..O.X 라고 하자. 선공이 2번째에 막아버리면 이김
X..O..X 먼저 벽깔면 지니까 이동만 할것임...
*/

vector<string> P = {"mingyu", "yunsu", "draw"};
int main(){
    fast_io
    int n; cin >> n;
    string s; cin >> s;
    s = "X" + s + "X";
    int my_case = 0;
    // my_case == 0 -> 벽에 둘러쌓여있음
    // my_case == 1 -> 벽에 한칸 닿아 있음
    // my_case == 2 -> X.O.X
    // my_case == 3 -> X.O.. , ..O.X
    // my_case == 4 -> ..O..
    for(int i=1;i<=n;i++){
        if(s[i] == 'O'){
            if(s[i+1] == 'X' && s[i-1] == 'X') my_case = 0;
            else if(s[i+1] == 'X' || s[i-1] == 'X') my_case = 1;
            else{
                // X.O.X
                if(s[i+2] == 'X' && s[i-2] == 'X') my_case = 2;
                else if(s[i+2] == 'X' || s[i-2] == 'X') my_case = 3;
                else my_case = 4;
            }
        }
    }
    int cnt = 0;
    for(int i=1;i<=n;i++){
        if(s[i] == '.') cnt++;
    }
    
    switch (my_case) {
        case 0 : 
            cout << P[1];
            break;
        case 1 : 
            cout << P[0];
            break;
        case 2 :
            if(cnt & 1) {
                cout << P[0];
            }else {
                cout << P[1];
            }
            break;
        case 3 : 
            if(cnt & 1) {
                cout << P[0];
            }else {
                cout << P[2];
            }
            break;
        case 4 : 
            cout << P[2];
            break;
    }
}