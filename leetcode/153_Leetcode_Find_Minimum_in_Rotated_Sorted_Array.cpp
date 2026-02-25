/*LeetCode 153 — Minimum in Rotated Sorted Array
Given a sorted array that has been rotated between 1 and n times, find the minimum element in O(log n) time.

Example:

Input:  [3,4,5,1,2]
Output: 1
 Intuition

In a rotated sorted array, one half is always sorted.

By comparing the middle element with the last element:

If nums[mid] > nums[end], the minimum lies in the right half

Otherwise, the minimum lies in the left half (including mid)

We shrink the search space using binary search until only one element remains.

⚙️ Approach (Step-by-Step)

Initialize:

start = 0
end = n - 1

While start < end:

Find mid

If nums[mid] > nums[end]
→ move right → start = mid + 1

Else
→ move left → end = mid

When loop ends:

start == end

That index contains the minimum.

Return:

nums[start]
🧪 Dry Run

Array:

[3,4,5,1,2]

Step 1:

start=0 end=4 mid=2 → nums[mid]=5 > nums[end]=2
→ start=3

Step 2:

start=3 end=4 mid=3 → nums[mid]=1 <= nums[end]=2
→ end=3

Step 3:

start=3 end=3 → stop
answer = nums[3] = 1

Complexity
Time: O(log n)
Space: O(1)

*/
class Solution {//use binary search o(log n) time complexity and space complexity is o(1)
public:
    int findMin(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
        while(start<end){//run the loop till < only
            int mid=start+(end-start)/2;
        if(nums[mid]>=nums[end]){//if this condition is true then the smallest element is in right side so take start towards the smallest element 
            start=mid+1;
        }else{//else the smallest element is in left side so do end=mid not mid-1 because doing so will result in wrong answer as mid can also be the smallest element 
            end=mid;
        }
    }
    return nums[end];//return start or end
    }
};




     
