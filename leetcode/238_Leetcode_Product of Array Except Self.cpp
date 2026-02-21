/*📦 Product of Array Except Self (LeetCode 238)
🧩 Problem

Given an integer array nums, return an array answer such that:

answer[i] = product of all elements of nums except nums[i]

Must run in O(n) time

No division allowed

💡 Intuition

For every index, we need:

product_before_i × product_after_i

Instead of recomputing products repeatedly:

Store prefix product while moving left → right

Multiply suffix product while moving right → left

We reuse the answer array to store prefix values, avoiding extra space.

🛠 Approach
✅ Step 1 — Prefix pass

Keep prefix = 1

Store prefix in ans[i]

Update prefix *= nums[i]

✅ Step 2 — Suffix pass

Keep suffix = 1

Multiply ans[i] *= suffix

Update suffix *= nums[i]

🔎 Example
Input:  nums = [1,2,3,4]
Output: [24,12,8,6]

Explanation:

Index	Product except self
0	2×3×4 = 24
1	1×3×4 = 12
2	1×2×4 = 8
3	1×2×3 = 6
🧪 Dry Run
Prefix pass
i	prefix before	ans[i]	prefix after
0	1	1	1
1	1	1	2
2	2	2	6
3	6	6	24
ans = [1,1,2,6]
Suffix pass
i	suffix before	ans[i] after multiply	suffix after
3	1	6	4
2	4	8	12
1	12	12	24
0	24	24	24
Final ans = [24,12,8,6]
⏱ Complexity
Type	Complexity
Time	O(n)
Extra Space	O(1) (output array not counted)

Store prefix in answer array and multiply suffix in reverse traversal to achieve O(n) time and O(1) space.*/



/*class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       int n=nums.size();
        vector<int>ans(n,1);//intilize a vector
        for(int i=0;i<n;i++){//start and run till n outter loop
            for(int j=0;j<n;j++){//run inner loop till n 
               if(i!=j) //if i==j then skip adding the product else add the prodcut in all other cases 
              ans[i]*=nums[j];//store in arr[i] vector 
               }
            }
        }
        return ans;//return the vector
    }
};
//o(n2) time complexity 
//space complexity 0(n) 


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n,1), suffix(n,1), ans(n);//create three vector suffix prefix and ans 
        // build prefix
        for(int i=1;i<n;i++){//run the loop and calculate the prefix 
            prefix[i] = prefix[i-1] * nums[i-1];//prefix =prefix of i-1 and * that num[i-1]number
        }
        // build suffix
        for(int i=n-2;i>=0;i--){//runt the loop and calculate the suvfix
            suffix[i] = suffix[i+1] * nums[i+1];//suffix =suffix of i+1 and * that num[i+1]number
        }
        // build answer
        for(int i=0;i<n;i++){
            ans[i] = prefix[i] * suffix[i];//multiply both prefox and suffix vector and store in ans vector 
        }
        return ans;//return ans vector
    }
}; //time complexity o(n)
   //space complexity o(n)

*/


/*class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       int n=nums.size();
        vector<int>ans(n,1);//intilize a vector
        for(int i=0;i<n;i++){//start and run till n outter loop
            for(int j=0;j<n;j++){//run inner loop till n 
               if(i!=j) //if i==j then skip adding the product else add the prodcut in all other cases 
              ans[i]*=nums[j];//store in arr[i] vector 
               }
            }
        }
        return ans;//return the vector
    }
};
//o(n2) time complexity 
//space complexity 0(n) 


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n,1), suffix(n,1), ans(n);//create three vector suffix prefix and ans 
        // build prefix
        for(int i=1;i<n;i++){//run the loop and calculate the prefix 
            prefix[i] = prefix[i-1] * nums[i-1];//prefix =prefix of i-1 and * that num[i-1]number
        }
        // build suffix
        for(int i=n-2;i>=0;i--){//runt the loop and calculate the suvfix
            suffix[i] = suffix[i+1] * nums[i+1];//suffix =suffix of i+1 and * that num[i+1]number
        }
        // build answer
        for(int i=0;i<n;i++){
            ans[i] = prefix[i] * suffix[i];//multiply both prefox and suffix vector and store in ans vector 
        }
        return ans;//return ans vector
    }
}; //time complexity o(n)
   //space complexity o(n)

*/


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,1);
        //  store prefix products
        int prefix = 1;
        for(int i=0;i<n;i++){
            ans[i] = prefix;
            prefix *= nums[i];
        }
        // multiply suffix products
        int suffix = 1;//start with 1 
        for(int i=n-1;i>=0;i--){//reverse loop
            ans[i] *= suffix;//multiply directly in ans vector
            suffix *= nums[i];
        }
        return ans;//return and
    }
}; //time complexity o(n) 
//space complexity o(1)
