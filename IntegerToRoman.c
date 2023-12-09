char * intToRoman(int num){
    /*note:1~3 is I~III; 4~8 is IV~VIII; 9~10 is IX~X. Thus, handle IX IV is important*/   
    char *res = malloc(sizeof(char)*16); /*"MMMDCCCLXXXVIII" is one of the longest string */
    char *res_head=res;
    while(num!=0){
        if(num>=1000){
            *res='M';
            num=num-1000;
        }
        else if(num<1000 && num>=900){
            *res='C';
            res++;
            *res='M';
            num=num-900;
        }
        else if(num<900 && num>=500){
            *res='D';
            num=num-500;
        }
        else if(num<500 && num>=400){
            *res='C';
            *res++;
            *res='D';
            num=num-400;
        }
        else if(num<400 && num>=100){
            *res='C';
            num=num-100;
        }
        else if(num<100 && num>=90){
            *res='X';
            res++;
            *res='C';
            num=num-90;
        }
        else if(num<90 && num>=50){
            *res='L';
            num=num-50;
        }
        else if(num<50 && num>=40){
            *res='X';
            res++;
            *res='L';
            num=num-40;
        }
        else if(num<40 && num>=10){
            *res='X';
            num=num-10;
        }
        else if(num<10 && num>=9){
            *res='I';
            res++;
            *res='X';
            num=num-9;
        }
        else if(num<9 && num>=5){
            *res='V';
            num=num-5;
        }
        else if(num<5 && num>=4){
            *res='I';
            res++;
            *res='V';
            num=num-4;
        }
        else{
            *res='I';
            num=num-1;
        }
        res++;
    }
    *res = '\0';
    return res_head;
}
