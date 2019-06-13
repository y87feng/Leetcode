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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) return head;
        int index = remove_nth_from_end(head, n);
        if (index == n) return head->next;
        return head;
    }
    
    int remove_nth_from_end(ListNode* node, int n) { // return the node index from the end
        if (node->next == nullptr) return 1;
        int next_index = remove_nth_from_end(node->next, n);
        if (n == next_index) {
            node->next = node->next->next;
        }
        return next_index+1;
    }
};