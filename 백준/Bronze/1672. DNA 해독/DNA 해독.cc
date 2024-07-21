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

map<pair<char, char>, char> mp;

int main(){
    fast_io
    int n; cin >> n;
    mp[{'A', 'A'}] = 'A'; mp[{'A', 'G'}] = 'C'; mp[{'A', 'C'}] = 'A'; mp[{'A', 'T'}] = 'G';
    mp[{'G', 'A'}] = 'C'; mp[{'G', 'G'}] = 'G'; mp[{'G', 'C'}] = 'T'; mp[{'G', 'T'}] = 'A';
    mp[{'C', 'A'}] = 'A'; mp[{'C', 'G'}] = 'T'; mp[{'C', 'C'}] = 'C'; mp[{'C', 'T'}] = 'G';
    mp[{'T', 'A'}] = 'G'; mp[{'T', 'G'}] = 'A'; mp[{'T', 'C'}] = 'G'; mp[{'T', 'T'}] = 'T';
    stack<char> stk;
    for(int i=0;i<n;i++){
        char x; cin >> x;
        stk.push(x);
    }
    while(stk.size() > 1){
        char a = stk.top(); stk.pop();
        char b = stk.top(); stk.pop();
        stk.push(mp[{a, b}]);
    }
    cout << stk.top();
}