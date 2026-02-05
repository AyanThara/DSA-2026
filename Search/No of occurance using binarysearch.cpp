int countOccurrences(vector<int>& arr, int n, int k) {
    int first = -1, last = -1;
    int start = 0, end = n - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == k) {
            first = mid;
            end = mid - 1;
        } else if (arr[mid] < k) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    if (first == -1) return 0;
    start = 0;
    end = n - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == k) {
            last = mid;
            start = mid + 1;
        } else if (arr[mid] < k) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return last - first + 1;
}
