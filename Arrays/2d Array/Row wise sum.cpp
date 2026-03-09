#include<iostream>
using namespace std;
void rowWiseSum(int arr[][100], int rows, int cols){
    for(int i = 0; i < rows; i++){
        int sum = 0;
        for(int j = 0; j < cols; j++){
            sum += arr[i][j];
        }
        cout << "Sum of row " << i << " = " << sum << endl;
    }

}
int main(){
    int arr[100][100];
    int rows, cols;
    cin >> rows >> cols;
    // input
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cin >> arr[i][j];
        }
    }
    rowWiseSum(arr, rows, cols);
}
