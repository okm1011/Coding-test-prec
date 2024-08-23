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
        if(head == nullptr)return nullptr;
        set<int>ch;
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        ListNode* check = head;
        ListNode* last_check = dummy;

        while(1){

            if(check->next == nullptr)break;

            if(check->val == check->next->val){
                int same_val = check->val;
                while(1){
                    if(check->next != nullptr)check = check->next;
                    else {
                        temp -> next = nullptr;
                        return dummy->next;
                    }

                    if(same_val != check->val)break;
                }
            }else{
                
                last_check = check;
                temp->next = last_check;
                temp = temp->next;
                if(check->next != nullptr)check = check->next;
                else break;
            }

        }
        
        if(last_check->val != check->val) temp -> next = check;
        return dummy->next;
    }
};