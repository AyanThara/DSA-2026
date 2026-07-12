# 🎨 Painter's Partition Problem – II (GFG)

## Problem Statement

Given an array `arr[]` where each element represents the length of a board and an integer `k` representing the number of painters, determine the minimum time required to paint all the boards.

### Constraints

* Every painter paints **only contiguous boards**.
* A board **cannot be split** between painters.
* Every painter paints **1 unit length in 1 unit time**.
* Every board must be painted.
* The objective is to **minimize the maximum time** taken by any painter.

---

# Intuition

The problem asks us to **minimize the maximum painting time**.

Instead of trying every possible partition of boards, we **Binary Search on the Answer**.

Suppose we assume:

```text
Maximum time allowed for one painter = mid
```

Now ask the question:

> **Can all boards be painted using at most `k` painters if no painter paints more than `mid` units?**

There are only two possibilities:

* ✅ **Yes** → `mid` is a valid answer. Try a smaller value.
* ❌ **No** → `mid` is too small. Increase it.

This monotonic property makes Binary Search possible.

---

# Why is the Search Space Correct?

## Minimum Possible Answer

The largest board must be painted by one painter.

Since a board cannot be split,

```cpp
low = max(arr)
```

Example:

```text
Boards = [5,10,30,20,15]

Largest board = 30
```

So the answer can never be less than **30**.

---

## Maximum Possible Answer

One painter paints every board.

```cpp
high = sum(arr)
```

Example:

```text
5 + 10 + 30 + 20 + 15 = 80
```

So the search range becomes

```text
30 -------------------- 80
```

---

# Feasibility Check (`isPossible()`)

For every guessed value `mid`:

* Start assigning boards to the first painter.
* Keep adding boards until adding another board exceeds `mid`.
* Start assigning boards to the next painter.
* Count how many painters are required.

If the required painters become greater than `k`,

```cpp
return false;
```

Otherwise,

```cpp
return true;
```

---

# Algorithm

1. Set

   * `low = maximum board length`
   * `high = sum of all board lengths`
2. Perform Binary Search.
3. Compute `mid`.
4. Check whether painting is possible with `mid`.
5. If possible:

   * Store `mid`.
   * Search the left half.
6. Otherwise:

   * Search the right half.
7. Return the minimum valid answer.

---

# Dry Run

### Input

```text
arr = [5,10,30,20,15]
k = 3
```

Initial values

```text
low = 30
high = 80
```

---

## Iteration 1

```text
mid = (30 + 80) / 2 = 55
```

Allocation

```text
Painter 1

5 + 10 + 30 = 45

45 + 20 = 65 > 55
```

Painter 2

```text
20 + 15 = 35
```

Painters used

```text
2
```

Possible ✅

Update

```text
ans = 55
high = 54
```

---

## Iteration 2

```text
low = 30
high = 54

mid = 42
```

Allocation

```text
Painter 1

5 + 10 = 15

15 + 30 = 45 > 42
```

Painter 2

```text
30
```

Next board

```text
30 + 20 = 50 > 42
```

Painter 3

```text
20 + 15 = 35
```

Painters used

```text
3
```

Possible ✅

Update

```text
ans = 42
high = 41
```

---

## Iteration 3

```text
low = 30
high = 41

mid = 35
```

Allocation

```text
Painter 1

5 + 10 = 15
```

Next board

```text
15 + 30 = 45 > 35
```

Painter 2

```text
30
```

Next board

```text
30 + 20 = 50 > 35
```

Painter 3

```text
20 + 15 = 35
```

Painters used

```text
3
```

Possible ✅

Update

```text
ans = 35
high = 34
```

---

## Iteration 4

```text
low = 30
high = 34

mid = 32
```

Allocation

```text
Painter 1

5 + 10 = 15
```

Next board

```text
15 + 30 = 45 > 32
```

Painter 2

```text
30
```

Next board

```text
30 + 20 = 50 > 32
```

Painter 3

```text
20
```

Next board

```text
20 + 15 = 35 > 32
```

Painter 4

```text
15
```

Need

```text
4 painters
```

Not Possible ❌

Update

```text
low = 33
```

---

## Iteration 5

```text
low = 33
high = 34

mid = 33
```

Again, 4 painters are required.

Not Possible ❌

```text
low = 34
```

---

## Iteration 6

```text
low = 34
high = 34

mid = 34
```

Again, 4 painters are required.

Not Possible ❌

```text
low = 35
```

Now

```text
low = 35
high = 34
```

Binary Search ends.

---

# Final Answer

```text
35
```

---

# C++ Solution

```cpp
class Solution {
public:

    bool isPossible(vector<int>& arr, int k, long long mid) {

        int painters = 1;
        long long time = 0;

        for (int board : arr) {

            if (time + board <= mid) {
                time += board;
            } else {

                painters++;
                time = board;

                if (painters > k)
                    return false;
            }
        }

        return true;
    }

    int minTime(vector<int>& arr, int k) {

        long long low = *max_element(arr.begin(), arr.end());

        long long high = 0;

        for (int board : arr)
            high += board;

        long long ans = high;

        while (low <= high) {

            long long mid = low + (high - low) / 2;

            if (isPossible(arr, k, mid)) {

                ans = mid;
                high = mid - 1;

            } else {

                low = mid + 1;
            }
        }

        return (int)ans;
    }
};
```

---

# Complexity Analysis

| Complexity            | Value                |
| --------------------- | -------------------- |
| **Feasibility Check** | **O(n)**             |
| **Binary Search**     | **O(log(sum(arr)))** |

### Overall Time Complexity

```text
O(n × log(sum(arr)))
```

### Space Complexity

```text
O(1)
```

---

# Key Takeaways

* This is a **Binary Search on Answer** problem.
* We are **not searching the array**.
* We are searching the **minimum possible maximum painting time**.
* `isPossible(mid)` checks whether all boards can be painted using at most `k` painters if each painter paints at most `mid` units.
* If `mid` is possible, search the **left half** because we want to minimize the answer.
* If `mid` is not possible, search the **right half**.

---

# Similar Problems

* Allocate Minimum Pages (GFG)
* Painter's Partition Problem – II (GFG)
* Split Array Largest Sum (LeetCode 410)
* Capacity to Ship Packages Within D Days (LeetCode 1011)

### Binary Search Pattern

| Problem Type             | Binary Search Move                    |
| ------------------------ | ------------------------------------- |
| **Minimize the Maximum** | Possible → Left, Not Possible → Right |
| **Maximize the Minimum** | Possible → Right, Not Possible → Left |
