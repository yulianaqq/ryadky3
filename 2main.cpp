#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;


bool IsPasswordStrong(const string& password, string& errorMsg) {
    bool hasLower = false, hasUpper = false, hasDigit = false;

  
    if (password.length() < 8) {
        errorMsg = "Password must be at least 8 characters long.";
        return false;
    }

  
    for (int i = 0; i < password.length(); i++) {
        if (islower(password[i]))
            hasLower = true;
        else if (isupper(password[i]))
            hasUpper = true;
        else if (isdigit(password[i]))
            hasDigit = true;
    }

  
    if (!hasLower)
        errorMsg += " Missing lowercase letters.";
    if (!hasUpper)
        errorMsg += " Missing uppercase letters.";
    if (!hasDigit)
        errorMsg += " Missing digits.";

    
    return hasLower && hasUpper && hasDigit;
}


string GenerateStrongPassword() {
    const string lower = "abcdefghijklmnopqrstuvwxyz";
    const string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const string digits = "0123456789";
    string password;

   
    password += lower[rand() % lower.length()];
    password += upper[rand() % upper.length()];
    password += digits[rand() % digits.length()];

   
    string allChars = lower + upper + digits;
    while (password.length() < 8) {
        password += allChars[rand() % allChars.length()];
    }

    return password;
}

int main() {
    srand(time(0)); 

    string password, errorMsg;
    cout << "Enter a password for validation: ";
    cin >> password;

  
    if (IsPasswordStrong(password, errorMsg)) {
        cout << "Password is strong." << endl;
    } else {
        cout << "Password is weak." << endl;
        cout << "Issues: " << errorMsg << endl;

        
        cout << "Generated strong password: " << GenerateStrongPassword() << endl;
    }

    return 0;
}
