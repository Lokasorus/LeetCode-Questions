class Solution {
public:
void f(string &num, int &target, int i, long long curr, long long prev, string path, vector<string> &ans){
    if(i == num.size()){
        if(curr == target){
            ans.push_back(path);
        }
        return;
    }

    for(int j = i; j<num.size(); j++){
        if(j>i && num[i] == '0') return;
        long long cur = stoll(num.substr(i, j-i+1));
        string c = num.substr(i, j-i+1);
        if(i == 0){
            f(num, target, j+1, cur, cur, path + c, ans);
        }else{
            f(num, target, j+1, curr + cur, cur, path+"+"+c, ans);
            f(num, target, j+1, curr - cur, -cur, path +"-"+c, ans);
            f(num, target, j+1, curr - prev + prev*cur, prev*cur, path + "*" + c, ans);
        }
    }
}
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        f(num, target, 0, 0, 0, "", ans);
        return ans;
        
    }
};