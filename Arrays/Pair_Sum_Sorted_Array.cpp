/*class Solution {//brute force 
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(nums[i] + nums[j] == target){
                    return {i, j};
                }
            }
        }

        return {};
    }
};*/


class Solution {//when array is sorted
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size() - 1;

        while(i < j){
            int sum = nums[i] + nums[j];

            if(sum == target){
                return {i, j};   // indices
            }
            else if(sum < target){
                i++;   // need bigger sum
            }
            else{
                j--;   // need smaller sum
            }
        }

        return {};
    }
};
