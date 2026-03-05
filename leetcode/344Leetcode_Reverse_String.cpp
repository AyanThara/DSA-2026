/*Reverse String (LeetCode 344)Reversing a string means placing the last character at the beginning and the first character at the end. Instead of using extra space to create a new string, we can reverse it by swapping characters from both ends moving toward the center.
    Approach
We use the Two Pointer Technique:
One pointer starts from the beginning.
Another pointer starts from the end.
Swap both characters and move inward:
Increment the start pointer
Decrement the end pointer
Repeat until both pointers meet.
This reverses the string in-place without using extra memory.

⏱️ Complexity
Time Complexity: O(n)
Space Complexity: O(1)

🔹 Key Concept Used
Two Pointer Technique
In-place Swapping
This is the most optimal solution because it reverses the string without using extra space. */


class Solution {
public:
    void reverseString(vector<char>& s) { 
        reverse(s.begin(),s.end());  //using in built reverse function 
    }
};

/*class Solution {//simple two pointer approach 
public:
    void reverseString(vector<char>& s) {
        int start=0;//intilize it with 0 
        int end=s.size()-1;// initlize it with n-1 index
        while(start<end){//while start is less than end 
            swap(s[start],s[end]);//swap start and end 
            start++;//inrement start
            end--;//decrement end
        }
    }
};*/
