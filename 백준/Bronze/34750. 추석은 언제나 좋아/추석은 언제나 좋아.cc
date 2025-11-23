#include <iostream>
using namespace std;

int main(){
    int n; cin >> n;
    int a = (n < 100000 ? n / 20 : 
            n < 500000 ? n / 10 : 
            n < 1000000 ? n * 3 / 20 : 
            n / 5);
    int b = n - a;
    cout << a << ' ' << b;
}