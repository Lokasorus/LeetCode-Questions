class Solution {
public:
    void dfs(int node, vector<vector<int>> &adj, vector<int>& vis, vector<int>& ind, string &s, string &ans){
        vis[node] = 1;
        ind.push_back(node);
        ans += s[node];

        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it, adj, vis, ind, s, ans);
            }
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
         int n = s.size();
        vector<vector<int>> adj(n);
        for(auto it: pairs){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
       
        string a(n, '.');
        vector<int> vis(n, 0);
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                vector<int> ind;
                string ans = "";
                dfs(i, adj, vis, ind, s, ans);
                sort(ans.begin(), ans.end());
                sort(ind.begin(), ind.end());
                for(int i = 0; i<ind.size(); i++){
                    a[ind[i]] = ans[i];
                }


            }
         
            
        }
           return a;

    }
};