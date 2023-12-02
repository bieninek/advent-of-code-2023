#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream input ("1_2.txt");
    int sum = 0;
    string line;

    while (input >> line) {
        int firstNum, lastNum;
        bool numFound = false;

        for (int i = 0; i < line.size(); i++) {
            if (i+2 < line.size() && line[i] == 'o' && line[i+1] == 'n' && line[i+2] == 'e') {
                line[i] = '1';
            }
            if (i+2 < line.size() && line[i] == 't' && line[i+1] == 'w' && line[i+2] == 'o') {
                line[i] = '2';
            }
            if (i+4 < line.size() && line[i] == 't' && line[i+1] == 'h' && line[i+2] == 'r' && line[i+3] == 'e' && line[i+4] == 'e') {
                line[i] = '3';
            }
            if (i+3 < line.size() && line[i] == 'f' && line[i+1] == 'o' && line[i+2] == 'u' && line[i+3] == 'r') {
                line[i] = '4';
            }
            if (i+3 < line.size() && line[i] == 'f' && line[i+1] == 'i' && line[i+2] == 'v' && line[i+3] == 'e') {
                line[i] = '5';
            }
            if (i+2 < line.size() && line[i] == 's' && line[i+1] == 'i' && line[i+2] == 'x') {
                line[i] = '6';
            }
            if (i+4 < line.size() && line[i] == 's' && line[i+1] == 'e' && line[i+2] == 'v' && line[i+3] == 'e' && line[i+4] == 'n') {
                line[i] = '7';
            }
            if (i+4 < line.size() && line[i] == 'e' && line[i+1] == 'i' && line[i+2] == 'g' && line[i+3] == 'h' && line[i+4] == 't') {
                line[i] = '8';
            }
            if (i+3 < line.size() && line[i] == 'n' && line[i+1] == 'i' && line[i+2] == 'n' && line[i+3] == 'e') {
                line[i] = '9';
            }

            if (line[i] >= '0' && line[i] <= '9') {
                if (!numFound) {
                    numFound = true;
                    firstNum = line[i] - '0';
                }
                lastNum = line[i] - '0';
            }
        }
        sum += firstNum * 10 + lastNum;
    }
    cout << sum << endl;
    return 0;
}
