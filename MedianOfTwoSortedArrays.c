/* Note that you cannot access the memory address bigger than tail of the array */
/* or it will return overflow from the compiler*/
/* it also means that the end of the array is not NULL*/

int *merge(int *nums1, int *nums2, int s1, int s2){
    int ct1 = 0, ct2 = 0, flag1 = 0, flag2 = 0; 
    if(s1 == 0) flag2 = 1;
    if(s2 == 0) flag1 = 1;
    int size = s1 + s2;
    int *new = malloc(sizeof(int)*(size));
    
    for(int i=0; i<=size-1; i++){
        if(flag1==1){
            new[i] = nums1[ct1];
            ct1 ++;
        }
        else if(flag2==1){
            new[i] = nums2[ct2];
            ct2 ++;
        }
        else if(nums1[ct1]<=nums2[ct2] && ct1!=s1-1){
            new[i] = nums1[ct1];
            ct1 ++;
        }
        else if(nums1[ct1]>nums2[ct2] && ct2!=s2-1){
            new[i] = nums2[ct2];
            ct2 ++;
        }
        else if(nums1[ct1]<=nums2[ct2] && ct1==s1-1){
            new[i] = nums1[ct1];
            flag2 = 1;
        }
        else if(nums1[ct1]>nums2[ct2] && ct2==s2-1){
            new[i] = nums2[ct2];
            flag1 = 1;
        }
    }
    return new;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int *new = merge(nums1, nums2, nums1Size, nums2Size);
    int size = nums1Size + nums2Size;
    double res;
    if(size%2 == 0){
        double tmp = new[size/2 - 1] + new[size/2];
        res = tmp/2;
    }
    else res = new[size/2];
    return res;
}
