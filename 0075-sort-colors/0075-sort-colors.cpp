class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        // 1st approach time complexity O(3)
        // int noz = 0;
        // int noo = 0;
        // int notw = 0;
        // for(int i = 0 ; i<n ; i++){
        //     if(nums[i]== 0) noz++;
        //     else if(nums[i]== 1) noo++;
        //     else notw++;
        // }
        // for(int i = 0 ; i<n ; i++){
        //     if(i<noz) nums[i] = 0;
        //     else if(i<(noz+noo)) nums[i] = 1;
        //     else nums[i] = 2;
        // }


        //2nd Approach space complexity O(1)
        // dutch national flag algorithm : 
        // 0 to low-1 == 0;
        // low to mid-1 == 1;
        // mid to high-1 === unsorted;
        // high to n-1 == 2;
        int low = 0;
        int mid = 0;
        int high = n-1;
        
        while(mid<=high){
            
           if(nums[mid]==0){
    
                swap(nums[mid],nums[low]);
                mid++;
                low++;

           }
           else if(nums[mid]==1){
            mid++;
           }
           else if(nums[mid]==2){
            swap(nums[mid],nums[high]);
            high--;
           }
        }
    }
};