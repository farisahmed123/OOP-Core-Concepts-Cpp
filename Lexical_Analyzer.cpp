#include <iostream>
#include <fstream>

using namespace std;

// List of keywords
string keywords[] = {"int", "float", "string", "bool", "if", "else", "while", "for",
                     "return", "true", "false", "func", "break", "continue"};

// Function to check if a word is a keyword
bool isKeyword(string word) {
    for (int i = 0; i < 13; i++) {
        if (keywords[i] == word) return true;
    }
    return false;
}

// Function to check if a word is a valid identifier
bool isIdentifier(string word) {
    if (word.empty() || !(word[0] >= 'a' && word[0] <= 'z')) return false;
    
    for (int i = 0; i < word.length(); i++) {
        if (!((word[i] >= 'a' && word[i] <= 'z') || (word[i] >= '0' && word[i] <= '9') || word[i] == '-')) {
            return false;
        }
    }
    return true;
}

int main() {
    ifstream inputFile("Sample.txt");  // Open source file
    ofstream outputFile("symbol_table.txt"); // Create output file

    if (!inputFile || !outputFile) {
        cout << "Error: Unable to open file!" << endl;
        return 1;
    }

    string token;
    char character;

    while (inputFile.get(character)) {
        if (character == ' ' || character == '\n' || character == '\t') continue;

        if ((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z')) {
            token = character;
            while (inputFile.get(character) && ((character >= 'a' && character <= 'z') || 
                                                (character >= '0' && character <= '9') || 
                                                 character == '-')) {
                token += character;
            }
            inputFile.putback(character);

            if (isKeyword(token)) outputFile << "KEYWORD: " << token << endl;
            else if (isIdentifier(token)) outputFile << "IDENTIFIER: " << token << endl;
        }
        else if (character >= '0' && character <= '9') {
            token = character;
            while (inputFile.get(character) && (character >= '0' && character <= '9')) token += character;
            inputFile.putback(character);
            outputFile << "NUMBER: " << token << endl;
        }
        else if (character == '(' || character == ')' || character == '{' || character == '}' || 
                 character == '[' || character == ']') {
            outputFile << "PARENTHESIS: " << character << endl;
        }
        else if (character == '#') {
            outputFile << "END_STATEMENT: #" << endl;
        }
        else {
            token = character;
            char nextChar = inputFile.peek();

            if ((character == '=' && nextChar == '=') || (character == '!' && nextChar == '=') ||
                (character == '>' && nextChar == '=') || (character == '<' && nextChar == '=') ||
                (character == '&' && nextChar == '&') || (character == '|' && nextChar == '|') ||
                (character == ':' && nextChar == '=')) {
                inputFile.get(nextChar);
                token += nextChar;
            }
            outputFile << "OPERATOR: " << token << endl;
        }
    }

    inputFile.close();
    outputFile.close();
    cout << "Lexical analysis completed. Check 'symbol_table.txt'." << endl;
    return 0;
}

