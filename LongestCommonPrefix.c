char * longestCommonPrefix(char ** strs, int strsSize){
    /*note we only care about the prefix */
    if(strsSize==1) return strs[0];
    char *tmp = strs[0];
    char *res = tmp;
    int j=0, flag=0;
    while(1){
        for(int i=0; i<=strsSize-1;i++){
            if(strs[i][j]!=*tmp || strs[i][j]==NULL) flag = 1;
            if(flag==1) break;
        }
        if(flag==1) break;
        tmp++;
        j++;
    }
    *tmp = '\0';
    return res;
}
