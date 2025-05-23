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

class Cube{
public:
    char front, right, back, left, top, bottom;
    Cube(char a, char b, char c, char d, char e, char f) : front(a),right(b),back(c), left(d), top(e), bottom(f) {}
    Cube() {}
    
    void roll_right(){
        *this = Cube(front, top, back, bottom, left, right);
        
    }
    void roll_front(){
        *this = Cube(top, right, bottom, left, back, front);
    }
    void roll(int idx){
        for(int i=0;i<idx;i++){
            this -> roll_right();
        }
    }
    Cube make_shape(int idx){
        Cube ret = *this;
        switch (idx / 4){
            case 0 : {
                ret.roll(idx % 4);
                break;
            }
            case 1 : {
                ret.roll_right();ret.roll_right();ret.roll_right();
                ret.roll_front();
                ret.roll(idx % 4);
                break;
            }
            case 2 : {
                ret.roll_front();ret.roll_front();
                ret.roll(idx % 4);
                break;
            }
            case 3 : {
                ret.roll_right(); ret.roll_front();
                ret.roll(idx % 4);
                break;
            }
            case 4 : {
                ret.roll_front();
                ret.roll(idx % 4);
                break;
            }
            case 5 : {
                ret.roll_front();ret.roll_front();ret.roll_front();
                ret.roll(idx % 4);
                break;
            }
            
        }

        return ret;
    }
    vector<char> dice_print(){
        vector<char> ret= {front, right, back, left, top, bottom};
        return ret;
    }

};

int main(){
    fast_io
    vector<Cube> C(4);
    for(int i=0;i<4;i++){
        string s; cin >> s;
        C[i] = Cube(s[0], s[1], s[2], s[3], s[4], s[5]);
    }
    set<pair<vector<vector<char>>, char>> st;
    for(int i=0;i<24;i++){
        Cube d1 = C[0].make_shape(i);
        for(int j=0;j<24;j++){
            Cube d2 = C[1].make_shape(j);
            for(int k=0;k<24;k++){
                Cube d3 = C[2].make_shape(k);
                for(int p=0;p<24;p++){
                    Cube d4 = C[3].make_shape(p);
                    vector<vector<char>> tmp;
                    tmp.emplace_back(d1.dice_print());
                    tmp.emplace_back(d2.dice_print());
                    tmp.emplace_back(d3.dice_print());
                    tmp.emplace_back(d4.dice_print());
                    bool ok = true;
                    vector<vector<char>> tmp2;
                    for(int q=0;q<4;q++){
                        set<char> cst;
                        vector<char> vvv;
                        for(int r=0;r<4;r++){
                            cst.insert(tmp[r][q]);
                            vvv.push_back(tmp[r][q]);
                        }
                        if(cst.size() != 4) {ok = false; break;}
                        tmp2.push_back(vvv);
                    }
                    if(ok) {
                        st.insert({tmp2, tmp[3][4]});
                    }
                    
                }
            }
        }
    }
    int res = 0;
    auto del_iter = st.end();
    for(auto it = st.begin();it!=st.end();it++){
        auto V = it -> first;
        auto top = it -> second;
        if(del_iter != st.end()){
            st.erase(del_iter);
        }
        bool ok = true;
        for(int i=1;i<4;i++){
            vector<vector<char>> tmp;
            for(int j=0;j<4;j++){
                tmp.emplace_back(V[(i+j)%4]);
            }
            bool equal = std::equal(std::begin(tmp), std::end(tmp), std::begin(V));
            if(equal) continue;
            if(st.count({tmp, top})){
                ok = false;
                break;
            }
        }
        if(!ok) del_iter = it;
        else del_iter = st.end();
    }
    cout << st.size();
}