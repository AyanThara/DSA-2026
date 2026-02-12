#include <bits/stdc++.h>
using namespace std;

/*
Insertion Sort

Time Complexity:
Best: O(n)
Average: O(n²)
Worst: O(n²)

Space Complexity: O(1)
Stable: Yes
In-place: Yes
*/

void insertionSort(int n, vector<int>& arr) {
    for(int i = 1; i < n; i++) {//run i loop from 1 to n because we considered o th index element as already sorted 
        int temp = arr[i];// we will store i th element in temp
        int j = i - 1;//we will compare all the element till i-1 index
        while(j >= 0 && arr[j] > temp) {//check is j>0 and also if the value of j >temp the index value we will replace j+! index value with j and 
            arr[j + 1] = arr[j];
            j--;// we will take j back to the index and will store the value of tenp 
        }

        arr[j + 1] = temp;
    }
}
include <bits/stdc++.h>
using namespace std;

/*
Insertion Sort – With Dry Run Explanation

Idea:
We assume first element (index 0) is already sorted.
Then we pick elements one by one and insert them
into their correct position in the sorted part.

Example:
arr = [5, 3, 1]

Step 1:
i = 1
temp = 3
j = 0

Compare arr[j] (5) > temp (3)
→ Shift 5 to right
Array becomes: [5, 5, 1]
j--

Now j = -1 (stop loop)
Insert temp at j+1 → index 0

Array becomes: [3, 5, 1]

Step 2:
i = 2
temp = 1
j = 1

Compare 5 > 1 → shift
Array: [3, 5, 5]

j = 0
Compare 3 > 1 → shift
Array: [3, 3, 5]

j = -1 → stop
Insert temp at index 0

Final: [1, 3, 5]

Time Complexity:
Best Case: O(n) (Already sorted)
Worst Case: O(n²)
Space: O(1)
Stable: Yes
*
void insertionSort(int n, vector<int>& arr) {

    // Start from index 1 because index 0 is already sorted
    for(int i = 1; i < n; i++) {

        int temp = arr[i];     // Store current element
        int j = i - 1;         // Compare with sorted part

        // Shift elements greater than temp
        while(j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];  // Move element right
            j--;                  // Move left
        }

        // Place temp at correct position
        arr[j + 1] = temp;
    }
}*/
