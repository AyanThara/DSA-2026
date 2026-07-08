# 📚 Allocate Minimum Pages (GFG)

## Problem Statement

Given an array `arr[]` where `arr[i]` represents the number of pages in the `i-th` book and an integer `k` representing the number of students, allocate books such that:

* Each student gets **at least one** book.
* Books assigned to a student are **contiguous**.
* Every book is allocated exactly once.
* Minimize the **maximum number of pages** assigned to any student.

If the number of students is greater than the number of books, return `-1`.

---

## Approach

This problem can be solved efficiently using **Binary Search on Answer**.

Instead of checking every possible allocation, we binary search the answer (maximum pages assigned to a student).

### Search Space

The minimum possible answer is the largest book because a student must read the entire book.

```cpp
low = max(arr)
```

The maximum possible answer is the sum of all pages because one student can read every book.

```cpp
high = sum(arr)
```

---

## Feasibility Check

For every guessed answer `mid`:

* Start allocating books to the first student.
* Keep assigning books until adding another book exceeds `mid`.
* Allocate the next book to a new student.
* Count the number of students required.

If the required students are less than or equal to `k`, then `mid` is a valid answer.

Otherwise, we need to increase `mid`.

---

## Algorithm

1. If `k > number of books`, return `-1`.
2. Set:

   * `low = maximum element`
   * `high = sum of all pages`
3. Perform Binary Search.
4. For each `mid`, check whether allocation is possible.
5. If possible:

   * Store `mid` as the current answer.
   * Search the left half.
6. Otherwise:

   * Search the right half.
7. Return the minimum valid answer.

---

## Dry Run

### Input

```text
arr = [12, 34, 67, 90]
k = 2
```

Initial search space:

```text
low = 90
high = 203
```

### Iteration 1

```text
mid = 146
```

Allocation:

```text
Student 1 -> 12 + 34 + 67 = 113
Student 2 -> 90
```

Students used = 2 ✅

Possible

```text
Answer = 146
high = 145
```

---

### Iteration 2

```text
mid = 117
```

Allocation:

```text
Student 1 -> 12 + 34 + 67 = 113
Student 2 -> 90
```

Students used = 2 ✅

Possible

```text
Answer = 117
high = 116
```

---

### Iteration 3

```text
mid = 103
```

Allocation:

```text
Student 1 -> 12 + 34 = 46
Student 2 -> 67
Student 3 -> 90
```

Students used = 3 ❌

Not Possible

```text
low = 104
```

---

### Iteration 4

```text
mid = 110
```

Again, 3 students are required.

Not Possible

```text
low = 111
```

---

### Iteration 5

```text
mid = 113
```

Allocation:

```text
Student 1 -> 12 + 34 + 67 = 113
Student 2 -> 90
```

Students used = 2 ✅

Possible

```text
Answer = 113
```

Binary Search ends.

### Final Answer

```text
113
```

---

## Correct C++ Solution

```cpp
class Solution {
public:

    bool isPossible(vector<int>& arr, int k, long long mid) {
        int students = 1;
        long long pages = 0;

        for (int book : arr) {
            if (pages + book <= mid) {
                pages += book;
            } else {
                students++;
                pages = book;

                if (students > k)
                    return false;
            }
        }

        return true;
    }

    int findPages(vector<int>& arr, int k) {

        int n = arr.size();

        if (k > n)
            return -1;

        long long low = *max_element(arr.begin(), arr.end());
        long long high = 0;

        for (int book : arr)
            high += book;

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

## Complexity Analysis

| Complexity | Value                    |
| ---------- | ------------------------ |
| Time       | **O(n × log(sum(arr)))** |
| Space      | **O(1)**                 |

---

## Key Takeaways
* Binary Search is performed on the **answer**, not on the array.
* The feasibility function greedily allocates books while maintaining contiguous order.
* Whenever a problem asks to **minimize the maximum** (or **maximize the minimum**) and checking a candidate answer is efficient, **Binary Search on Answer** is usually the optimal approach.

### Similar Problems
* LeetCode 410 – Split Array Largest Sum
* LeetCode 1011 – Capacity to Ship Packages Within D Days

