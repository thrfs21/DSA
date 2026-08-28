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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* temp = head;
        ListNode* newHead = new ListNode(temp->val);
        temp = temp->next;

        while(temp){
            ListNode* newNode = new ListNode(temp->val);

            if(newNode->val < newHead->val){
                newNode->next = newHead;
                newHead = newNode;
            }
            else {
                ListNode* prev = newHead;
                ListNode* curr = prev->next;

                while(curr && curr->val < newNode->val){
                    curr = curr->next;
                    prev = prev->next;
                }

                prev->next = newNode;
                newNode->next = curr;
            }

            temp = temp->next;
        }

        return newHead;
    }
};
