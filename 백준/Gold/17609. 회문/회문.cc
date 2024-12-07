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

void solv(){
    string s; cin >> s;
    int n = s.length();
    int l = 0, r = n - 1;
    bool ispal = true;
    for(int i=0;i<n/2;i++){
        if(s[i] != s[n-1-i]){
            ispal = false;
            l = i;
            r = n-1-i;
            break;
        }
    }

    if(ispal){
        cout << "0\n";
        return;
    }
    bool sim1 = true, sim2 = true;
    int c1 =0, c2 = 0;
    for(int i=0;i<n/2;i++){
        if(i == l) c1 = 1;
        if(n-1-i == r) c2 = 1;
        if(s[i+c1] != s[n-1-i]) sim1 = false;
        if(s[i] != s[n-1-i-c2]) sim2 = false;
    }
    if(sim1 || sim2){
        cout << "1\n";
    }else{
        cout << "2\n";
    }
}

int main(){
    fast_io
    int tt; cin >> tt;
    while(tt--) solv();
}