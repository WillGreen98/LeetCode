/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
        ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
            if(list1 == nullptr) return list2;
            if(list2 == nullptr) return list1;
            if(list1 == nullptr && list2 == nullptr) return nullptr;

            ListNode *head = nullptr;
            ListNode *tail = nullptr;

            while(list1 != nullptr && list2 != nullptr) {
                if(list1->val < list2->val) {
                    if(head == nullptr) {
                        head = list1;
                        tail = list1;
                    } else {
                        tail->next = list1;
                        tail = tail->next;
                    }

                    list1 = list1->next;
                } else {
                    if(head == nullptr) {
                        head = list2;
                        tail = list2;
                    } else {
                        tail->next = list2;
                        tail = tail->next;
                    }

                    list2 = list2->next;
                }
            }

            if(list1 != nullptr) tail->next = list1;
            if(list2 != nullptr) tail->next = list2;

            return head;
        }
};
// @lc code=end
