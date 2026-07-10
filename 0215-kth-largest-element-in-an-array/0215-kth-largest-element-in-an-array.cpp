class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int, greater<int>> st;
        for(int i = 0; i<nums.size(); i++){
            st.insert(nums[i]);
        }
        int cnt = 0;
        for(auto it: st){
            cnt++;
            if(cnt == k) return it;
        }
        return -1;
    }
};