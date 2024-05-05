#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unistd.h>
using namespace std;

const int MAX_LINE_LENGTH = 1000;

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

// Function to check for the presence of the header file
bool isHeader(const string& sourceCode, const string& header) {
    int pointer = 0;
    if (sourceCode[pointer] == '#' && sourceCode[pointer + 1] == 'i' && sourceCode[pointer + 2] == 'n' &&
        sourceCode[pointer + 3] == 'c' && sourceCode[pointer + 4] == 'l' && sourceCode[pointer + 5] == 'u' &&
        sourceCode[pointer + 6] == 'd' && sourceCode[pointer + 7] == 'e') {
        pointer += 8;

        while (sourceCode[pointer] == ' ' || sourceCode[pointer] == '\t') {
            ++pointer;
        }

        if (sourceCode[pointer] == '<') {
            ++pointer;

            int k = 0;
            while (sourceCode[pointer] != '\0') {
                if (sourceCode[pointer] == header[k]) {
                    ++pointer;
                    ++k;
                    if (sourceCode[pointer] == '>' && (header[k] == ',' || header[k] == '\0')) {
                        cout << "Header File Found" << endl;
                        return true;
                    }
                } else {
                    while (header[k] != ',' && header[k] != '\0') {
                        ++k;
                    }
                    if (header[k] == ',') {
                        ++k;
                    } else {
                        cout << "No Such Header File Found!!!" << endl;
                        return false;
                    }
                }
            }
        } else {
            cout << "Error! '<' expected after '#include'" << endl;
            return false;
        }
    }
    return false;
}

// Function to tokenize a line of code
int tokenizeLine(const string& line, string* tokens) {
    int numTokens = 0;
    string token = "";
    stringstream ss(line);

    while (ss >> token) {
        tokens[numTokens++] = token;
    }

    return numTokens;
}

int main() {
    // Load C++ keywords from file
    ifstream keywordFile("Desktop/keyword");
    if (!keywordFile.is_open()) {
        cout << "Error opening keyword file." << endl;
        return 1;
    }

    string* keywords = new string[MAX_LINE_LENGTH];
    int numKeywords = 0;
    string keyword;
    while (numKeywords < MAX_LINE_LENGTH && keywordFile >> keyword) {
        keywords[numKeywords++] = keyword;
    }
    keywordFile.close();

    // Open lex_input.txt
    ifstream inputFile("Desktop/lex_input.txt");
    if (!inputFile.is_open()) {
        cout << "Error opening lex_input file." << endl;
        delete[] keywords;
        return 1;
    } else {
        cout << "Input file opened successfully." << endl;
    }

    string header;
    cout << "Enter the header to search for: ";
    cin >> header;

    string line;
    int lineNumber = 1;
    string* tokens = new string[MAX_LINE_LENGTH];
    while (getline(inputFile, line)) {
        // Check for the presence of the header file
        if (isHeader(line, header)) {
            cout << "Header file found in line " << lineNumber << endl;
        }

        // Tokenize the line
        int numTokens = tokenizeLine(line, tokens);
        cout << "Tokenizing line " << lineNumber << ": ";
        // Categorically tokenize every element
        for (int i = 0; i < numTokens; ++i) {
            // Process tokens
        }
        cout << endl;

        lineNumber++;
    }

    inputFile.close();

    delete[] keywords;
    delete[] tokens;

    return 0;
}
