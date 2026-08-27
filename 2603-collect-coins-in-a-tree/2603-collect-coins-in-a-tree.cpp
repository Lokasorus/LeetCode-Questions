class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n = coins.size();
        vector<unordered_set<int>> adj(n+1);
        vector<int> indegree(n, 0);
        for(auto it: edges){
            int  u = it[0];
            int v = it[1];
            adj[u].insert(v);
            indegree[v]++;
            adj[v].insert(u);
            indegree[u]++;
        }
        
        queue<int> q;
        for(int i = 0; i<n; i++){
            if(indegree[i] == 1 && coins[i] == 0) q.push(i);
        }
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            for(auto x: adj[it]){
                adj[x].erase(it);
                indegree[x]--;
                if(indegree[x] == 1 && coins[x] == 0) q.push(x);
            }
            indegree[it] = 0;
        }

        for(int i = 0; i<2; i++){
            vector<int> leaves;
            for(int j = 0; j<n; j++){
                if(indegree[j] == 1) leaves.push_back(j);
            }
            for(int u: leaves){
                indegree[u] = 0;
                for(int x: adj[u]){
                    adj[x].erase(u);
                    indegree[x]--;
                }
                
            }
        }
        int ans = 0;
        for(int i = 0; i<n; i++){
            if(indegree[i]>0) ans++;
        }
        return max(0, 2*(ans-1));
        
        
        
    }
};