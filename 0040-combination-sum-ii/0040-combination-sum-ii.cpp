class Solution {
public:

    void combination(int ind, vector<vector<int>> &ds, vector<int> &a, vector<int> &subset, int k, int n){
        if(k == 0){
            ds.push_back(subset);
            return;
        }
        for(int i = ind; i<n; i++){
            if(i>ind && a[i] == a[i-1]){
                continue;
            }
            if(a[i]>k) break;
            subset.push_back(a[i]);
            combination(i+1, ds, a, subset, k-a[i], n);
            subset.pop_back();

        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ds;
        vector<int> subset;
        sort(candidates.begin(), candidates.end());
        int n = candidates.size();
        combination(0, ds, candidates, subset, target, n);
        return ds;

        
    }
};