class Solution {
public:
void dfs(int node, int parent, int &maxi, int &far, int dist, vector<vector<int>>& adj){
    if(dist>maxi){
        maxi = dist;
        far = node;
    }

    for(auto it: adj[node]){
        if(it!=parent){
            dfs(it, node, maxi, far, dist+1, adj);
        }
    }

}
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size();
        int m = edges2.size();
        vector<vector<int>> adj1(n+1);
        vector<vector<int>> adj2(m+1);

        for(int i = 0; i<n; i++){
            int u = edges1[i][0];
            int v = edges1[i][1];
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }
        for(int i = 0; i<m; i++){
            int u = edges2[i][0];
            int v = edges2[i][1];
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }
        int maxi = -1;
        int far;
        dfs(0, -1, maxi, far, 0, adj1);
        int u = far;
        maxi = -1;

        dfs(u, -1, maxi, far, 0, adj1);
        int d1 = maxi;
        int r1 = (maxi+1)/2;
        maxi = -1;
        dfs(0, -1, maxi, far, 0, adj2);
        int v = far;
        maxi = -1;
        dfs(v, -1, maxi, far, 0, adj2);
        int d2 = maxi;
        int r2 = (maxi+1)/2;

        return max(d1, max(d2, r1+1+r2));


        
        
    }
};