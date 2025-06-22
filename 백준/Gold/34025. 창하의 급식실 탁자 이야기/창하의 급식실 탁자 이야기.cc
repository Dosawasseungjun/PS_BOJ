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
    vector<int> a;
    int one = 0;
    for(int i=0;i<N;i++){
        int x; cin >> x;
        if(x == 1) one++;
        else a.push_back(x);
    }
    int flag = 0;
    ll res = 0;
    for(int x : a){
        while(flag && one){
            res += 1;
            one -= 1;
        }
        if(flag && (x & 1)){
            if(one){
                res += x / 2 + 1;
                flag = 1;
            }else{
                res += x / 2 + 2;
                flag = 0;
            }
        }else if(flag){
            res += x / 2 + 1;
            flag = 1;
        }else if(x & 1){
            res += x / 2 + 1;
            flag = 1;
        }else{
            res += x/ 2 + 1;
            flag = 0;
        }
    }
    if(one){
        res += one;
        flag = 1;
    }
    if(flag == 0) res -= 1;
    
    cout << res;
}