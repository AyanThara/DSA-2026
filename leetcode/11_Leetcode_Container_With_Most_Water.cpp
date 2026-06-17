# 💧 Container With Most Water
## 🧠 Problem (Very Simple)
You are given an array of heights.

Think of each number as a vertical wall.
👉 Your task:
Pick **two walls** such that they can hold **maximum water** between them.

---
## 👶 Explanation (Like 5-Year-Old)

Imagine:
- You have two sticks 🪵
- You pour water between them 🧃

👉 Water will stay only till the **shorter stick**

So:
- Height = smaller stick
- Width = distance between sticks

👉 Water = height × width

---

## 🔍 Example

Input:
[1,8,6,2,5,4,8,3,7]

Pick:
- 8 and 7

👉 smaller = 7  
👉 distance = 7  

👉 water = 7 × 7 = 49 ✅

---

## 🚀 Approach (Two Pointers)

- Start from both ends  
- Calculate area  
- Move pointer of smaller height  
- Repeat until pointers meet  

---

## 💻 Code (With Comments)
    
class Solution {//brute force 
public:
    int maxArea(vector<int>& height) {
     int n=height.size();
     int maxWater=0;
     for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
          int width=j-i;
          int h=min(height[i],height[j]);
          int currentWater=h*width;
          maxWater=max(maxWater,currentWater);
          }
       }  
    return maxWater; 
    }
};


```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;                         // start pointer from left (index 0)
        int right = height.size() - 1;        // start pointer from right (last index)
        int ans = 0;                          // store maximum area

        while(left < right) {                 // run loop until both pointers meet
            int h = min(height[left], height[right]); // take smaller height (water level)
            int w = right - left;             // calculate width (distance between lines)

            ans = max(ans, h * w);            // update max area

            // move pointer which has smaller height
            // because only this can increase area
            if(height[left] < height[right])
                left++;                       // move left pointer to right
            else
                right--;                      // move right pointer to left
        }

        return ans;                           // return final maximum water stored
    }
};


