#include <bits/stdc++.h>
using namespace std;
/*
Approach:
- Compare adjacent elements
- Swap if needed
- Stop early if no swaps happen

*/

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for(int i = 0; i < n - 1; i++) {//loop tell that how many rounds re taking place 
        bool swapped =false;//take a variable nd make it false 
        for(int j = 0; j < n - i - 1; j++) {//run till n-i-1 so that the already swwapped elements are not checked
            if(arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;//if swap then update to true 
            }
        }

        if(swapped==false) {//check if no swap then break so we can optimize the code
          break; 
        }
    }
}
