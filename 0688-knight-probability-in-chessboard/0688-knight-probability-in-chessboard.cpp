class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {

        vector<vector<vector<double>>> dp(k+1, vector<vector<double>>(n+1, vector<double>(n+1, 0)));
        dp[0][row][column] = 1.0;
        double p = 0.125;
        vector<pair<int, int>> moves = {{-1, -2}, {-1, 2}, {-2, -1}, {-2, 1}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
        for(int i = 0; i<k; i++){
            for(int r = 0; r<n; r++){
                for(int c = 0; c<n; c++){
                    if(dp[i][r][c] == 0.0) continue;
                    for(auto it: moves){
                        int nr = r+ it.first;
                        int nc = c+ it.second;
                        if(nr>=0 && nr<n && nc>=0 && nc<n){
                            dp[i+1][nr][nc] += dp[i][r][c]*p;
                        }
                    }
                }
            }
        }
        double ans = 0.0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                 ans += dp[k][i][j];
            }
        }
        return ans;
        
    }
};