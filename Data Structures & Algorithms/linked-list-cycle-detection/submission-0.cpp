/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        unordered_set<ListNode*> mp;

        ListNode* curr = head;
        while(curr){
            if(mp.find(curr) != mp.end()){
                return true;
            }
            mp.insert(curr);
            curr = curr->next;
        }

        return false;

    }
};