#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream input ("1.txt");
    int sum = 0;
    string line;

    while (input >> line) {
        int firstNum, lastNum;
        bool numFound = false;

        for (int i = 0; i < line.size(); i++) {
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
