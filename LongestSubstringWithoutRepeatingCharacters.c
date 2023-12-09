/*reference: https://leetcode.com/problems/longest-substring-without-repeating-characters/solutions/1006139/C-Super-Simple-Clean-Solution-0ms/ */
/* SUPER THANK ↑↑*/

int lengthOfLongestSubstring(char * s){
    if(*s==NULL) return 0;
    char *head = s;
    char *tail = s;
    int map[128] = {0}; /*ASCII table */
    int counter = 0, res = 0;
    while(*tail){
        if(map[*tail]==0){
            map[*tail] = 1;
            counter++;
            tail++;
        }
        else{
            char *tmp = head;
            while(head!=tail){
                map[*head] = 0;
                head++;
            }
            head = tmp+1;
            tail = head;
            counter = 0;
        }
        if(res<counter) res = counter;
    }
    return res;
}
