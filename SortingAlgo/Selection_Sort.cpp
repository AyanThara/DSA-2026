#include <iostream>
using namespace std;
void SelectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[min_index] > arr[j]) {
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]);
    }
}
int main() {
    int array[] = {64, 25, 12, 22, 11};
    int n = 5;
    SelectionSort(array, n);
    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
}
