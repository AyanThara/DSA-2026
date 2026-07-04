# LeetCode 540 - Single Element in a Sorted Array
## Problem Statement
Given a sorted array consisting of only integers where every element appears exactly twice except for one element which appears exactly once, find the single element that appears only once.
You must solve it in **O(log n)** time and **O(1)** space.

### Example 1
Input:
```text
[1,1,2,3,3,4,4,8,8]
```

Output:

```text
2
```

### Example 2

Input:

```text
[3,3,7,7,10,11,11]
```

Output:

```text
10
```

---

# Intuition

Since the array is sorted:

* Every duplicate element appears in pairs.
* Before the single element, pairs follow a fixed pattern.
* After the single element, the pattern breaks.
* We can use Binary Search to efficiently locate the position where this pattern changes.

---

# Approach

1. Handle corner cases:

   * If array size is 1, return that element.
   * If first element is unique, return it.
   * If last element is unique, return it.

2. Calculate the middle element.

3. If the middle element is different from both its neighbours, it is the answer.

4. Use Binary Search:

   * For an even index:

     * If `nums[mid] == nums[mid+1]`, search right.
     * Otherwise search left.
   * For an odd index:

     * If `nums[mid] == nums[mid-1]`, search right.
     * Otherwise search left.

---

# Code

```cpp
class Solution {//binary search
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();

        if(n==1) return nums[0];
        //corner case to check if only 1 element is present then return it

        int start=0;
        int end=n-1;

        while(start<=end){

            int mid=start+(end-start)/2;
            //cal mid

            if(mid==0 && nums[0]!=nums[1]) return nums[0];
            //corner case for first element i.e if first element is not equal to second element then its only single element as there is no element before it to compare with

            if(mid==n-1 && nums[n-1]!=nums[n-2]) return nums[n-1];
            //corner case for last element that if last element is not equal to element before it then it is only the single element as there is no element after that to compare with

            if(mid>0 && mid<n-1 &&
               nums[mid]!=nums[mid-1] &&
               nums[mid]!=nums[mid+1])
                return nums[mid];
            //compare with -1 and +1 element for mid if none match then return mid

            if(mid%2==0){
                //even in case the mid is even

                if(nums[mid]==nums[mid+1]){
                    start=mid+1;
                }else{
                    end=mid-1;
                }

            }else{
                //odd

                if(nums[mid]==nums[mid-1]){
                    start=mid+1;
                }else{
                    end=mid-1;
                }
            }
        }

        return -1;
    }
};
```

---

# Dry Run

Input:

```text
[1,1,2,3,3,4,4,8,8]
```

### Iteration 1

```text
start = 0
end = 8

mid = 4
nums[mid] = 3
```

Check neighbours:

```text
nums[4] == nums[3]
```

Mid is even.

```text
nums[4] != nums[5]
```

Move left:

```text
end = 3
```

---

### Iteration 2

```text
start = 0
end = 3

mid = 1
nums[mid] = 1
```

Mid is odd.

```text
nums[1] == nums[0]
```

Move right:

```text
start = 2
```

---

### Iteration 3

```text
start = 2
end = 3

mid = 2
nums[mid] = 2
```

Check neighbours:

```text
nums[2] != nums[1]
nums[2] != nums[3]
```

Therefore:

```text
return 2
```

---

# Complexity Analysis

### Time Complexity

```text
O(log n)
```
Binary Search halves the search space in every iteration.
### Space Complexity
```text
O(1)
```
No extra data structure is used.
---
# Key Learning
* Binary Search is not only for searching values.
* It can also be used to identify pattern breaks.
* In sorted arrays with duplicate pairs, index parity (even/odd) is very useful.
