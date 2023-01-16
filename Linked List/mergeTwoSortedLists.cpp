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
    
    ListNode * magic_box(ListNode* temp1, ListNode* temp2){
        
        if(temp1==nullptr && temp2!=nullptr){
            return temp2;
        }
        else if(temp2==nullptr && temp1!=nullptr){
            return temp1;
        }
        else if(temp2==nullptr && temp1==nullptr){
            return nullptr;
        }
            
        ListNode * temp=nullptr;
        
        if(temp1->val<=temp2->val){
            temp=temp1;
            temp->next=magic_box(temp1->next,temp2);
        }
        else{
            temp=temp2;
            temp->next=magic_box(temp1,temp2->next);
        }
        return temp;
    }
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        return magic_box(list1,list2);
    }
};

/*
class Solution {
public:
    
    void addAdditionalData(ListNode* list1, ListNode* temp_ans){
        
        while(list1!=nullptr){
            temp_ans->next=new ListNode(list1->val,nullptr);
            temp_ans=temp_ans->next;
            list1=list1->next;
        }
    }
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        
        ListNode * first;
        ListNode * temp_ans;
        
        while(list1!=nullptr && list2!=nullptr){
            
            if(list1->val>=list2->val){
                if(first==nullptr){
                    temp_ans=list1;
                    //temp_ans=new ListNode(list1->val,nullptr);
                    first=temp_ans;
                }
                else{
                    temp_ans->next=list1;
                    //temp_ans->next==new  ListNode(list1->val,nullptr);
                    temp_ans=temp_ans->next;
                }
                list1=list1->next;
            }
            else{
                if(first==nullptr){
                    temp_ans=list2;
                    //temp_ans=new ListNode(list2->val,nullptr);
                    first=temp_ans;
                }
                else{
                    temp_ans=list2;
                    //temp_ans->next=new ListNode(list2->val,nullptr);
                    temp_ans=temp_ans->next;
                }
                list2=list2->next;
            }
        }
        
        if(list1!=nullptr){
            while(list1!=nullptr){
                temp_ans=list1;
                //temp_ans->next=new ListNode(list1->val,nullptr);
                temp_ans=temp_ans->next;
                list1=list1->next;
            }
            //addAdditionalData(list1, temp_ans);
        }
        else{
            while(list2!=nullptr){
                temp_ans=list2;
                //temp_ans->next=new ListNode(list2->val,nullptr);
                temp_ans=temp_ans->next;
                list2=list2->next;
            }
            //addAdditionalData(list2, temp_ans);
        }
        
        return first;
    }
};
*/