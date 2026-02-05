#include<iostream>
using namespace std;
int binarysearch(int arr[], int size, int key){
    int start = 0;
    int end = size - 1;
    while(start <= end){
        int mid = start + (end - start) / 2; //very important to handle overflow error on coding platforms
        if(arr[mid] == key){
            return mid;
        }
        else if(arr[mid] < key){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return -1;
}
int main(){
    int even[6] = {10,20,30,40,50,60};
    int odd[5]  = {1,2,3,4,5};
    int ans1 = binarysearch(even, 6, 50);
    int ans2 = binarysearch(odd, 5, 4);
    cout << ans1 << endl;
    cout << ans2;
}
