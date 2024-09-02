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
    int N;
    cin >> N;
    if(N == 2){
        cout << "1\n2 1";
    }else if(N==3){
        cout << "2\n1 2\n";
        cout << "1 3\n";
    }
    else if(N & 1){
        int oc = N / 2;
        cout << ((oc & 1) ? N - 1 : N) << '\n';
        for(int i=N-1;i>1;i-=2){
            cout << i-1 << ' ' << i << '\n';
        }
        
        if(oc & 1){
            for(int i=0;i<oc/2;i++) cout << "1 1\n";
            for(int i=0;i<oc/2;i++) cout << "0 1\n";
        }else{
            for(int i=0;i<oc/2;i++) cout << "1 1\n";
            for(int i=0;i<oc/2-1;i++) cout << "0 0\n";
        }
        cout << (oc & 1) << ' ' << N << '\n';
    }else{
        int oc = N / 2;
        cout << ((oc & 1) ? N - 1 : N) << '\n';
        for(int i=N-1;i>1;i-=2){
            cout << i-1 << ' ' << i << '\n';
        }
        
        if(oc & 1){
            for(int i=0;i<oc/2;i++) cout << "1 1\n";
            for(int i=0;i<oc/2;i++) cout << "0 1\n";
        }else{
            for(int i=0;i<oc/2;i++) cout << "1 1\n";
            for(int i=0;i<oc/2-1;i++) cout << "0 0\n";
        }
        cout << (oc & 1) << ' ' << N << '\n';
    }
}