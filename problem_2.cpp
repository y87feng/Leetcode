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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry_bit = 0;
        auto cur1 = l1;
        auto cur2 = l2;
        ListNode * pre_header = new ListNode(0);
        auto res_cur = pre_header; 
        while (cur1 != nullptr || cur2 != nullptr) {
            int value = carry_bit;
            if (cur1 != nullptr) {
                value += cur1->val;
                cur1 = cur1->next;
            }
            if (cur2 != nullptr) {
                value += cur2->val;
                cur2 = cur2->next;
            }
            carry_bit = value / 10;
            value = value % 10;
            res_cur->next = new ListNode(value);
            
            res_cur = res_cur->next;
        }
        
        if (carry_bit != 0) {
            res_cur->next = new ListNode(carry_bit);
        }
        
        return pre_header->next;
    }
};