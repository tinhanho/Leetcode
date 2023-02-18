bool isPalindrome(int x){
    int len=1, ct=1;
    bool res = true;
    if(x<0) return false;
    while(x/ct>=10){
        x/(ct*10);
        ct *=10;
        len ++;
    }
    int *arr = malloc(sizeof(int)*(len));
    int tmp = len;
    while(tmp!=0){
        arr[tmp-1] = x%10;
        x = x/10;
        tmp--;
    }
    for(int i=0;i<=len-1;i++){
        int j = len-1-i;
        if(arr[i]!=arr[j]){
            res = false;
            break;
        } 
    }
    return res;
}
