class Solution {
public:
string f(string &s, vector<int> &hash){
    for(int i = 0; i<s.size(); i++){
        hash[s[i]-'a' + 26*(i%2)]++;
    }

    string ans = "";
    for(int i = 0; i<51; i++){
        ans += hash[i];

    }
    return ans;
}
    int numSpecialEquivGroups(vector<string>& words) {
        set<string> st;
        for(int i = 0; i<words.size(); i++){
            vector<int> hash(52, 0);
            string s = f(words[i], hash);
            st.insert(s);
        }
        return st.size();
        
    }
};