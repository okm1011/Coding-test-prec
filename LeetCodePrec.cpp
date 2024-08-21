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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        stack<ListNode*>st;
        ListNode*temp = head;
        int index = 1;
        ListNode* first = nullptr;
        ListNode* end = nullptr;
        
        while(1){

            if(index >= left && index <= right){
                st.push(temp);
            }
            if(index == left-1 && left - 1 >=1){
                first = temp;
            }
            if(index == right+1){
                end = temp;
                break;
            }
            if(temp->next != nullptr){
                temp = temp->next;
                index++;
            }else{
                break;
            }
        }
        if(first == nullptr){
            head = st.top();
            st.pop();
            temp = head;
            
            while(!st.empty()){
                temp->next = st.top();
                st.pop();
                temp = temp->next;
            }
            temp->next = end;
        }else{
            index = 1;
            temp = head;
            while(1){
                if(index == left-1){
                    temp->next = first;
                    index++;
                }else if(index == left){
                    while(!st.empty()){
                        temp->next = st.top();
                        st.pop();
                        temp = temp->next;
                    }
                    temp->next = end;
                       
                    break;                 
                }else{
                    temp = temp->next;
                    index++;
                }
            }
        }
        
        return head;
    }
};