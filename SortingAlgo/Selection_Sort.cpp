# Selection Sort

## Intuition

Selection Sort divides the array into two parts: a sorted part and an unsorted part. In every iteration, it finds the smallest element from the unsorted part and places it at its correct position. After each iteration, the sorted part grows by one element.

---

## Approach

1. Start from the first element.
2. Assume the current element is the smallest.
3. Traverse the remaining unsorted array to find the actual smallest element.
4. Swap the smallest element with the current position.
5. Repeat the process until only one element remains.

### Why `i < n-1`?

The outer loop fixes one position in every iteration. After fixing the first `n-1` positions, the last element is automatically in its correct position, so there is no need for another iteration.

### Why `j < n`?

The inner loop searches the entire remaining unsorted array to find the minimum element. It must check the last element as well, so the loop runs until `j < n`.

---

## Complexity

- **Time Complexity**
  - Best Case: `O(n²)`
  - Average Case: `O(n²)`
  - Worst Case: `O(n²)`

- **Space Complexity**
  - `O(1)`

---

## Code
```cpp
#include <iostream>
using namespace std;
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int curr = arr[i];
        int prev = i - 1;
        while (prev >= 0 && arr[prev] > curr) {
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = curr;
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = 5;
    insertionSort(arr, n);
    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}
```
