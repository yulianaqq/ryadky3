#include <iostream>
#include <string>
using namespace std;

string Filter(const string& str) {
    string result;
    for (int i = 0; i < str.length(); i++) {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')) {
      
            if (str[i] >= 'A' && str[i] <= 'Z') {
                result += str[i] + ('a' - 'A');  
            } else {
                result += str[i]; 
            }
        }
    }
    return result;
}


int main() {
  cout << "Enter two lines" << endl;
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    
   
    if (Filter(str1) == Filter(str2))
        cout << "Result: identical" << endl;
    else
        cout << "Result: not  identical" << endl;
    
    return 0;
}