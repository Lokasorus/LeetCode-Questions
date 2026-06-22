class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
 set<int> st;
        int i = 0;
        int n = nums.size();
        while(i<n){
            long long x = nums[i];
            auto it = st.lower_bound(x-valueDiff);
            if(it!=st.end() && *it<=x+valueDiff){
                return true;
            }
            st.insert(x);
            if(i>=indexDiff){
                st.erase(nums[i-indexDiff]);
            }
            i++;
        }
        return false;
    }
};