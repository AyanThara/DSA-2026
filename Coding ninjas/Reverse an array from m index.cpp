void reverseArray(vector<int> &arr , int m) {

    int start = m + 1;// start from m+! index
    int end = arr.size() - 1;//go till end

    while(start < end) {//simple binary search
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}
