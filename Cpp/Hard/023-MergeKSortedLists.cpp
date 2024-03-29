/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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
        ListNode *mergeKLists(vector<ListNode*> &lists) {
            ListNode *head = new ListNode(0);
            ListNode *current = head;

            for(int i = 0; i < lists.size(); i++) {
                current->next = lists[i];
                while(current->next != nullptr) {
                    current = current->next;
                }
            }

            current = head->next;
            while(current != nullptr) {
                ListNode *temp = current->next;
                while(temp != nullptr) {
                    if(current->val > temp->val) {
                        int tempVal = current->val;
                        current->val = temp->val;
                        temp->val = tempVal;
                    }

                    temp = temp->next;
                }

                current = current->next;
            }

            return head->next;
        }
};
// @lc code=end
