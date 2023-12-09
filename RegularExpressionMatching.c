/*This algorithm uses DP to solve */
/*Note that "A*" can stand for zero of preceding, that is, NULL string*/
bool isMatch(char * s, char * p){
    /*determine length of s and p */
    int len_s = 0, len_p = 0;
    char *tmp = s;
    while(*tmp){
        len_s++;
        tmp++;
    }
    tmp = p;
    while(*tmp){
        len_p++;
        tmp++;
    }
    /*DP starts here */
    bool **arr = malloc(sizeof(bool*)*(len_s+1));
    for(int i=0;i<=len_s;i++) arr[i]=malloc(sizeof(bool)*(len_p+1));
    /*initialization*/
    for(int i=0;i<=len_s;i++){
        for(int j=0;j<=len_p;j++){
            arr[i][j] = false;
        }
    }    
    /* set boundary value */
    arr[0][0] = true;
    /* NULL vs. X*X*X*X*... and note that array[0][0] is NULL for both s and p*/
    for(int j=2;j<=len_p && p[j-1]=='*';j+=2) arr[0][j] = true;
    /* when j=0, which means p is NULL, then all the matches except for arr[0][0] is false obviously*/
    for(int i=1;i<=len_s;i++) arr[i][0] = false;
    /*recursive relation */
    for(int i=1;i<=len_s;i++){
        for(int j=1;j<=len_p;j++){
            int s_ind = i-1;
            int p_ind = j-1;
            if(s[s_ind]==p[p_ind] || p[p_ind]=='.') arr[i][j] = arr[i-1][j-1];
            else if(p[j-1]=='*'){
                arr[i][j] = arr[i][j-2] || ((s[s_ind] == p[p_ind-1] || p[p_ind-1] == '.') && arr[i-1][j]);
            }
        }
    }
    return arr[len_s][len_p];
}
