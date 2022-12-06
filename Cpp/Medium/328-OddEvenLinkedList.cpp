/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
 */

// @lc code=start
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
        ListNode* oddEvenList(ListNode *head) {
            if(head == nullptr) return head;

            ListNode *odd_p = head;
            ListNode *even_p = head->next;
            ListNode *even_head = even_p;

            while(even_p != nullptr && even_p->next != nullptr) {
                odd_p->next = even_p->next;
                odd_p = odd_p->next;
                even_p->next = odd_p->next;
                even_p = even_p->next;
            }

            odd_p->next = even_head;

            return head;
        }
};
// @lc code=end
