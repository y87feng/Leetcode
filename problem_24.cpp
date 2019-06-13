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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr) return head;
        auto fakehead = new ListNode(0); // fake head
        fakehead->next = head;
        auto prev = fakehead;
        auto cur = head;
        auto next = head->next;
        while (next) {
            prev->next = next;
            cur->next = next->next;
            next->next = cur;
            
            prev = cur;
            cur = cur->next;
            if (cur == nullptr) break;
            next = cur->next;
        }
        return fakehead->next;
    }
};