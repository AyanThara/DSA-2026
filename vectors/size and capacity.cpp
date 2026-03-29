#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> vec;
    vec.push_back(0);
    vec.push_back(1);
    vec.push_back(2);
    cout << "Size: " << vec.size() << endl;//3
    cout << "Capacity: " << vec.capacity() << endl;//4
}
//in next iteratoion if 2 more elements are addedd then size will be 5 but capacity will be double of 4 i.e 8
