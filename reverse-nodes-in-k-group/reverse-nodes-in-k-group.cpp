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

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *x=NULL,*y=head,*prevhead1=NULL,*prevhead2=NULL;
        if(head==NULL || head->next==NULL){
            return head;
        }
        int num=0;
        while(y!=NULL){
            num++;
            y=y->next;
        }
        y=head;
        int it=num/k;
        ListNode *head1=NULL;
        for(int i=0;i<it;i++){
            ListNode *z;
            prevhead2=prevhead1;
            prevhead1=y;
            
            for(int j=0;j<k;j++){
                z=y->next;
                y->next=x;
                x=y;
                y=z;
            }
             if(i==0){
                head1=x;
            }
            else{
                prevhead2->next=x;
               
            }
        
            x=NULL;
            y=z;
        }
        prevhead1->next=y;
        
 
        return head1;
    }
};