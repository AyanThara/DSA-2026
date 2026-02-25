/* LeetCode 34 — Find First and Last Position of Element in Sorted Array Problem
Given a sorted array nums and a target value, return the first and last position of the target.
If the target is not found, return [-1, -1].
Example:
Input:  nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
💡 Intuition

Since the array is sorted, we can use binary search.

When we find the target at mid, it may not be the first or last occurrence because duplicates can exist.

So:

For the first position, store index and continue searching left

For the last position, store index and continue searching right

This means we perform two binary searches.

⚙️ Approach (Step-by-Step)

Create function firstPos():

If nums[mid] == target

store mid

move left → end = mid - 1

Create function lastPos():

If nums[mid] == target

store mid

move right → start = mid + 1

Call both functions and return:

{firstIndex, lastIndex}
🧪 Dry Run

Array:

nums = [1,2,2,2,3], target = 2

Finding first position

start=0 end=4 mid=2 → nums[2]=2 → store=2 → move left → end=1
start=0 end=1 mid=0 → nums[0]=1 < 2 → start=1
start=1 end=1 mid=1 → nums[1]=2 → store=1 → end=0 → stop
First = 1

Finding last position

start=0 end=4 mid=2 → nums[2]=2 → store=2 → start=3
start=3 end=4 mid=3 → nums[3]=2 → store=3 → start=4
start=4 end=4 mid=4 → nums[4]=3 > 2 → end=3 → stop
Last = 3

Result:
[1,3]

⏱ Complexity
Time: O(log n)
(two binary searches)
Space: O(1)

*/


class Solution {//create two function one for first occurance and another for last occurance and return both in a vector 
public:
    int firstPos(vector<int>& nums, int target){//first occurance function 
        int start = 0, end = nums.size()-1;
        int ans = -1;//for storing the target
        while(start <= end){
            int mid = start + (end-start)/2;
            if(nums[mid] < target){
                start = mid + 1;
            }
            else if(nums[mid] > target){
                end = mid - 1;
            }
            else{
                ans = mid;//if nums[mid]==target store in array and move the end back 
                end = mid - 1;
            }
        }
        return ans;//return ans
    }
    int lastposition(vector<int>& nums, int target){//function for last occurance 
        int start = 0, end = nums.size()-1;
        int ans = -1;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(nums[mid] < target){
                start = mid + 1;
            }
            else if(nums[mid] > target){
                end = mid - 1;
            }
            else{
                ans = mid;//store if nums[mid]==target
                start = mid + 1;//move the start forward
            }
        }
        return ans;//return ans
    }
    vector<int> searchRange(vector<int>& nums, int target){//create the fuunction 
        vector<int> result;//create the result vector 
        result.push_back(firstPos(nums,target));    //add the first occurance 
        result.push_back(lastposition(nums,target));//add last occurance 
        return result;//return the final result
    }
};
