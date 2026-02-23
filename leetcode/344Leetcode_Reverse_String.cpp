class Solution {//simple two pointer approach swaping start and end 
public:
    void reverseString(vector<char>& s) {
        int start=0;//start with 0
        int end=s.size()-1;//end with last index
        while(start<end){//run the loop till this condition
            swap(s[start],s[end]);//swap start and end
            start++;//increment
            end--;//decrement
        }
    }
};
