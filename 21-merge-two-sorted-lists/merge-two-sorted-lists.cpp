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
    ListNode* solve(ListNode* list1, ListNode* list2) {
        ListNode* curr1 = list1;
        ListNode* next1 = curr1->next;
        ListNode* curr2 = list2;
        ListNode* next2 = nullptr;

        // KEY FIX: if list1 has only one node, directly attach list2
        if (next1 == nullptr) {
            curr1->next = curr2;
            return list1;
        }

        while (next1 != nullptr && curr2 != nullptr) {
            if (curr2->val >= curr1->val && curr2->val <= next1->val) {
                // insert curr2 between curr1 and next1
                next2 = curr2->next;
                curr1->next = curr2;
                curr2->next = next1;

                // advance pointers
                curr1 = curr2;
                curr2 = next2;
            } else {
                // move forward in list1
                curr1 = next1;
                next1 = next1->next;

                // if reached end of list1, attach remaining list2
                if (next1 == nullptr) {
                    curr1->next = curr2;
                    return list1;
                }
            }
        }
        return list1;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        // ensure first param of solve has the smaller head
        if (list1->val <= list2->val)
            return solve(list1, list2);
        else
            return solve(list2, list1);
    }
};
