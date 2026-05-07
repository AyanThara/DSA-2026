#include<iostream>
using namespace std;
int main(){
    int n=5;
    int array[5]={1,2,3,4,5};
    for(int start=0;start<=n;start++){  //starting index
        for(int end=start;end<=n;end++){  //ending index
            for(int i=start;i<end;i++){   //start a loop from start and run till end and print the array[i[
                cout<<array[i]<<" ";
            }
        }
        cout<<endl;
    }
}
