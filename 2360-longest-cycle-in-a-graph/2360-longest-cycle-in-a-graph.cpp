class Solution {
public:
int longest = -1;

void dfs(int node, unordered_map<int, int> &dist, vector<int>& edges, vector<int> &vis){
    vis[node]=1;
    int adjnode = edges[node];
    if(adjnode!=-1 && !vis[adjnode]){
        dist[adjnode] = dist[node]+1;
        dfs(adjnode, dist, edges, vis );
    }else if(adjnode!=-1 && dist.count(adjnode)){
        longest = max(longest, dist[node] - dist[adjnode] + 1);
    }
    return;

    
}
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        
        vector<int> vis(n, 0);
        
        for(int i = 0; i<n; i++){
            if(!vis[i]){
            unordered_map<int, int> dist;
            dist[i] = 1;
            dfs(i, dist, edges, vis);
            }
            
            
        }

        return longest;
    }
};