#include<iostream>
using namespace std;
int largestRowSum(int arr[][100], int rows, int cols){
    int maxSum = INT_MIN;
    int index = -1;
    for(int i = 0; i < rows; i++){
        int sum = 0;
        for(int j = 0; j < cols; j++){
            sum += arr[i][j];
        }
        if(sum > maxSum){
            maxSum = sum;
            index = i;
        }
    }
    return index;
}
int main(){
    int arr[100][100];
    int rows, cols;
    cin >> rows >> cols;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cin >> arr[i][j];
        }
    }
    int result = largestRowSum(arr, rows, cols);
    cout << "Row with maximum sum is: " << result << endl;
}
