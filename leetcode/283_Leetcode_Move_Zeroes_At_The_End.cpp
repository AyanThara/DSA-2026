class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index=0;//take a index variable and start with 0
        for(int i=0;i<nums.size();i++){ //run a loop from 0 to size 
             if(nums[i]!=0){ //if the value at the index is non zero
                swap(nums[i],nums[index]);//swap  with index if value is 0 do nothing
                index++;//increment the index
             }
        }
    }
};
/*
Example
Input
[0,1,0,3,12]
Process:
i=1 → swap(1,0) → [1,0,0,3,12]
i=3 → swap(3,0) → [1,3,0,0,12]
i=4 → swap(12,0) → [1,3,12,0,0]
Output:
[1,3,12,0,0]
*/
