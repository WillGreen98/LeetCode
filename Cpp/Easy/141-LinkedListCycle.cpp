/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
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
        bool hasCycle(ListNode *head) {
            if(head == nullptr) return false;

            ListNode *tortoise = head;
            ListNode *hare = head;

            while(hare != nullptr && hare->next != nullptr) {
                tortoise = tortoise->next;
                hare = hare->next->next;

                if(tortoise == hare) return true;
            }

            return false;
        }
};
// @lc code=end
