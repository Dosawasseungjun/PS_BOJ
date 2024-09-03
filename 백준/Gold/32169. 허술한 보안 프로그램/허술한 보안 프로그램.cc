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

vector<int> ask(vector<int> &a){
    cout << "? ";
    for(int x : a) cout << x << ' ';
    cout << '\n';
    cout << flush;
    vector<int> ret(a.size());
    for(int i=0;i<a.size();i++) cin >> ret[i];
    return ret;
}

void answer(vector<int> &a){
    cout << "! ";
    for(int x : a) cout << x << ' ';
    cout << '\n';
    cout << flush;
}

int main(){
    fast_io
    int N; cin >> N;
    vector<int> p1, p2;
    int tn = N;
    while(p1.size() < N){
        int x = 1;
        while(x < tn) x <<= 1;
        x >>= 1;
        int d = 0;
        while(x+d < tn){
            if(x - 1 - d >= 0) p1.push_back(x - 1 - d);
            p1.push_back(x + d);
            d++;
        }
        tn = x - d;
    }
    

    vector<int> k1  = ask(p1);

    tn = N;
    while(p2.size() < N){
        int x = 1;
        while(x < tn) x <<= 1;
        x >>= 1;
        int d = 0;
        while(x+d < tn){
            p2.push_back(x + d);
            if(x - 1 - d >= 0) p2.push_back(x - 1 - d);
            d++;
        }
        tn = x - d;
    }

    vector<int> k2 = ask(p2);
    vector<int> res(N);
    for(int i=0;i<N;i++){
        res[i] = k1[i] & k2[i];
    }
    answer(res);
}