class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

        // Remove matching nodes from the beginning
        while (head && head->val == val) {
            head = head->next;
        }

        ListNode* curr = head;

        while (curr) {

            ListNode* temp = curr->next;

            // Skip all nodes having val
            while (temp && temp->val == val) {
                temp = temp->next;
            }

            // Connect curr to the first non-val node
            curr->next = temp;

            curr = temp;
        }

        return head;
    }
};