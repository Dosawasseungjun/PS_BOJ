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

struct Trie{
    int now_cnt = 0;
    vector<Trie *> active;

    Trie():now_cnt(0), active(2, nullptr){};
    void insert(int bit, int x){
        now_cnt++;
        if(bit == -1) return ;
        
        int on = (x & (1 << bit) ? 1 : 0);
        if(!active[on]) active[on] = new Trie();
        active[on] -> insert(bit-1, x);
    }

    void del(int bit, int x){
        now_cnt--;
        if(bit == -1) return ;

        int on = (x & (1 << bit) ? 1 : 0);
        active[on] -> del(bit-1, x);
        if(active[on]->now_cnt == 0){
            active[on] = nullptr;
        }

    }

    int f(int bit, int x){
        if(bit == -1){
            return 0;
        }
        int ret = 0;
        if(x & (1 << bit)){ // 0이 있으면 가
            if(active[0]){
                ret |= (1 << bit) + (active[0]->f(bit-1, x));
            }else{
                ret |= (active[1] -> f(bit-1, x));
            }
        }else{ // 1이 있으면 가
            if(active[1]){
                ret |= (1 << bit) + (active[1]->f(bit-1, x));
            }else{
                ret |= (active[0] -> f(bit-1, x));
            }
        }

        return ret;
    }
};


int main(){
    fast_io
    Trie* root = new Trie();
    root->insert(31, 0);
    int M; cin >> M;
    while(M--){
        int op, x;
        cin >> op >> x;
        if(op == 1){
            root->insert(31, x);
        }else if(op == 2){
            root->del(31, x);
        }else{
            cout << root->f(31, x) << '\n';
        }
    }
}