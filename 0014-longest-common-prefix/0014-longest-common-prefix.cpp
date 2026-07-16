class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        sort(strs.begin(), strs.end());
        string one = strs[0];
        string end = strs[n-1];
        string cnt = "";
        int i = 0;
        int j = one.size();
        while(i<j){
            if(one[i] != end[i]) break;
            cnt+= one[i];
            i++;
        }
        return cnt;
        
    }
};