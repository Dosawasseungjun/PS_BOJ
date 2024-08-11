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
    char c; 
    vector<int> cnt(26, 0);
    while(cin >> c){
        cnt[c - 'a']++;
    }
    int mx =  *max_element(cnt.begin(), cnt.end());
    for(int i=0;i<26;i++){
        if(mx == cnt[i]) cout << (char)(i + 'a');
    }
}