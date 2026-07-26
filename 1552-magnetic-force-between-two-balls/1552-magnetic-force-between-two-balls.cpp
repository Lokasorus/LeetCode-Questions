class Solution {
public:
int helper(int d, vector<int> &arr){
    int last = arr[0];
    int cnt = 1;
    for(int i = 1; i<arr.size(); i++){
        if(arr[i] - last >=d){
            cnt++;
            last = arr[i];
        }
    }
    return cnt;
}
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        
       int n = position.size();
        

        int low = 1;
        int high = position[n-1] - position[0];
        while(low<=high){
            int mid = low+(high - low)/2;
            if(helper(mid, position) >= m){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return high;

        
    }
};