/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 */

// @lc code=start
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
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            ListNode *pA = headA;
            ListNode *pB = headB;

            while(pA != pB) {
                pA = pA == NULL ? headB : pA->next;
                pB = pB == NULL ? headA : pB->next;
            }

            return pA;
        }
};
// @lc code=end
