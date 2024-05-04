//2차원 배열 역추적..
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string Astr, Bstr;
int dp[1001][1001];

int main(){
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> Astr >> Bstr;
    
    for(int i=1;i<=Astr.size();i++){
        for(int j=1;j<=Bstr.size();j++){
            if(Astr[i-1]==Bstr[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    int i = (int)Astr.size();
    int j = (int)Bstr.size();
    vector<char> ans;
    
    while (i>0&&j>0) {
        if(dp[i][j]==dp[i-1][j]){
            i--;
        }else if(dp[i][j]==dp[i][j-1]){
            j--;
        }else{
            ans.push_back(Astr[i-1]);
            i--; j--;
        }
    }
    
    cout << ans.size() << '\n';
    reverse(ans.begin(), ans.end());
    for(int i=0;i<ans.size();i++){
        cout << ans[i];
    }
}
