bool isempty(char *stack, char *head){
    if(stack==head) return true;
    else return false;
}
void push(char *s, char *head){
    *head = *s; 
}

bool isValid(char * s){
    char *tmp = s;
    int len = 0;
    while(*tmp){
        len++;
        tmp++;
    }
    char *stack = (char*)malloc(sizeof(char)*(len+1));
    char *head = stack;
    while(*s){
        if(*s=='(' || *s=='{' || *s=='['){
            push(s, head);
            head++;     
            s++;
        }
        else if((*s==')'||*s=='}'||*s==']')&&head==stack) return false;
        else if(*s==')'&&*(head-1)=='('){  
            head--;       
            s++;
        }
        else if(*s=='}'&&*(head-1)=='{'){
            head--;
            s++;
        }
        else if(*s==']'&&*(head-1)=='['){
            head--;            
            s++;
        }
        else return false;
    }
    return isempty(stack, head);
}
