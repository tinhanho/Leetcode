/*This algorithm use pure Dynamic Programming, time complexity is O(n^2)*/
/*Note that using Manacher’s algorithm could reach O(n) time*/
char * longestPalindrome(char * s){
    char *tmp = s;
    char *res;
    int size = 0, k = 0;
    int ans_i, ans_j, i, j;
    while(*tmp){
        size++;
        tmp++;
    }
    if(size ==1) return s;

    int m[size][size];

    /*initialization is important !!!!!*/
    for(i=0;i<=size-1;i++){
        for(j=0;j<=size-1;j++){
            m[i][j]=0;
        }
    }
    while(k!=size){
        for(i=0; i<=size-1-k; i++){    
            j = i + k;        
            if(i==j){
                m[i][j]=1;
                ans_i = i;
                ans_j = j;            
            }
            else if(s[i]==s[j] && j-1==i){
                m[i][j] = 1;
                ans_i = i;
                ans_j = j;
            }
            else if(s[i]==s[j] && m[i+1][j-1]==1){
                m[i][j] = 1;
                ans_i = i;
                ans_j = j;
            }      
        }
        k++;
    }
    k = 0;
    res = malloc(sizeof(char)*(ans_j-ans_i+2));
    for(int m=ans_i; m<=ans_j;m++){
        res[k]=s[m];
        k++;
    }
    res[k]='\0'; /*Important here */
    return res;
}
