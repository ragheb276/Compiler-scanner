#include<vector>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<ctype.h>
#include<fstream>
#include <cstdlib>
using namespace std;

int isreservedword(char buffer[]) {
    char reservedwords[][10] = { "break","while","char","const","if","default", // one can add any reservedword he needs in here
                            "do","double","else","float","for","goto",
                            "integer","return","read","call","set","endwhile",
                            "enduntil","until","end","begin","then","write", };
     int i, flag = 0;
    for (i = 0; i < 25; ++i) {
        if (strcmp(reservedwords[i], buffer) == 0) {
            flag = 1;
            break;
        }
    }
    return flag;
}
int main() {
    char ch, buffer[15], b[30], logical_op[] = "><!", math_op[] = "+-*/=", numer[] = ".0123456789";
    ifstream fin("E://input.txt"); // Reading a file named input 
    bool pass;
    int i, j = 0, aaa = 0;
    vector <string>reservedword;
    vector<string>identifier;
    vector<char>logical;
    vector<char>math;
    vector<string>number;
    if (!fin.is_open()) { // checking if the file is opened or not 
        cout << "error while opening the file\n";
        exit(0);
    }
    ofstream f1("E://output.txt"); //creating a new file called output to hold the output
    while (!fin.eof()) {
        ch = fin.get();
        if (ch == 123) { // the comments in the language 
             pass = false;
        }
        else if (ch == 125) {
             pass = true;
        };

        if (pass) {
       
            if (ch == 59) {  // checking semi colon 
                cout << ";" << "|" << "semi-colon" << "\n";
                f1 << ";" << "|" << "semi-colon" << "\n";
            }

            if (ch == 40) {        // checking left bracket    
                cout << "(" << "|" << "Left-bracket" << "\n";
                f1 << "(" << "|" << "Left-bracket" << "\n";
            }
            if (ch == 41) {   // checking Right bracket
                cout << ")" << "|" << "Right-bracket" << "\n";
                f1 << ")" << "|" << "Right-bracket" << "\n";
            }
        for (i = 0; i < 5; ++i) {   //checking the math operators 
            if (ch == math_op[i]) {
                math.push_back(ch);
                cout << math[0] << "|" << "math-operator" << "\n";
                f1 << math[0] << "|" << "math-operator" << "\n";
                math.pop_back();
            }
        }
        for (i = 0; i < 3; ++i) { // checking the logical operator
            if (ch == logical_op[i]) {
                logical.push_back(ch);
                cout << logical[0] << "|" << "logical-operator" << "\n";
                f1 << logical[0] << "|" << "logical-operator" << "\n";
                logical.pop_back();
            }
        }
        if (ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9' || ch == '.' || ch == ' ' || ch == '\n' || ch == ';') {
            if (ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9' || ch == '.')b[aaa++] = ch;
            if ((ch == ' ' || ch == '\n' || ch == ';') && (aaa != 0)) {
                b[aaa] = '\0';  
                aaa = 0;
                char arr[30];
                strcpy_s(arr, b);
                number.push_back(arr);
                cout << number[0] << "|" << "number" << "\n";
                f1 << number[0] << "|" << "number" << "\n";
                number.pop_back();
            }
        }


        if (isalnum(ch)) {
            buffer[j++] = ch;
        }
        else if ((ch == ' ' || ch == '\n') && (j != 0)) {
            buffer[j] = '\0';
            j = 0;

            if (isreservedword(buffer) == 1) {
                reservedword.push_back(buffer);
                cout << reservedword[0] << "|" << "reservedword" << "\n";
                f1 << reservedword[0] << "|" << "reservedword" << "\n";
                reservedword.pop_back();
            }
            else {
                if (buffer[0] >= 97 && buffer[0] <= 122) {

                    char arrr[30];
                    strcpy_s(arrr, buffer);
                    identifier.push_back(arrr);
                    cout << identifier[0] << "|" << "identifier" << "\n";
                    f1 << identifier[0] << "|" << "identifier" << "\n";
                    identifier.pop_back();

                }
            }
        }

    }
    }
    fin.close(); //closing the input file 
    f1.close(); //closing the output file 
    system("pause");
    return 0;
}
