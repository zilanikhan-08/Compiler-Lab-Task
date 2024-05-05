#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <sstream>
using namespace std;

const int MAX_KEYWORDS = 50;
const int MAX_TOKENS_PER_LINE = 100;
const int MAX_LINE_LENGTH = 1000;
const int MAX_HEADER_SIZE = 100;

// Function to check if a character is alphanumeric
bool isAlphanumeric(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

// Function to check if a string is a valid C++ keyword
bool isKeyword(const string& word, const string keywords[], int numKeywords) {
    for (int i = 0; i < numKeywords; ++i) {
        if (word == keywords[i]) {
            return true;
        }
    }
    return false;
}

// Function to tokenize a line of code
int tokenizeLine(const string& line, string tokens[][MAX_TOKENS_PER_LINE]) {
    int numTokens = 0;
    string token = "";
    stringstream ss(line);

    while (ss >> token) {
        tokens[numTokens++][0] = token;
    }

    return numTokens;
}

int main() {
    // Check for the presence of the header file
    const char* sourceCode = "#include <iostream>";
    bool headerResult = isHeader(sourceCode);
    if (!headerResult) {
        cout << "No Header file found." << endl;
        return 1;
    }

    // Load C++ keywords from file
    ifstream keywordFile("keywords.txt");
    if (!keywordFile.is_open()) {
        cout << "Error opening keywords file." << endl;
        return 1;
    }

    string keywords[MAX_KEYWORDS];
    int numKeywords = 0;
    string keyword;
    while (numKeywords < MAX_KEYWORDS && keywordFile >> keyword) {
        keywords[numKeywords++] = keyword;
    }
    keywordFile.close();

    // Open lex_input.txt
    ifstream inputFile("lex_input.txt");
    if (!inputFile.is_open()) {
        cout << "Error opening lex_input file." << endl;
        return 1;
    }

    string line;
    int lineNumber = 1;
    string tokens[MAX_LINE_LENGTH][MAX_TOKENS_PER_LINE];
    while (getline(inputFile, line)) {
        // Check for syntax errors, wrong data types, and report them
        if (line.find("itn") != string::npos) {
            cout << "Syntax error: 'itn' instead of 'int' in line " << lineNumber << endl;
        }
        if (line.find("#") != string::npos) {
            cout << "Syntax error: '#' is not a valid character in line " << lineNumber << endl;
        }

        // Tokenize the line
        int numTokens = tokenizeLine(line, tokens);
        cout << "Tokenizing line " << lineNumber << ": ";
        // Categorically tokenize every element
        for (int i = 0; i < numTokens; ++i) {
            if (isKeyword(tokens[i][0], keywords, numKeywords)) {
                cout << tokens[i][0] << " is a keyword. ";
            } else if (tokens[i][0] == "=" || tokens[i][0] == "+" || tokens[i][0] == "-" || tokens[i][0] == "*" || tokens[i][0] == "/" || tokens[i][0] == "%" || tokens[i][0] == "<" || tokens[i][0] == ">" || tokens[i][0] == "==" || tokens[i][0] == "!=" || tokens[i][0] == "<=" || tokens[i][0] == ">=") {
                cout << tokens[i][0] << " is an operator. ";
            } else if (tokens[i][0] == ";" || tokens[i][0] == "," || tokens[i][0] == "{" || tokens[i][0] == "}" || tokens[i][0] == "(" || tokens[i][0] == ")") {
                cout << tokens[i][0] << " is a punctuation. ";
            } else if (isAlphanumeric(tokens[i][0][0]) || tokens[i][0][0] == '_') {
                cout << tokens[i][0] << " is an identifier. ";
            } else {
                cout << tokens[i][0] << " is unrecognized. ";
            }
        }
        cout << endl;

        lineNumber++;
    }

    inputFile.close();

    return 0;
}
