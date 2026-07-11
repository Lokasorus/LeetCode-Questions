class Solution {
public:
bool isPalindrome(int i, int j, string s) {
  
  	while(i<j){
        if(s[i] != s[j])return false;
        i++;
        j--;
    }

    return true;
}
void f(int i, int n,  string &s,  vector<string> curr, vector<vector<string>>& ans){
    if(i==n){
        ans.push_back(curr);
        return;
    }
    
    
    
    for(int j = i; j<n; j++){
        
        if(isPalindrome(i, j, s)){
            curr.push_back(s.substr(i, j-i+1));
            f(j+1, n, s, curr, ans);
            curr.pop_back();
            
        }

    }
}
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<string> curr;
        vector<vector<string>> ans;

         f(0, n, s, curr, ans);
         return ans;
    }
};