class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>temp(n);//create a nums vector 
        for(int i=0;i<n;i++){//run the loop from start to end
            temp[(i+k)%n]=nums[i]; 
        }
        nums=temp;//copy temp into nums
    }
};


/*n
input 
ums = [1,2,3,4,5,6,7]
k = 3
n = 7
k = k % n = 3

newIndex = (i + k) % n
Step by step solution

| i | nums[i] | newIndex = (i+3)%7 | temp after placing |
| - | ------- | ------------------ | ------------------ |
| 0 | 1       | 3                  | [*,*,*,1,*,*,*]    |
| 1 | 2       | 4                  | [*,*,*,1,2,*,_]    |
| 2 | 3       | 5                  | [*,*,*,1,2,3,*]    |
| 3 | 4       | 6                  | [*,*,_,1,2,3,4]    |
| 4 | 5       | 0                  | [5,*,*,1,2,3,4]    |
| 5 | 6       | 1                  | [5,6,_,1,2,3,4]    |
| 6 | 7       | 2                  | [5,6,7,1,2,3,4]    |

output
[5,6,7,1,2,3,4]

*/
