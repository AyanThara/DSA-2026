# Two Sum II - Input Array Is Sorted (Two Pointer Approach)

## Problem Statement

Given a **1-indexed sorted array** `numbers` and an integer `target`, return the indices of the two numbers such that they add up to the target.
---

# Algorithm

1. Initialize two pointers:

   * `start = 0`
   * `end = last index`

2. Calculate the sum:

   ```
   sum = numbers[start] + numbers[end]
   ```

3. If:

   * `sum == target` → Return indices.
   * `sum > target` → Move `end--`.
   * `sum < target` → Move `start++`.

4. Continue until `start >= end`.

---

# Dry Run

### Input

```
numbers = [2,7,11,15]
target = 9
```

### Initial State

```
Index : 0   1   2   3
Value : 2   7  11  15
        S           E
```

### Iteration 1

```
sum = 2 + 15 = 17

17 > 9

Move end--
```

```
Index : 0   1   2   3
Value : 2   7  11  15
        S       E
```

---

### Iteration 2

```
sum = 2 + 11 = 13

13 > 9

Move end--
```

```
Index : 0   1   2   3
Value : 2   7  11  15
        S   E
```

---

### Iteration 3

```
sum = 2 + 7 = 9

Target Found
```

Return

```
{1,2}
```

---

# Why Two Pointers Work?

Since the array is already sorted:

* If the sum is too large, moving the right pointer left decreases the sum.
* If the sum is too small, moving the left pointer right increases the sum.

Therefore, we never need to check the same pair again.

---

# Complexity Analysis

**Time Complexity:** `O(n)`

Each pointer moves at most `n` times.

**Space Complexity:** `O(1)`

Only two pointers are used.

---

# Key Learning

* Works only because the array is sorted.
* Uses two pointers instead of nested loops.
* Better than brute force (`O(n²)`).
* One of the most common interview patterns.

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
    return{};//no validpair found
    }
};
