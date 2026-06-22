class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int maxi = *max_element(arr1.begin(), arr1.end());
        vector<int> cnt(maxi+1, 0);
        int n = arr1.size();
        for(int i = 0; i<arr1.size(); i++){
            cnt[arr1[i]]++;
        }
        vector<int>ans(n);
        int k = 0;
        for(int i = 0; i<arr2.size(); i++){
            while(cnt[arr2[i]] >0){
                ans[k++] = arr2[i];
                cnt[arr2[i]]--;
            }
        }
        for(int i = 0; i<maxi+1; i++){
            while(cnt[i]>0){
                ans[k++] = i;
                cnt[i]--;
            }
        }
        return ans;

        
    }
};