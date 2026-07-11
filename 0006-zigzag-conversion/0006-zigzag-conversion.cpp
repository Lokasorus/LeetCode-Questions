class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> ans(numRows);
        if(numRows == 1) return s;
        int row = 0;
        bool down = true;
        for(char c: s){
            ans[row]+=c;
            if(row == 0) down = true;
            if(row == numRows-1) down = false;
            if(down) row++;
            else row--;
        }
        string ss;
        for(auto it: ans){
            for(char c: it){
                ss += c;
            }
        }
        return ss;
    }
};