#include <bits/stdc++.h>
#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false);
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;
#define xx first
#define yy second

const int MAX = 1e5+1;
int n;
ll a[MAX], b[MAX];
ll dp[MAX]; //i번째 나무를 자를 때 최소 비용 dp[i] = a[i]*b[j] + dp[j]  //j는 i보다 큼 b[j]가 기울기 dp[j]가 y절편
vector<pll> s;

//a, b 직선의 교점의 x좌표 -> 커져야지 넣는다.
double cmp(pll a, pll b){
    return 1.0*(a.yy-b.yy)/(b.xx-a.xx);
}

int main() {
    fast_io
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];
    s.push_back({b[1], dp[1]});   //초기화
    
    int pos = 0;
    for(int i=2;i<=n;i++){
        while(pos<s.size()-1&&cmp(s[pos], s[pos+1])<a[i]) pos++;
        dp[i] = a[i]*s[pos].xx+s[pos].yy;
        pll A = {b[i], dp[i]};
        while(s.size()-1){
            pll B = s.back();
            s.pop_back();
            pll C = s.back();
            
            if(cmp(C, B)<=cmp(B, A)){
                s.push_back(B);
                break;
            }
        }
        s.push_back(A);
    }
    cout << dp[n];
}
