/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int carry=0;
    struct ListNode *res_list = malloc(sizeof(struct ListNode)); 
    struct ListNode *res = res_list;
    int tmp;
    while(l1!=NULL || l2!=NULL){
        if (l1!=NULL && l2!=NULL)tmp = l1->val + l2->val;
        else if(l1==NULL)tmp=l2->val;
        else tmp = l1->val;
        
        if( tmp>=10 && carry==0){
            struct ListNode *newNode = malloc(sizeof(struct ListNode));    
            carry=1;
            newNode->val = tmp - 10;
            newNode->next = NULL;
            res_list->next = newNode;
            res_list = res_list->next;
        }
        else if (tmp>=9 && carry==1){
            struct ListNode *newNode = malloc(sizeof(struct ListNode));    
            carry=1;
            newNode->val = tmp - 10 + 1;
            newNode->next = NULL;
            res_list->next = newNode;
            res_list = res_list->next;
        }
        else if (tmp<10 && carry==0){
            struct ListNode *newNode = malloc(sizeof(struct ListNode));    
            carry=0;
            newNode->val = tmp;
            newNode->next = NULL;
            res_list->next = newNode;
            res_list = res_list->next;          
        }
        else if (tmp<9 && carry==1){
            struct ListNode *newNode = malloc(sizeof(struct ListNode));    
            carry=0;
            newNode->val = tmp + 1; 
            newNode->next = NULL;
            res_list->next = newNode;
            res_list = res_list->next;  
        }
        if (l1!=NULL && l2!=NULL){l1=l1->next;l2=l2->next;}
        else if(l1==NULL)l2=l2->next;
        else l1=l1->next;
    }
    if(l1==NULL && l2==NULL && carry==1){
        struct ListNode *newNode = malloc(sizeof(struct ListNode)); 
        newNode->val=1;
        newNode->next = NULL;
        res_list->next = newNode;
        res_list = res_list->next;                   
    }
    return res->next;
}
