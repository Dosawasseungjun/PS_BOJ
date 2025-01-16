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
    queue<Node> q;
    int res = 0;
    int nc = 0, idx = 0;
    for(int v=1;v<=N;v++){
        // 짐 내리기
        while(!q.empty() && q.front().ed <= v){
            res += q.front().n;
            nc -= q.front().n;
            q.pop();
        }
        // 짐 올리기
        for(int i=idx;i<M;i++){
            if(A[i].st < v) continue;
            if(nc < C){
                int k = min(C-nc, A[i].n);
                idx = i;
                A[i].n -= k;
                nc += k;
                q.push(Node(A[i].st, A[i].ed, k));
            }else break;
        }
    }
    cout << res;
}