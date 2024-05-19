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

struct TreeNode{
    char label;
    TreeNode * left,* right;
};

vector<TreeNode> tree(26);

void preorder(TreeNode* root){
    if(root == NULL) return;

    cout << root -> label;
    preorder(root -> left);
    preorder(root -> right);
}

void inorder(TreeNode* root){
    if(root == NULL) return;

    inorder(root -> left);
    cout << root -> label;
    inorder(root -> right);
}

void postorder(TreeNode* root){
    if(root == NULL) return;

    postorder(root -> left);
    postorder(root -> right);
    cout << root -> label;
}

int main(){
    fast_io
    int n; cin >> n;
    for(int i=0;i<n;i++){
        char p, c1, c2;
        cin >> p >> c1 >> c2;
        tree[p - 'A'].label = p;
        if(c1 != '.') tree[p-'A'].left = &tree[c1-'A'];
        if(c2 != '.') tree[p-'A'].right = &tree[c2-'A'];
    }

    preorder(&tree[0]); cout << '\n';
    inorder(&tree[0]); cout << '\n';
    postorder(&tree[0]);
}