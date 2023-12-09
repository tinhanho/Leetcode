/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *reverse(struct ListNode *head){
  struct ListNode *tmp = NULL;
  while(head!=NULL){
    struct ListNode *new = malloc(sizeof(struct ListNode));
    new -> val = head -> val;
    new -> next = tmp;
    tmp = new;
    head = head->next;
  } 
  return tmp;
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){ 
  bool flag1 = true;
  bool flag2 = true;
  int min;
  struct ListNode *head = NULL;
  if(list1 == NULL && list2 == NULL) return list1;
  else if(list1 == NULL) return list2;
  else if(list2 == NULL) return list1;
  while(flag1 || flag2){ 
    if(flag1==false){
      min = list2->val;
      list2 = list2->next;      
    }
    else if(flag2==false){
      min = list1->val;
      list1 = list1->next;
    }
    else if(list1->val <= list2->val){
      min = list1->val;
      list1 = list1->next;
    }
    else if(list1->val > list2->val){
      min = list2->val;
      list2 = list2->next;    
    }
    if(list1==NULL) flag1=false;
    if(list2==NULL) flag2=false;
    struct ListNode *tmp = malloc(sizeof(struct ListNode));
    tmp->val = min;
    tmp->next = head;
    head = tmp;
  }
  struct ListNode *return_list = reverse(head);
  return return_list;
}
