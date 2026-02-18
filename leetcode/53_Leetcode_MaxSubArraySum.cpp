class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();//take a variable and intialize with nums.size
        int currsum=0;//take currsum as 0
        int maxsum=INT_MIN;//and max sum as -infinite
        for(int i=0;i<n;i++){//run the loop till n 
            currsum+=nums[i];//update currsum with nums[i]
            maxsum=max(currsum,maxsum);//check max of currsum and maxsum
            if(currsum<0)//if currsum id less than 0 reintilze it with 0
            currsum=0;
        }
    return maxsum;//return max sum
    }
};


/*
Example Input
nums = [-2,1,-3,4,-1,2,1,-5,4]

 Initial values
currentsum = -2
maxsum = -2

Step-by-step Dry Run
i	nums[i]	currentsum calculation	currentsum	maxsum
0	-2	start value	-2	-2
1	1	max(1, -2+1=-1)	1	1
2	-3	max(-3, 1-3=-2)	-2	1
3	4	max(4, -2+4=2)	4	4
4	-1	max(-1, 4-1=3)	3	4
5	2	max(2, 3+2=5)	5	5
6	1	max(1, 5+1=6)	6	6
7	-5	max(-5, 6-5=1)	1	6
8	4	max(4, 1+4=5)	5	6
 Final Answer
maxsum = 6

 Maximum subarray = [4,-1,2,1]
 Sum = 6
 What’s happening intuitively

Negative running sum? → restart from current number

Positive running sum? → extend subarray

At index 3:

previous sum = -2
starting new from 4 is better → choose 4
*/

That’s the core Kadane insight.
