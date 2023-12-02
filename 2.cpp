#include <iostream>
#include <set>
#include <fstream>
using namespace std;

int main() {
    ifstream input ("2.txt");
    string line;

    int gameID;
    set<int> bad; // i use set to avoid duplicates
    bad.clear();

    while (!input.eof()) {
        getline(input, line);
        int i;

        // get gameID
        gameID = 0;
        for (i = 5; line[i] != ':'; i++) {
            gameID *= 10;
            gameID += line[i] - '0';
        }

        // iterates through the rest of line
        // new iteration -> new draw
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
            // finishing the draw, i need to check if the game is impossible
            if (red > 12 || green > 13 || blue > 14 ) {
                bad.insert(gameID); // avoids duplicates
            }
            // go further to avoid infinite loop on ';'
            i++;
        }
    }

    int sumBad = 0;
    for (int elem : bad) {
        sumBad += elem;
    }

    int sumAll = 0;
    for (int i = 0; i <= gameID; i++) {
        sumAll += i;
    }

    cout << sumAll - sumBad << endl;
    return 0;
}
