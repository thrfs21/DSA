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
    ListNode* doubleIt(ListNode* head) {
        if(head == NULL || head->val == 0) return head;

        // reverse
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;
        int carry = 0;
        ListNode* temp = head;
        while(temp){
            int value = (temp->val * 2) + carry;
            if(value > 9) carry = 1;
            else carry = 0;
            value = value % 10;

            temp->val = value;
            temp = temp->next;
        }

        // reverse back
        prev = NULL;
        curr = head;
        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        if(carry){
            ListNode* newNode = new ListNode(carry);
            newNode->next = prev;
            return newNode;
        }

        return prev;

    }
};
