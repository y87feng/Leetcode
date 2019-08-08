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

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) return head;
        int len = 0;
        auto cur = head;

        while (cur) {
            len++;
            cur = cur->next;
        }

        if (len == n) return head->next;
        auto pre = head;
        for (int i = 0; i < len; i++) {
            if (len - i == n+1) {
                pre->next = pre->next->next;
                break;
            }
            pre = pre->next;
        }
        return head;
    }
    
};