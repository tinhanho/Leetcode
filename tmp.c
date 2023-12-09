/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){ 
    //Record whether it is valid for the linked-lists
    bool *vd = malloc(sizeof(bool)*listsSize);
    for(int k=0; k<=listsSize-1;k++) vd[k] = true;
    int i = listsSize-1;
    int i_s;
    int min = 10000;
    bool flag;
    while(flag==true){
        for(int k=0;k<=listSize-1;k++){
            if(vd[k]==true){
                flag = true;
                break;
            }
            flag=false;
        }
        while(i!=-1){
            if(lists[i]->val < min && vd[i]!=false){
                min = lists[i] ->val;
                i_s = i;
            }
            i--;
        }
        lists[i_s] = lists[i_s] -> next;
        if(lists[i_s] == NULL) vd[i]= false;
        printf("%d ", min);
        i=0;
    }
    return 0;
}
