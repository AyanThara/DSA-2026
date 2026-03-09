#include<iostream>
using namespace std;
bool searchElement(int arr[][100], int rows, int cols, int target){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(arr[i][j] == target){
                return true;
            }
        }
    }
    return false;
}
int main(){
    int arr[100][100];
    int rows,cols;
    cin >> rows >> cols>;
    // input
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cin >> arr[i][j];
        }
    }
    int target;
    cin >> target;
    if(searchElement(arr, rows, cols, target)){
        cout << "Element Found";
    }
    else{
        cout << "Element Not Found";
    }
}
