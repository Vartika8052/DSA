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
    ListNode* mergeTwoSorted(ListNode* L1, ListNode*  L2){
        if(!L1 ) return L2;
        if(!L2) return L1;

        if(L1-> val <= L2-> val){
            L1->next = mergeTwoSorted(L1->next, L2);
            return L1;
        }
        else{
            L2->next = mergeTwoSorted(L1, L2->next);
            return L2;
        }
        return NULL;
    }
    ListNode* partitionAndMerge(int s, int e, vector<ListNode*>& lists){
        if(s > e){
            return NULL;
        }
        if(s == e){
            return lists[s];
        }
        int mid = s + (e - s)/2;
        ListNode* L1 = partitionAndMerge(s, mid, lists);
        ListNode* L2 = partitionAndMerge(mid + 1, e, lists);
        return mergeTwoSorted(L1, L2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k == 0)
           return NULL;
        return partitionAndMerge(0, k-1, lists);
        
    }
};