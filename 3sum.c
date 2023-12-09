/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
 
/*bubble sort*/
int* num_sort(int* nums, int numsSize){
    int tmp;
    for(int i=0; i<=numsSize-2;i++){
        for(int j=i+1; j<=numsSize-1;j++){
            if(nums[j]<nums[i]){
                tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            }
        }
    }
    return nums;
}


int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int bsize = 8;
    int** return_list = (int**)malloc(sizeof(int*)*bsize);
    int i=0;
    int tmp1=100001, tmp2=100001;
    nums = num_sort(nums, numsSize);
    int* first = nums;
    while(first+1!=&nums[numsSize-1]){
        int* second = first+1;
        int* third = &nums[numsSize-1];
        while(second<third){
            if(*first + *second + *third == 0){
                if(*second!=tmp1 && *third!=tmp2){
                    return_list[i] = (int*)malloc(sizeof(int)*3);
                    return_list[i][0] = *first;
                    return_list[i][1] = *second;
                    tmp1 = *second;
                    return_list[i][2] = *third;  
                    tmp2 = *third;
                    i++;                 
                }          
                third--;
                second++;
            }
            else if(*first + *second + *third <0){
                second++;
            }
            else if(*first + *second + *third >0){
                third--;
            }
            if(i==bsize){
            bsize *= 2;
            return_list = (int**)realloc(return_list, sizeof(int*)*bsize);
            }
        }
        first++;
        while(*(first-1)==*first && first!= &nums[numsSize-2]) first++;
        tmp1 = 100001;
        tmp2 = 100001;
    }
    *returnSize = i;
    *returnColumnSizes = (int*)malloc(sizeof(int)*(*returnSize));
    for (int j=0; j<(*returnSize); j++) {
        (*returnColumnSizes)[j]=3;
    }
    return return_list;
}
