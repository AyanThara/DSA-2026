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




#include<iostream>
#include<vector>
using namespace std;

vector<int> pairSum(vector<int> arr, int target){

    int left = 0;
    int right = arr.size() - 1;

    while(left < right){

        int sum = arr[left] + arr[right];

        if(sum == target){
            return {left, right};
        }

        else if(sum < target){
            left++;
        }

        else{
            right--;
        }
    }

    return {};
}

int main(){

    vector<int> arr = {1,2,3,4,5};
    int target = 5;

    vector<int> result = pairSum(arr, target);

    cout << result[0] << " " << result[1];

    return 0;
}
