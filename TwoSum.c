int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    * returnSize=2;
    static int ans[2];
    for(int i=0; i<=numsSize-1;i++){
        for(int j=i+1;j<=numsSize-1;j++){
            if( (nums[i]+nums[j])==target ){
                ans[0]=i;
                ans[1]=j;
                return ans;
            }
        }
    }
    return 0;
}
