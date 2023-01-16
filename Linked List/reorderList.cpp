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
    void reorderList(ListNode* head) {
        stack<ListNode*> st;
        queue<ListNode*>q;
        ListNode* temp=head;
        
        int cnt=0;
        while(temp!=nullptr){
            st.push(temp);
            q.push(temp);
            temp=temp->next;
            cnt++;
        }
        int mid=cnt%2==0?cnt/2:(cnt/2)+1;
       // cout<<cnt<<endl;
        
        ListNode* ans=nullptr;
        
        for(int i=1;i<=mid;i++){
            ListNode* left=q.front();
            ListNode* right=st.top();
            
            if(i==mid && cnt%2==1){
                if(ans==nullptr){
                    ans=left;
                    ans->next=nullptr;
                }
                else{
                    ans->next=left;
                    ans=left;
                    ans->next=nullptr;
                }
                break;
            }
            q.pop();
            st.pop();
            if(ans==nullptr){
                ans=left;
                ans->next=right;
                ans=right;
                
            }else{
                ans->next=left;
                ans=left;
                ans->next=right;
                ans=right;
                
            }
            if(i==mid){
                    ans->next=nullptr;
                }
        }
        
    }
};