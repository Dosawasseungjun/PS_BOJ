#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

string str1, str2;

int dp[1001][1001];

int comparestr(int idx1, int idx2){
    if(idx1 ==str1.size()||idx2==str2.size()) return 0;
    int &ret = dp[idx1][idx2];
    
    if(ret !=-1) return ret;    
    ret = 0;        //리턴값이 0일 수 있으니깐 dp초기화를 -1로 햇어야함..
    if(str1[idx1]==str2[idx2]){
        ret = max(ret, comparestr(idx1+1, idx2+1)+1);
    }else{
        ret = max(ret, comparestr(idx1, idx2+1));
        ret = max(ret, comparestr(idx1+1, idx2));
    }
    
    return ret;
}


int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin >> str1;
    cin >> str2;
    
    memset(dp, -1, sizeof(dp));
    
    cout << comparestr(0, 0);
}
