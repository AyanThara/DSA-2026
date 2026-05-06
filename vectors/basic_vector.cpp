#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>vec={3,0};
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(6);
    for(int i:vec){
        cout<<i<<endl;
    }
    cout<<"size of vec is "<<vec.size()<<endl;
    cout<<"capacity of vec  is "<<vec.capacity();
}
