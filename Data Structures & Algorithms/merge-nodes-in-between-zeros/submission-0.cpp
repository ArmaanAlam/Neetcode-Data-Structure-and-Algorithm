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
    ListNode* mergeNodes(ListNode* head) {
        
        ListNode* newNode = new ListNode(-1);
        ListNode* tail = newNode;
        int total = 0;
        ListNode* curr = head->next;

        while(curr){
            if(curr->val == 0){
                tail->next = new ListNode(total);
                tail = tail->next;
                total = 0;
            }
            else{
                total += curr->val;
            }
            curr = curr->next;
        }

        return newNode->next;
    }
};
