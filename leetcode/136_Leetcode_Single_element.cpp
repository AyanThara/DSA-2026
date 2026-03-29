/* Single Number using XOR (O(n) Time, O(1) Space)
In the array, every element appears twice except one. Using XOR:
a ^ a = 0
0 ^ x = x
So, all duplicates cancel out, leaving the unique number.
 Approach
Initialize ans = 0
Traverse the array
XOR each element with ans
Final value of ans is the answer
Dry Run
Input:
nums = [2, 2, 1]
Step-by-step:
ans = 0

ans = 0 ^ 2 = 2
ans = 2 ^ 2 = 0
ans = 0 ^ 1 = 1
Final Answer: 1
 Complexity
Time: O(n)
Space: O(1*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int x : nums)
            ans ^= x;
        return ans;
    }
};
