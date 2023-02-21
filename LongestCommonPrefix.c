char * longestCommonPrefix(char ** strs, int strsSize){
    /*note we only care about the prefix */
    if(strsSize==1) return strs[0];
    char *res = malloc(sizeof(char)*(200+1)); /* strs[i].length<=200 */
    char *res_head = res;
    char *tmp = strs[0];
    int j=0, flag=0;
    while(1){
        for(int i=0; i<=strsSize-1;i++){
            if(strs[i][j]!=*tmp || strs[i][j]==NULL){
                flag = 1;
            }
        }
        if(flag==1) break;
        *res=*tmp;
        tmp++;
        j++;
        res++;
    }
    *res = '\0';
    return res_head;
}
