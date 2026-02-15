#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    // ----------------- APPROACH 1: USING EXTRA ARRAY -----------------
    //simple beginner method: create a third array and merge into it
    void mergeWithExtra(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        vector<int> arr3;
        int i = 0, j = 0;

        //compare and store smaller element
        while(i < m && j < n){
            if(nums1[i] < nums2[j]){
                arr3.push_back(nums1[i]);
                i++;
            } else {
                arr3.push_back(nums2[j]);
                j++;
            }
        }

        //store remaining elements
        while(i < m){
            arr3.push_back(nums1[i]);
            i++;
        }

        while(j < n){
            arr3.push_back(nums2[j]);
            j++;
        }

        //copy back to nums1
        for(int k = 0; k < m+n; k++){
            nums1[k] = arr3[k];
        }
    }


    // ----------------- APPROACH 2: OPTIMAL IN-PLACE -----------------
    //best solution: fill nums1 from back, no extra space needed
    void mergeOptimal(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i = m - 1;        //last valid element in nums1
        int j = n - 1;        //last element in nums2
        int k = m + n - 1;    //last index of nums1

        //place bigger element at the end
        while(i >= 0 && j >= 0){
            if(nums1[i] > nums2[j]){
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }

        //copy remaining nums2 elements if any
        while(j >= 0){
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};

int main() {

    Solution obj;

    //example arrays
    vector<int> nums1a = {1,2,3,0,0,0};
    vector<int> nums2a = {2,5,6};

    vector<int> nums1b = nums1a;   //copy for second method
    vector<int> nums2b = nums2a;

    int m = 3, n = 3;

    //----- run extra array approach -----
    obj.mergeWithExtra(nums1a, m, nums2a, n);

    cout << "Merge using extra array: ";
    for(int x : nums1a) cout << x << " ";
    cout << endl;


    //----- run optimal in-place approach -----
    obj.mergeOptimal(nums1b, m, nums2b, n);

    cout << "Merge using optimal in-place: ";
    for(int x : nums1b) cout << x << " ";
    cout << endl;

    return 0;
}
