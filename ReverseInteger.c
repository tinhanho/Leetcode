#define INT_MAX 2147483647
#define INT_MIN -2147483648

int reverse(int x){
    int res = 0;
    while(x!=0){
        if(res>INT_MAX/10 || (res==INT_MAX/10 && x/10>7) || res<INT_MIN/10 || ( res==INT_MIN && x/10<8) ) return 0;
        else{
            res = res * 10 + x % 10;
            x = x/10;
        }
    } 
    return res;
}
