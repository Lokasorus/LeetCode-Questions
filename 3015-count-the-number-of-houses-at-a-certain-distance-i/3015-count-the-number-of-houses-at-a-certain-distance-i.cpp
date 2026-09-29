class Solution {
public:
void bfs(int node, vector<vector<int>>& adj, vector<int> &dist){
    queue<pair<int, int>> q;
    int n = adj.size();
    q.push({0, node});
    vector<int> vis(n, 0);
    vis[node] = 1;
    while(!q.empty()){
        auto it = q.front();
        int dis = it.first;
        q.pop();
        dist[dis]++;
        int no = it.second;
        for(auto it: adj[no]){
            if(!vis[it]){
                q.push({dis+1, it});
                vis[it] = 1;
            }
        }
    }
}
    vector<int> countOfPairs(int n, int x, int y) {
        vector<vector<int>> adj(n+1);
        adj[x].push_back(y);
        adj[y].push_back(x);
        for(int i = 1; i<=n-1; i++){
            adj[i].push_back(i+1);
            adj[i+1].push_back(i);
        }
        vector<int> dist(n+1, 0);
        for(int i = 1; i<=n; i++){
            bfs(i, adj, dist);
        }
        dist.erase(dist.begin());
        return dist;
        
    }
};