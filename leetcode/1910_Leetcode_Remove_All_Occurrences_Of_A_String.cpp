Remove All Occurrences of a Substring (LeetCode 1910)
Given two strings s and part, repeatedly remove the substring part from s until it no longer appears in the string. Return the final string after all occurrences of part are removed.
Intuition

The idea is to repeatedly search for the substring part inside the string s. If the substring exists, we remove it and continue checking again. To search for the substring we use the find() function. If find() returns a valid index, it means the substring is present. If it returns string::npos, it means the substring is not present anymore and we can stop the loop.

To remove the substring, we use the erase() function which deletes a certain number of characters starting from a given index.

Approach

Use find() to check if the substring part exists in s.

If it exists, store the starting index in a variable pos.

Use erase(pos, part.length()) to remove the substring.

Repeat this process until part is no longer found in s.

Return the final string.


Dry Run Example

Input

s = "daabcbaabcbc"
part = "abc"
Iteration 1
daabcbaabcbc
  ↑
pos = 2

Remove "abc"

dabaabcbc
Iteration 2
dabaabcbc
     ↑
pos = 5

Remove "abc"

dababc
Iteration 3
dababc
   ↑
pos = 3

Remove "abc"

dab
Final Output
dab
Time Complexity
O(n²)
find() may run multiple times and each erase() operation can take O(n) time.
Space Complexity
O(1)
No extra data structures are used; the string is modified in place.






class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.find(part) != string::npos){//run the loop till no part is found in the string
            int pos = s.find(part);//create a variable and store the position of that part  in that variable eg daabc pos = 2
            s.erase(pos, part.length());//remove the part using erase function
            //erase function ask for the start index so which we calculated in pos so pass that index and the length we want to delete that is part's lenght 
        }
        return s; //return the remaining string
    }
};
