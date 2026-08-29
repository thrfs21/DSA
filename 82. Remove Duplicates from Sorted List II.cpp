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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* prev = head;
        ListNode* curr = head->next;
        unordered_set<int> set;

        while(curr){
            if(prev->val == curr->val){
                set.insert(curr->val);
                
                while(curr && curr->val == prev->val) curr = curr->next;

                if(curr == NULL) break;
                prev->next = curr;
            }


            prev = curr;
            curr = curr->next;
        }

        while(head && set.contains(head->val)){
            head = head->next;
        }
        if(head == NULL || head->next == NULL) return head;

        ListNode* temp = head;
        while(temp->next){
            if(set.contains(temp->next->val)) temp->next = temp->next->next;
            else {
                temp = temp->next;
            }
        }

        return head;
    }
};
