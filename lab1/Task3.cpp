#include <bits/stdc++.h>

using namespace std;

string commentIdentifier(string str) {
    if (str.find("//") == 0)
     {
        return "Single-line comment";
     }
    else if (str.find("/*") == 0 && str.find("*/") == str.size() - 2)
     {
        return "Multi-line comment";
     }
    else
     {
        return "Not a comment";
     }
}

int main() {
    string input;
    cout << "Enter any String : ";
    getline(cin, input);
    cout << commentIdentifier(input) << endl;
    return 0;
}
