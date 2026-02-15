//beginner friendly approach creating an third  array and storing the in the third array 
/*class Solution {     
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> arr3; 
        int i = 0, j = 0;
        while(i < m && j < n) {
            if(nums1[i] < nums2[j]) {  //compare the element and store the lowest 
                arr3.push_back(nums1[i]); //in arr3 and update the index
                i++;a
            } else {
                arr3.push_back(nums2[j]);
                j++;
            }
        }
        while(i < m) {   
            arr3.push_back(nums1[i]);
            i++;
        }
        while(j < n) {
            arr3.push_back(nums2[j]);
            j++;
        }
 //storing back all the element to nums1 as given in question no extra space to be taken 
        for(int k = 0; k < m + n; k++) {             
            nums1[k] = arr3[k];
        }
    }
};*/

//optimal beginner friendly approach (no extra array used)
//we start filling nums1 from the back to avoid overwriting existing elements

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i = m - 1;   //points to last valid element in nums1
        int j = n - 1;   //points to last element in nums2
        int k = m + n - 1; //points to last position of nums1 (final merged place)

        //compare elements from the end and place the bigger one at the back
        //this keeps nums1 sorted without needing extra space
        while(i >= 0 && j >= 0){
            if(nums1[i] > nums2[j]){
                nums1[k] = nums1[i];  //put nums1 element at correct back position
                k--;
                i--;
            } else {
                nums1[k] = nums2[j];  //put nums2 element at correct back position
                k--;
                j--;
            }
        }

        //if nums2 still has elements left, copy them
        //no need to copy nums1 leftovers because they are already in place
        while(j >= 0){
            nums1[k] = nums2[j];
            k--;
            j--;
        }
    }   
};

