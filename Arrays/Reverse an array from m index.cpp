void reverseArray(vector<int> &arr , int m) {

    int start = m + 1;//start from m+1 index
    int end = arr.size() - 1;//go till end 

    while(start < end) {//simple binary search 
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

//eg arr[5]={1,2,3,4,5}; m=2 so we have to revese from  as array statrt with 0 base indx so as m=2 so we have to reverse from 3 so new reverse array will be {1,2,3,5,4};

