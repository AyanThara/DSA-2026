class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start=0;//two pointers start and end 
        int end=numbers.size()-1;
        while(start<end){//run till start>end
            int sum=numbers[start]+numbers[end];//calculate sum
            if(sum==target){//check sum is equal to target if yes 
                return{start+1,end+1};//return start ,end index by adding 1
            }else if(sum>target){//if sum>target
                end--;//end--
            }else{//else 
                start++;//start++
            }
        }
    return{};
    }
};
