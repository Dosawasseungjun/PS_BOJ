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


vector<int> Z_algorithm(const string &S){
    int n = S.size();
    vector<int> Z(n, 0);
    int L = 0, R = 0;    // 현재 윈도우 [L,R]

    for(int i = 1; i < n; i++){
        if(i > R){
            // 1) 윈도우 밖: 직접 비교
            int len = 0;
            while(i + len < n && S[len] == S[i + len]) len++;
            Z[i] = len;
            if(len > 0){
                L = i;
                R = i + len - 1;
            }
        } else {
            // 2) 윈도우 안: 기존 Z값 재활용
            int k = i - L;  // 윈도우 시작 대비 오프셋
            Z[i] = min(R - i + 1, Z[k]);
            // 필요하면 연장
            while(i + Z[i] < n && S[Z[i]] == S[i + Z[i]]){
                Z[i]++;
            }
            if(i + Z[i] - 1 > R){
                L = i;
                R = i + Z[i] - 1;
            }
        }
    }
    return Z;
}



int main(){
    fast_io
    string s; cin >> s;
    reverse(s.begin(), s.end());
    vector<int> Z = Z_algorithm(s);
    int n = s.length();
    Z[0] = n;
    int M; cin >> M;
    while(M--){
        int x; cin >> x;
        int k = n-x;
        cout << Z[k] << '\n';
    }
}