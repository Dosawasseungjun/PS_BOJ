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
    int N; cin >> N;
    vector<pair<string, int>> A(N);
    for(int i=0;i<N;i++){
        cin >> A[i].xx >> A[i].yy;
    }
    int M; cin >> M;
    vector<pair<string, int>> B(M);
    for(int i=0;i<M;i++){
        cin >> B[i].xx >> B[i].yy;
    }
    int Q; cin >> Q;
    string name = "";
    while(Q--){
        string a,b,  c;
        cin >> a >> b >> c;
        if(b == "-"){
            name = a;
            cout << "hai!\n";
            continue;
        }
        int d = -1;
        for(int i=0;i<M;i++){
            if(name == B[i].xx){
                d = B[i].yy;
                break;
            }
        }
        set<pair<int, string>> st;
        for(int i=0;i<N;i++){
            st.insert({abs(d - A[i].yy), A[i].xx});
        }
        auto fst = *st.begin();
        auto scd = *(++st.begin());

        cout << scd.yy << " yori mo " << fst.yy << '\n';
    }
}