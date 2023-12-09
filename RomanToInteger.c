int romanToInt(char * s){
    /*note: 1~3: I~III; 4~8: IV~VIII; 9~10: IX~X*/
   int res=0;
   int counter=0;
   while(*s){
        if(*s=='M') res+=1000;
        else if(*s=='C'){
            if(*(s+1)=='M'){
                res+=900;
                s++;
            }
            else if(*(s+1)=='D'){
                res+=400;
                s++;
            }
            else res+=100;            
        }
        else if(*s=='D'){
            while(*(s+1)=='C'){
               s++;
               counter++;
            }
            res=res+500+counter*100;
        }
        else if(*s=='X'){
            if(*(s+1)=='C'){
                res+=90;
                s++;
            }
            else if(*(s+1)=='L'){
                res+=40;
                s++;
            }
            else{
                res+=10;
            }
        }
        else if(*s=='L'){
            while(*(s+1)=='X'){
               s++;
               counter++;
            }
            res=res+50+counter*10;            
        }        
        else if(*s=='I'){
            if(*(s+1)=='X'){
                res+=9;
                s++;
            }
            else if(*(s+1)=='V'){
                res+=4;
                s++;
            }
            else{
                res+=1;
            }
        }
        else if(*s=='V'){
            while(*(s+1)=='I'){
               s++;
               counter++;
            }
            res=res+5+counter*1;              
        }
        counter=0;
        s++;
    } 
    return res;
}
