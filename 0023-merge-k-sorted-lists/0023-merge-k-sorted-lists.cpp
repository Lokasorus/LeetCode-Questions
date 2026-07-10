/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        for(auto it: lists){
            if(it!=nullptr){
            pq.push({it->val, it});
            }
        }
        
        while(!pq.empty()){
            auto it = pq.top();
            curr->next = new ListNode(it.first);
            
            pq.pop();
            if(it.second->next!=nullptr){
                pq.push({it.second->next->val, it.second->next});
            }
            curr = curr->next;
        }
        return dummy->next;
        
    }
};