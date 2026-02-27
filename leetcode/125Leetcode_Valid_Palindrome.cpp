/*🔹 Problem

Given a string s, return true if it is a palindrome, or false otherwise.

A valid palindrome:

Ignores special characters

Ignores spaces

Case insensitive

🔹 Intuition

The string may contain spaces, symbols, and uppercase letters which should not affect palindrome checking. So first we remove non-alphanumeric characters and convert uppercase letters into lowercase to make comparison easier.

🔹 Approach

We create a new string that stores only letters and digits. While adding characters, uppercase letters are converted into lowercase using the 'A' → 'a' conversion method.

After building the cleaned string, we apply the two-pointer technique:

Start pointer from beginning

End pointer from last

If characters mismatch → not palindrome
If all match → palindrome


🔹 Complexity;
Time Complexity:O(n)
Space Complexity:o(n)

🔹 Key Concept Used
String Filtering
ASCII Conversion
Two Pointer Technique */

class Solution {
public:
    bool isPalindrome(string s) {
        string clean = "";//creating an empty clean string 
        for(char c : s) {
            if(isalnum(c)) {//is alphanumberic bulit in cpp function that check if it is numberic or alphabet if yes return true else false
                if(c >= 'A' && c <= 'Z') {//the alphabet is between A and Z then we need to convert to lower case so
                    clean += (c - 'A' + 'a');   //remove -A from that alphabet and + a 
                }//A=65... a=97 according to ur formula B=66-65=1+a->=98 i.e b=98 true 
                else {
                    clean += c;//if already lower case then add it in clean 
                }
            }
        }
        int start = 0;//simple two pointer approach 
        int end = clean.size() - 1;
        while(start < end) {
            if(clean[start] != clean[end])//if start!=end return false not a palindrome 
                return false;
            start++;//increment start
            end--;//decrement end
        }
        return true;//if it reaches here it is palindrome
    }
};
