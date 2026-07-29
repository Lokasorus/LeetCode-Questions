/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int swaps(vector<int>& temp){
    map<int, int> mpp;
    int n = temp.size();

    vector<int> arr = temp;
    sort(arr.begin(), arr.end());
    for(int i = 0; i<arr.size(); i++){
        mpp[arr[i]] = i;
    }
    int cnt = 0;
    vector<int> vis(n, 0);
    for(int i = 0; i<n; i++){
        if(!vis[i]){
            int start = i;
            vis[start] = 1;
            while(mpp[temp[start]]!=i){
                
                start = mpp[temp[start]];
                vis[start] = 1;
                cnt++;


            }
        }
    }
    return cnt;


}
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        while(!q.empty()){
            int size = q.size();
            vector<int> temp;
            
            for(int i = 0; i<size; i++){
                TreeNode* curr = q.front();
                q.pop();
                temp.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);

                
            }
            ans += swaps(temp);

            

        }
        return ans;
        
    }
};