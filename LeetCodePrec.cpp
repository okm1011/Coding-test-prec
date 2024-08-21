/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL)return NULL;
        Node* copy_head = new Node(head->val);
        Node* dummy_temp = copy_head;
        Node* temp = head;
        map<Node* , int> m_ch;
        int cnt = 0;
        m_ch.insert({temp,cnt});
        // head check

        while(temp->next != NULL){
            Node* next_node = new Node(temp->next->val);
            cnt++;
            m_ch.insert({temp->next,cnt});
            dummy_temp->next = next_node;
            dummy_temp = next_node;
            temp = temp->next;
        }
        dummy_temp->next = NULL;


        
        int turn = 0;
        dummy_temp = copy_head;
        temp = head;
        while(turn <= cnt){
            if(temp->random != NULL){
                int index = m_ch[temp->random];
                Node* target = copy_head;
                for(int i = 0 ; i<index ; i++){
                    target = target->next;
                }
                dummy_temp->random = target;
            }else{
                dummy_temp->random = NULL;
            }
            temp = temp->next;
            dummy_temp = dummy_temp -> next;
            turn++;
        }





        return copy_head;
    }
};