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

const int INF = 1e9+1;
map<char, int> M;
vector<int> A(13);
int dp[1 << 13], P[1 << 13];
vector<int> ans;

void reconstruct(int x){
    if(P[x] == -1){
        ans.push_back(x);
        return;
    }
    reconstruct(P[x]);
    reconstruct(x & (~P[x]));
}

bool can(vector<int> &k){
    bool straight = k.size() >= 5 ? true : false;
    sort(k.begin(), k.end());
    for(int i=1;i<k.size();i++){
        if(k[i]!=k[i-1]+1) straight = false;
    }
    if(straight) return true; // straight
    map<int, int> mp;
    for(int K : k) mp[K]++;
    if(mp.size() == 2){ // full house
        if(mp.begin() -> yy == 2 && (--mp.end()) ->yy == 3) return true;
        if(mp.begin() -> yy == 3 && (--mp.end()) ->yy == 2) return true;
    }else if(mp.size()==1){
        return true; // one, pair, triple, four
    }
    return false;
}

void solv(){
    vector<string> C(13);
    for(int i=0;i<13;i++) {
        cin >> C[i];
        if(C[i][0]>='1' && C[i][0] <= '9') A[i] = C[i][0] - '0';
        else A[i] = M[C[i][0]];
    }
    fill(dp, dp + (1 << 13), INF);
    fill(P, P + (1<<13), -1);
    vector<int> SET;
    for(int i=0;i<(1 << 13);i++){
        vector<int> k;
        for(int j=0;j<13;j++){
            if(i & (1 << j)) k.push_back(A[j]);
        }
        if(can(k)) SET.push_back(i), dp[i] = 1;
    }

    for(int i=0;i<(1<<13);i++){
        for(int j : SET){
            if((i & j) == j && dp[i] > dp[i & (~j)] + dp[j]){
                dp[i] = dp[i & (~j)] + dp[j];
                P[i] = j;
            }
        }
    }

    cout << dp[(1 << 13) -1] << '\n';
    reconstruct((1<<13) -1);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<13;j++){
            if(ans[i] & (1 << j)) cout << C[j] << ' ';
        }
        cout << '\n';
    }
}

int main(){
    fast_io
    M['T'] = 10;
    M['J'] = 11;
    M['Q'] = 12;
    M['K'] = 13;
    M['A'] = 14;
    int tt; cin >> tt;
    while(tt--) solv(), ans.clear();

}