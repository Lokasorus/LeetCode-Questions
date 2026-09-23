class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> fleet(n);
        for(int i = 0; i<n; i++){
            fleet[i] = {position[i], (double)(target - position[i])/speed[i]};
        } 
        sort(fleet.begin(), fleet.end(), [](auto& a, auto& b){
            return a.first > b.first;
           
        });
        double prev = fleet[0].second;
        int ans = 1;
        int res = 1;
        for(int i = 1; i<n; i++){
            double cur = fleet[i].second;
            if(cur>prev){
                res++;
                prev = cur;

            }

        }
        return res;      
    }
};