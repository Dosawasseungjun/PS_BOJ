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

char G[11][11];
int a[11], ps[11], n;
bool ed = false;

void sol(int cnt){
    if(cnt == n+1){

        ed = true;
        return ;
    }

    if(ed) return ;
    for(int i = -10;i<=10;i++){
        bool ok = true;
        a[cnt] = i;
        ps[cnt] = ps[cnt-1] + i;
        for(int j=1;j<=cnt;j++){
            if(G[j][cnt] == '-'){
                if(ps[cnt] - ps[j-1] >= 0) ok = false;
            }else if(G[j][cnt] == '+'){
                if(ps[cnt] - ps[j-1] <= 0) ok = false;
            }else{
                if(ps[cnt] - ps[j-1] != 0) ok = false;
            }
        }
        if(ok){
            sol(cnt + 1);
        }
        if(ed) break;
    }
}

int main(){
    fast_io
    // fill(G[0], G[11], 'A');
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            cin >> G[i][j];
        }
    }
    sol(1);
    for(int i=1;i<=n;i++) cout << a[i] << ' ';
}