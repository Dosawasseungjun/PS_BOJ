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

void solv(){
    int n; cin >> n;
    vector<int> a(n+2);
    for(int i=1;i<=n;i++) cin >> a[i];
    a[n+1] = n+1;   
    vector<int> cand;
    cand.push_back(1);
    for(int i=2;i<=n;i++){
        if(abs(a[i] - a[i-1]) != 1){
            cand.push_back(i-1);
            cand.push_back(i);
        }
    }
    cand.push_back(n);
    cand.erase(unique(cand.begin(), cand.end()), cand.end());
    vector<int> comb1;
    for(int i=0;i<cand.size()-2;i++){
        comb1.push_back(0);
    }
    comb1.push_back(1); comb1.push_back(1);

    do{
        int l1 = 0, r1 = 0;
        int l2 = 0, r2 = 0;
        for(int i=0;i<cand.size();i++){
            if(!l1 && comb1[i]) l1 = cand[i];
            else if(comb1[i]) r1 = cand[i];
        }
        vector<int> tmp = a;
        reverse(tmp.begin()+l1, tmp.begin()+r1+1);
        
        vector<int> cand2;
        cand2.push_back(1);
        for(int i=2;i<=n;i++){
            if(abs(tmp[i] - tmp[i-1]) != 1){
                cand2.push_back(i-1);
                cand2.push_back(i);
            }
        }
        cand2.push_back(n);
        cand2.erase(unique(cand2.begin(), cand2.end()), cand2.end());
        vector<int> comb2;
        for(int i=0;i<cand2.size()-2;i++){
            comb2.push_back(0);
        }
        comb2.push_back(1); comb2.push_back(1);

        do{
            int l2 = 0, r2 = 0;
            for(int i=0;i<cand2.size();i++){
                if(!l2 && comb2[i]) l2 = cand2[i];
                else if(comb2[i]) r2 = cand2[i];
            }

            vector<int> tmp2 = tmp;
            reverse(tmp2.begin()+l2, tmp2.begin()+r2+1);
            bool ok = true;
            for(int i=1;i<=n;i++) if(tmp2[i] != i) ok = false;
            if(ok){
                cout << l1 << ' ' << r1 << '\n';
                cout << l2 << ' ' << r2 << '\n';
                return ;
            }
        }while(next_permutation(comb2.begin(), comb2.end()));
        
        bool ok = true;
        for(int i=1;i<=n;i++) if(tmp[i] != i) ok = false;
        if(ok){
            cout << l1 << ' ' << r1 << '\n';
            cout << 1 << ' ' << 1 << '\n';
            return ;
        }

    }while(next_permutation(comb1.begin(), comb1.end()));
}

int main(){
    fast_io
    solv();
}