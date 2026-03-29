#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v = {1, 2, 3};
    int n = v.size();
    for(int i = 0; i < n; i++){          // start index
        for(int j = i; j < n; j++){      // end index
            for(int k = i; k <= j; k++){ // print subarray
                cout << v[k] << " ";
            }
            cout << endl;
        }
    }
}
