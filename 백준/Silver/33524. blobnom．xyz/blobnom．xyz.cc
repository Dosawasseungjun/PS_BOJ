#include <bits/stdc++.h>
using namespace std;

int n, m;
int A[300001];
int B[300001];



int main() {
    cin>>n>>m;
    for(int i=0; i<n; i++) cin>>A[i];
    for(int i=0; i<m; i++) cin>>B[i];
    int cnt[1000001]={0,};
    for(int i=0; i<n; i++) {
        cnt[A[i]]++;
    }
    for(int i=1; i<1000001; i++) cnt[i]+=cnt[i-1];

    // for(int i=1; i<100; i++) cout<<cnt[i];

    int f[1001];
    for(int i=0; i<=1000; i++) f[i]=3*i*(i-1)+1;

    f[0]=0;

    // for(int i=0; i<=1000; i++) cout<<f[i]<<' ';

    for(int i=0; i<m; i++) cout<<(upper_bound(f, f+1001, cnt[B[i]])-f-1)<<' ';
}