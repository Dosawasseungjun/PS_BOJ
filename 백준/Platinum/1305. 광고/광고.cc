#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int L;
vector<int> part;

vector<int> getPartialMatch(const string &N){
    int size = N.size();
    vector<int> pi(L, 0);
    
    int begin = 1, matched = 0;
    while (begin+matched<size) {
        if(N[begin+matched]==N[matched]){
            matched++;
            pi[begin+matched-1] = matched;
        }else{
            if(matched==0) begin++;
            else{
                begin += matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }
    
    return pi;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    
    cin >> L;
    string str;
    cin >> str;
    
    part = getPartialMatch(str);
    cout << part.size()-part.back();
}
