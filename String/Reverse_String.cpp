/*#include <iostream>
#include <string>
using namespace std;
int main() {
    string str = "ayan";
    for(int i = str.length() - 1; i >= 0; i--) {
        cout << str[i];
    }
}
*/
//Two pointer approaoch
#include <iostream>
#include <string>
using namespace std;
int main() {
    string str = "ayan";
    int start = 0;
    int end = str.length() - 1;

    while(start < end) {
        swap(str[start], str[end]);
        start++;
        end--;
    }
    cout << str;
}
