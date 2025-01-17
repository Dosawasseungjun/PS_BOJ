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

vector<int> R;
bool ok;
void recur(int cnt, int i, int j){
    if(cnt == 15){
        int sum = 0;
        for(int i=0;i<18;i++) sum += R[i];
        if(sum) return;
        ok = true;
        return ;
    }
    // i가 이기고 j가 지는 경우
    if (R[i * 3] && R[j * 3 + 2]){
        R[i * 3]--;
        R[j * 3 + 2]--;
        int ni = i, nj = j+1;
        if(nj == 6){
            ni++;
            nj = ni+1;
        }
        recur(cnt + 1, ni, nj);
        R[i * 3]++;
        R[j * 3 + 2]++;
    }
    // 비김
    if (R[i * 3 + 1] && R[j * 3 + 1]){
        R[i * 3 + 1]--;
        R[j * 3 + 1]--;
        int ni = i, nj = j+1;
        if(nj == 6){
            ni++;
            nj = ni+1;
        }
        recur(cnt + 1, ni, nj);
        R[i * 3 + 1]++;
        R[j * 3 + 1]++;
    }
    // i가 지고 j가 이김
    if (R[i * 3 + 2] && R[j * 3]){
        R[i * 3 + 2]--;
        R[j * 3]--;
        int ni = i, nj = j+1;
        if(nj == 6){
            ni++;
            nj = ni+1;
        }
        recur(cnt + 1, ni, nj);
        R[i * 3 + 2]++;
        R[j * 3]++;
    }
}
int main(){
    fast_io
    for(int i=0;i<4;i++){
        R = vector<int>(18);
        ok = false;
        for(int j=0;j<18;j++) cin >> R[j];
        recur(0, 0, 1);
        if(ok) cout << "1 ";
        else cout << "0 ";
    }
}