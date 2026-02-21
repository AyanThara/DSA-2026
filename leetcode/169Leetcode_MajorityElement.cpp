/*class Solution { //brute force approach complexity o(n2)
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int count = 0;//take a count variable a start with 0
            for (int j = 0; j < n; j++) {
                if (nums[i] == nums[j])//if both the value are same then make count ++
                    count++;
            }
            if (count > n / 2)//if count is greater than array/2 then it is majority element so return that element 
                return nums[i];
        }
        return -1; //else return -1 
    }
};


Dry Run
Input
nums = [2,2,1,1,1,2,2]
Step 1: Sort the array
[1,1,1,2,2,2,2]
n = 7
n/2 = 3
freq = 1
Step 2: Traverse
i	nums[i-1]	nums[i]	Action	freq	Return?
1	1	1	same → freq++	2	No
2	1	1	same → freq++	3	No (not >3)
3	1	2	different → reset freq=1	1	No
4	2	2	same → freq++	2	No
5	2	2	same → freq++	3	No
6	2	2	same → freq++	4	YES → return 2
✅ Output
2
Because it appears 4 times > 3 (n/2)
🧠 One-line explanation for dry run
After sorting, equal numbers come together, so we simply count consecutive duplicates and return the one whose count exceeds n/2.
*/

class Solution {//little optimize approach we are calcualting freq in one loop only
public://time complexity o(nlogn) space o(n)
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());//sort the array so we can go from left to right
        int n = nums.size();
        int freq = 1;   //start freq with 1
        for(int i = 1; i < n; i++){//start from 1 and go till n 
            if(nums[i] == nums[i-1]){//compare i with i-1
                freq++;
                if(freq > n/2) return nums[i];//if freq greater than n/2 then we will return value at i
            } else {
                freq = 1;   // reset for new number
            }
        }
        return nums[0];  
    }
};

