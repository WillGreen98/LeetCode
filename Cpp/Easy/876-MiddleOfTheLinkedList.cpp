/*
 * @lc app=leetcode id=876 lang=cpp
 *
 * [876] Middle of the Linked List
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
        ListNode* middleNode(ListNode *head) {
            ListNode *tortoise = head;
            ListNode *hare = head;

            while(hare != nullptr && hare->next != nullptr) {
                tortoise = tortoise->next;
                hare = hare->next->next;
            }

            return tortoise;
        }
};
// @lc code=end
