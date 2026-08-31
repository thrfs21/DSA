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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int critical = 0;
        bool found = false;

        int count = 0;
        int maxi = 0;
        int mini = INT_MAX;

        ListNode* prev = head;
        ListNode* curr = head->next;

        while(curr->next){
            if((curr->val > prev->val && curr->val > curr->next->val) ||
                (curr->val < prev->val && curr->val < curr->next->val)){
                    critical++;
                    if(found) mini = min(mini, count);

                    maxi += count;
                    found = true;
                    count = 0;
            }

            if(found) count++;

            prev = prev->next;
            curr = curr->next;
        }

        if(critical < 2) return {-1,-1};

        return {mini, maxi};
    }
};
