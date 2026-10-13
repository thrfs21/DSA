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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* list1 = new ListNode(0);
        ListNode* list2 = new ListNode(0);
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        while(head){

            ListNode* newNode = new ListNode(head->val);

            if(head->val < x){
                temp1->next = newNode;
                temp1 = temp1->next;
            } else {
                temp2->next = newNode;
                temp2 = temp2->next;
            }

            head = head->next;
        }

        if(list1->next == NULL) return list2->next;

        temp1->next = list2->next;
        return list1->next;
    }
};
