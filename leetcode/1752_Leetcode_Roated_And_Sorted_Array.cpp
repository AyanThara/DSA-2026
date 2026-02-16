class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();//take a variable n and make it till nums.size
        int count = 0;//start count with 0 
        for(int i = 0; i < n; i++){//run till end
            if(nums[i] > nums[(i+1)%n]){//check if the condition is fulfilled exactly 1s
                count++;//increase count
            }
        }
        return count <=1 ; //returing count if=1
    }
};
