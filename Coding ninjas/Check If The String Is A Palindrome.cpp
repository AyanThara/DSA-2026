bool checkPalindrome(string s) {
    string clean = "";
    for(char c : s) {
        if(isalnum(c)) {
            if(c >= 'A' && c <= 'Z') 
                clean += (c - 'A' + 'a');   
            else 
                clean += c;                
        }
    }
    int start = 0;
    int end = clean.length() - 1;
    while(start < end) {
        if(clean[start] != clean[end])
            return false;
        start++;
        end--;
    }
    return true;
}
