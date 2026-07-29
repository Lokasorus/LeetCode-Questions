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
    int ans=0;
    int n = temp.size();
    vector<pair<int, int>> arr;
    for(int i = 0; i<temp.size(); i++){
        arr.push_back({temp[i], i});
    }
    sort(arr.begin(), arr.end());
    vector<int> vis(n, 0);
    for(int i = 0; i<arr.size(); i++){
        if(vis[i] || arr[i].second == i) continue;

        int j = i;
        int cnt = 0;
        while(!vis[j]){
            vis[j] = 1;
            j = arr[j].second;
            cnt++;
            
        }
        ans += cnt-1;
    }
    return ans;


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