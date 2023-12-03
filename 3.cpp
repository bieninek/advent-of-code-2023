#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream input ("3.txt");
    string line;
    vector <vector<char>> data;
    vector <char> temp;

    for (int i = 0; i < 150; i++) {
        temp.push_back('.');
    }
    data.push_back(temp);
    temp.clear();

    while (input >> line) {
        temp.push_back('.');
        for (int i = 0; i < line.size(); i++) {
            temp.push_back(line[i]);
        }
        temp.push_back('.');
        data.push_back(temp);
        temp.clear();
    }

    for (int i = 0; i < 150; i++) {
        temp.push_back('.');
    }
    data.push_back(temp);
    temp.clear();

    // processing numbers - end of input

    int sum = 0;
    for (int i = 1; i < data.size(); i++) {
        for (int j = 1; j < data.at(1).size(); j++) {
            int number = 0;
            int startingPos = -1;
            int endingPos = -1;
            for (;data.at(i).at(j) >= '0' && data.at(i).at(j) <= '9' && j < data.at(1).size(); j++) {
                number *= 10;
                number += data.at(i).at(j) - '0';

                if (startingPos == -1) {
                    startingPos = j;
                }
                endingPos = j;
            }

            if (number == 0) { // no number found
                continue;
            }

            // before the number
            if (data.at(i).at(startingPos-1) != '.' || data.at(i+1).at(startingPos-1) != '.' || data.at(i-1).at(startingPos-1) != '.') {
                sum += number;
                continue;
            }
            // after the number
            if (data.at(i).at(endingPos+1) != '.' || data.at(i+1).at(endingPos+1) != '.' || data.at(i-1).at(endingPos+1) != '.') {
                sum += number;
                continue;
            }
            // above and under the number
            for (; startingPos <= endingPos; startingPos++) {
                if (data.at(i-1).at(startingPos) != '.' || data.at(i+1).at(startingPos) != '.') {
                    sum += number;
                    break;
                }
            }
        }
    }

    cout << sum << endl;

    return 0;
}

