/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteMiddle(struct ListNode* head) {
    struct ListNode *tmp = head;
    int len=0;
    while(tmp!=NULL){
        len++;
        tmp = tmp->next;
    }
    if(len == 1) return NULL;
    len = len/2 - 1; // Let len be the node in front of red node.
    tmp = head;
    while(len){
        len--;
        tmp = tmp->next;
    }
    tmp -> next = tmp->next->next;
    return head;
}