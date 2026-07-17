# Insertion Sort

## Intuition

Insertion Sort works by dividing the array into two parts: a sorted part and an unsorted part.

We assume the first element is already sorted. Then, starting from the second element, we pick the current element and insert it into its correct position in the sorted part.

---

## Approach

1. Start the loop from index `1` because we assume the first element is already sorted.
2. Store the current element in `curr`.
3. Use `prev` to point to the previous element.
4. Compare `curr` with the previous elements.
5. If the previous element is greater than `curr`, shift it one position to the right.
6. Move `prev` backward using `prev--`.
7. When the correct position is found, insert `curr` at `prev + 1`.
8. Repeat until the entire array is sorted.

---

## Dry Run

Consider:

`arr = [4, 1, 2, 3]`

### Initial Array

```text
[4, 1, 2, 3]

Sorted:   [4]
Unsorted: [1, 2, 3]
```

### Iteration 1

```text
i = 1
curr = 1
prev = 0

arr[prev] = 4
```

Compare:

```text
4 > 1 → True
```

Shift `4` to the right:

```text
[4, 4, 2, 3]
```

Move `prev` backward:

```text
prev--
prev = -1
```

Now insert `curr` at `prev + 1`:

```text
prev + 1 = 0
arr[0] = 1
```

Array:

```text
[1, 4, 2, 3]
```

---

### Iteration 2

```text
i = 2
curr = 2
prev = 1

arr[prev] = 4
```

Compare:

```text
4 > 2 → True
```

Shift `4` right:

```text
[1, 4, 4, 3]
```

Move backward:

```text
prev = 0
```

Compare:

```text
arr[0] > curr
1 > 2 → False
```

Insert `curr` at `prev + 1`:

```text
arr[1] = 2
```

Array:

```text
[1, 2, 4, 3]
```

---

### Iteration 3

```text
i = 3
curr = 3
prev = 2

arr[prev] = 4
```

Compare:

```text
4 > 3 → True
```

Shift `4` right:

```text
[1, 2, 4, 4]
```

Move backward:

```text
prev = 1
```

Compare:

```text
2 > 3 → False
```

Insert `curr` at `prev + 1`:

```text
arr[2] = 3
```

Final Array:

```text
[1, 2, 3, 4]
```

---

## Dry Run Summary

| Iteration | curr | Array After Insertion |
|-----------|------|-----------------------|
| Initial | - | `[4, 1, 2, 3]` |
| 1 | 1 | `[1, 4, 2, 3]` |
| 2 | 2 | `[1, 2, 4, 3]` |
| 3 | 3 | `[1, 2, 3, 4]` |

---

## Key Logic

```cpp
int curr = arr[i];
int prev = i - 1;

while (prev >= 0 && arr[prev] > curr) {
    arr[prev + 1] = arr[prev];
    prev--;
}

arr[prev + 1] = curr;
```

- `curr` → stores the element we want to insert.
- `prev` → moves backward through the sorted part.
- `arr[prev + 1] = arr[prev]` → shifts a larger element one position to the right.
- `prev--` → moves backward to check the previous element.
- `arr[prev + 1] = curr` → inserts `curr` into its correct position.

---

## Complexity

- **Best Case:** `O(n)` — when the array is already sorted.
- **Average Case:** `O(n²)`
- **Worst Case:** `O(n²)` — when the array is reverse sorted.
- **Space Complexity:** `O(1)`

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

    int arr[] = {4, 1, 2, 3};
    int n = 4;

    insertionSort(arr, n);

    cout << "Sorted Array: ";

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
```

## Output

```text
Sorted Array: 1 2 3 4
```
