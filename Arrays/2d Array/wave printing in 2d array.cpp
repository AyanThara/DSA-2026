vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols){
    vector<int> ans;
    for(int col = 0; col < mCols; col++){
        if(col % 2 == 0){  // even column -> top to bottom
            for(int row = 0; row < nRows; row++)
            {
                ans.push_back(arr[row][col]);
            }
        }
        else{ // odd column -> bottom to top
            for(int row = nRows-1; row >= 0; row--){
                ans.push_back(arr[row][col]);
            }
        }
    }return ans;
}



//simple logic check the col if col is multple of 2 then top to bottom print else bottom to top and push in ans vector nd return ans vector
