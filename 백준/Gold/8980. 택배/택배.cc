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

class Node{
public:
    int st, ed, n;
    Node(){}
    Node(int a,int b,int c) : st(a), ed(b), n(c) {}

    bool operator<(const Node &n1) const{
        if(ed != n1.ed) return ed < n1.ed;
        return st < n1.st;
    }
};
int main(){
    fast_io
    int N, C; cin >> N >> C;
    int M; cin >> M;
    vector<Node> A(M);
    for(int i=0;i<M;i++){
        int s, e, n; cin >> s >> e >> n;
        A[i] = Node(s, e, n);
    }
    sort(A.begin(), A.end());
    vector<int> P(N+1);
    int res = 0;
    int nc = 0, idx = 0;
    for(int i=0;i<M;i++){
        int mx = 0;
        for(int j=A[i].st;j<A[i].ed;j++){
            mx = max(mx, P[j]);
        }
        int k = min(A[i].n, C - mx);
        for(int j=A[i].st;j<A[i].ed;j++){
            P[j] += k;
        }
        res += k;
    }
    cout << res;
}