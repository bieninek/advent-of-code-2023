#include <iostream>
#include <set>
#include <fstream>
using namespace std;

int main() {
    ifstream input ("2.txt");
    string line;

    int sum = 0;

    while (!input.eof()) {
        getline(input, line);
        int i;

        // get gameID
        int gameID = 0;
        for (i = 5; line[i] != ':'; i++) {
            gameID *= 10;
            gameID += line[i] - '0';
        }

        // iterates through the rest of line
        // new iteration -> new draw
        // biggest... keeps the biggest number of balls for each game
        int biggestRed = 0;
        int biggestBlue = 0;
        int biggestGreen = 0;
        while (i < line.size()) {
            int red = 0;
            int green = 0;
            int blue = 0;
            // new draw
            while (i < line.size() && line[i] != ';') {
                int unknown = 0; // this value will be always assigned to a corresponding color
                while (line[i] >= '0' && line[i] <= '9') {
                    unknown *= 10;
                    unknown += line[i] - '0';
                    i++;
                }

                // i have a value, can skip to check which color is corresponding
                i++;
                // three colors assigned
                if (line[i] == 'b') {
                    blue = unknown;
                }
                if (line[i] == 'g' && line[i+1] == 'r') {
                    green = unknown;
                }
                if (line[i] == 'r' && line[i+1] == 'e' && line[i+2] == 'd') {
                    red = unknown;
                }
            }
            // check if this time i need more balls
            if (red > biggestRed) {
                biggestRed = red;
            }
            if (blue > biggestBlue) {
                biggestBlue = blue;
            }
            if (green > biggestGreen) {
                biggestGreen = green;
            }
            // go further to avoid infinite loop on ';'
            i++;
        }
        sum += biggestRed * biggestBlue * biggestGreen;
    }

    cout << sum << endl;
    return 0;
}
