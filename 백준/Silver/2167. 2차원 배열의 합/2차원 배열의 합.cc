#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#include <cassert>
#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false);
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m;
int a[301][301], ps[301][301];

int main(){
    fast_io
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a[i][j];
            ps[i][j] = ps[i-1][j]+ps[i][j-1]-ps[i-1][j-1]+a[i][j];
        }
    }
    int k; cin >> k;
    for(int i=0;i<k;i++){
        int a, b, p, q;
        cin >> a >> b >> p >> q;
        cout << ps[p][q]-ps[p][b-1]-ps[a-1][q]+ps[a-1][b-1] << '\n';
    }
}
