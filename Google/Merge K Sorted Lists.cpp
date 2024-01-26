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
    ListNode* MergeList(ListNode* &l1,ListNode* &l2){
        ListNode* dummy = new ListNode(-1);
        ListNode* l3 = dummy;;
        while(l1 && l2){
            if(l1->val > l2->val){
                l3->next = l2;
                l3 = l3->next;
                l2 = l2->next;
            }
            else{
                l3->next = l1;
                l3 = l3->next;
                l1 = l1->next;
            }
        }
        while(l1){
            l3->next = l1;
            l3 = l3->next;
            l1 = l1->next;
        }
        while(l2){
            l3->next = l2;
            l3 = l3->next;
            l2 = l2->next;
        }
        return dummy->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();

        if(k == 0)
            return NULL;
        
        while(k > 1){
            for(int i=0;i<k/2;i++){
                lists[i] = MergeList(lists[i], lists[k-i-1]);
            }
            k = (k+1)/2;
        }
        return lists[0];
    }
};
