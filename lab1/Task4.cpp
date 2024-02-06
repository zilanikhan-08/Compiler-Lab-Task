#include <bits/stdc++.h>

using namespace std;

int identifierChecker(string input) {
    if ((input.empty()))
        return 2;

    if ((input[0] >= 'a' && input[0] <= 'z') || (input[0] >= 'A' && input[0] <= 'Z') || input[0] == '_')
        return 1;


    for (int i = 1; i < input.length(); ++i) {
        if (((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= '0' && input[i] <= '9') || input[i] == '_'))
            return 1;
    }

    return 0;
}

int main() {
    string input;
    cout << "Enter the input: ";
   getline(cin, input);

    if (identifierChecker(input)==1)
    {
        cout << "The input is an identifier." <<endl;
    }
    if(identifierChecker(input)==0)
    {
        cout << "The input is not an identifier." <<endl;
    }
    if(identifierChecker(input)==2)
    {
        cout << "No Input Provided." <<endl;
    }

    return 0;
}
