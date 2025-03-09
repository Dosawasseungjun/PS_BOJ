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
    string s, t;
    cin >> s >> t;
    if(s == "null"){
        cout << "NullPointerException\n";
        cout << "NullPointerException\n";
    }else{
        if(s == t) cout << "true\n";
        else cout << "false\n";
        
        if(t == "null"){
            cout << "false\n";
        }else{
            for(char &c : s) c = tolower(c);
            for(char &c : t) c = tolower(c);
            
            if(s == t) cout << "true\n";
            else cout << "false\n";
        }
        
    }
}