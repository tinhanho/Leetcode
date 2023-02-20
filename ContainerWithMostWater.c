/*Strategy:Greedy algorithm, use two pointers, cacaulating the value, moving 1 each time and take the most value*/
int min(int *x, int *y){
    if(*x<=*y) return *x;
    else return *y;
}

int maxArea(int* height, int heightSize){
    int *tmp=height;
    int res=0;
    while(heightSize!=1){
        heightSize--;
        tmp++;
    }
    int *tail=tmp;
    int *head=height;
    while(head!=tail){
        int ht = min(head, tail);
        int ans = ht * (tail-head);
        if(res<ans) res = ans;
        if(ht==*head) head++;
        else tail--;
    }
    return res;
}
