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

    ListNode* reverse(ListNode* head){

        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        
ListNode* head1 = NULL;
ListNode* tail = NULL;

ListNode* temp = head;

while (temp) {
    ListNode* node = new ListNode(temp->val);

    if (head1 == NULL) {
        head1 = node;
        tail = node;
    }
    else {
        tail->next = node;
        tail = node;
    }

    temp = temp->next;
}        ListNode* head2 = reverse(head);

        while(head1 && head2){
            if(head1->val != head2->val){
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }

        return true;
    }
};