class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        vector<int> inc(n, 1);
        vector<int> dec(n, 1);
        int in = 1;
        int de = 1;
        for(int i = 1; i<security.size(); i++){
            if(security[i]<=security[i-1]){
                in++;
                inc[i] = in;
            }else{
                in = 1;
            }
        }
        for(int i = n-2; i>=0; i--){
            if(security[i]<=security[i+1]){
                de++;
                dec[i] = de;
            }else{
                de = 1;
            }
        }
        vector<int> ans;
        for(int i = 0; i<n; i++){
            if(inc[i]-1>=time && dec[i]-1>=time){
                ans.push_back(i);
            }

        }
        return ans;
        
    }
};