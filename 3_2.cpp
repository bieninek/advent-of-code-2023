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

    int counters[data.size()][data.at(1).size()];
    int mult[data.size()][data.at(1).size()];
    for (int i = 0; i < data.size(); i++) {
        for (int j = 0; j < data.at(1).size(); j++) {
            counters[i][j] = 0;
            mult[i][j] = 1;
        }
    }

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
            for (int pos = i-1; pos <= i+1; pos++) {
                if (data.at(pos).at(startingPos-1) == '*') {
                    counters[pos][startingPos-1] ++;
                    mult[pos][startingPos-1] *= number;
                    continue;
                }
            }
            // after the number
            for (int pos = i-1; pos <= i+1; pos++) {
                if (data.at(pos).at(endingPos+1) == '*') {
                    counters[pos][endingPos+1] ++;
                    mult[pos][endingPos+1] *= number;
                    continue;
                }
            }
            // above and under the number
            for (; startingPos <= endingPos; startingPos++) {
                if (data.at(i-1).at(startingPos) == '*') {
                    counters[i-1][startingPos] ++;
                    mult[i-1][startingPos] *= number;
                    break;
                }
                if (data.at(i+1).at(startingPos) == '*') {
                    counters[i+1][startingPos] ++;
                    mult[i+1][startingPos] *= number;
                    break;
                }
            }
        }
    }

    int sum = 0;
    for (int i = 1; i < data.size(); i++) {
        for (int j = 1; j < data.at(1).size(); j++) {
            if (counters[i][j] == 2) {
                sum += mult[i][j];
            }
        }
    }

    cout << sum << endl;

    return 0;
}

