#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    char c[3]={'Z', 'N', 'A'};
    
    if(n==1) cout<<"NAZ\nAZN\nZNA\n";
    else {
        for(int i=0; i<3; i++) for(int j=0; j<n; j++){
            for(int k=0; k<3; k++) {
                for(int l=0; l<n; l++) cout<<c[(i+k)%3];
            }
            cout<<'\n';
        }
    }
}