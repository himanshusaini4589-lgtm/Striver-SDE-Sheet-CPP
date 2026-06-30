class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //approach 1 took 1 element space 
        // we can take sum of 1st n natural numbers and subtract from the sum of given nums
        //that element will be the duplicate number;

        //approach 2 took n^2 time complexity
        // we can iterate to a loop and inside loop we can iterate through another loop 
        // in which we can match the ith index with jth index 

        //approach 3 -: space used O(n)
        //sorting and then take idx variable and iterate to nums and match 
        // with i to i+1 if both were equal then duplicate 

        // approach 4 -: space used O(n)
        // we can take set as well in which we insert in the set and if it matches 
        // with another element which already present in set then duplicate

        // approach 5 -: modifiaction of array
        // we can put negetive sign to element index and if we find negetive again 
        // then we can say this number is duplicate 

        //approach 6 -: space O(1) time -: O(n) Linkedlist slow and fast technique
        // when slow and fast meet first time then we can get that there is a cycle 
        // second time we can idetify the duplicate element
        // in the first cycle => slow = l1 + l2
        // and fast will travel = l1 + l2 + nk ( l1 is before cycle distance linear and 
        // l2 is from where l1 ends and up to collision distance and n is number of 
        // cycle and k is length of cycle is k so fast will move the distnce atleast
        // slow and also some cycles. and in the second cycle -:
        // so fast will move double the distance of slow so 
        //  2(l1 + l2) = l1 + l2 + nk
        //  l1 + l2 = nk
        // l1 = nk -l2
        // so in the second cycle a seprate pointer will start from zero and when 
        // it moves l1 then slow also move nk - l2 
        // and which is equal (proved)

        int slow = nums[slow];
        int fast = nums[nums[fast]];
        int p = 0 ;
        while(slow!=fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        while(p!=fast){
            p = nums[p];
            fast = nums[fast];
        }
        return p;
    }
};