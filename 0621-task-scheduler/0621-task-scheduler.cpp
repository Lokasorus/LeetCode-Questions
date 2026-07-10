class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        vector<int> freq(26, 0);
        for(int i = 0; i<tasks.size(); i++){
            freq[tasks[i] - 'A']++;
        }

        int maxi  = *max_element(freq.begin(), freq.end());
        int cnt = 0;
        for(auto it: freq){
            if(it == maxi){
                cnt++;
            }
        }

        return max((int)tasks.size(), (maxi-1)*(n+1)+cnt);
    }
};