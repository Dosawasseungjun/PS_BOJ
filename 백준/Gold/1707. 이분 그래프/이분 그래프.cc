#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector<vector<int>> adj; //인접 리스트 표현
bool visited[2][40001]; //짝수번째 방문했는지 홀수번째 방문했는지 판단
void bfs(int start, int cnt){
    
    queue<pair<int, int>> q;
    visited[cnt%2][start] = true;
    q.push(make_pair(cnt, start));
    
    while (!q.empty()) {
        pair<int, int> here = q.front();
        q.pop();
        for(int i=0;i<adj[here.second].size();i++){
            if(!visited[(here.first+1)%2][adj[here.second][i]]){
                q.push(make_pair(here.first+1, adj[here.second][i]));
                visited[(here.first+1)%2][adj[here.second][i]] = true;
            }
        }
    }
    
}

void bfsAll(){
    for(int i=1;i<adj.size();i++){
        if(!visited[0][i]&&!visited[1][i]){
            bfs(i,0);
        }
    }
}

int main(){
    int test;
    cin >> test;
    
    while (test--) {
        int v,e;
        cin >> v >> e;
        
        memset(visited, false, sizeof(visited));
        adj = vector<vector<int>> (v+1);
        
        for(int i=0;i<e;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        bfsAll();
        bool result = true;
        for(int i=1;i<=v;i++){
            if(visited[0][i]&&visited[1][i]) result = false;
        }
        if(result) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}
