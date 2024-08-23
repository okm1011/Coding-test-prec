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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        stack<ListNode*>st;
        ListNode*temp = head;
        while(temp->next != nullptr){
            st.push(temp);
            temp= temp -> next;
        }
        st.push(temp);
        if(st.size() == 1)return nullptr;

        int cnt = 0;
        ListNode*prev = NULL;
        ListNode*cur = NULL;
        while(cnt < n && !st.empty()){
            
            if(cur == NULL){
                cur = st.top();
                st.pop();
                cnt++;
            }else{
                prev = cur;
                cur = st.top();
                st.pop();
                cnt++;
            }
        }
        if(st.empty()){
            return prev;
        }else{
            temp = st.top();
            
            temp -> next = prev;
            return head;
        }

        

    }
};