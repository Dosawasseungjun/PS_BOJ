#include <iostream>
#include <algorithm>
#define fast_io cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
using namespace std;

int wei[100001];
int main(){
    fast_io;
    int n; cin >> n;
    for(int i=0;i<n;i++) cin >> wei[i];
    sort(wei, wei+n);
    int maxres = 0;
    for(int i=0;i<n;i++){
        maxres =max(maxres, wei[i]*(n-i));
    }
    cout << maxres;
}
