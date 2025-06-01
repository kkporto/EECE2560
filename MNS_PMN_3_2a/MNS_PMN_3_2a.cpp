// MNS_PMN_3_2a.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Dictionary.h"
#include "Grid.h"
#include <iostream>
#include <ostream>

const int MINLEN = 5;
const int DIRS[8][2] = {
    {0,1}, {1,0}, {0,-1}, {-1,0},
    {1,1}, {1,-1}, {-1,1}, {-1,-1}
};

void findMatches(const Dictionary& d, const Grid& g) {
    const auto& mat = g.getData();
    int n = g.getSize();
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            for (auto dir : DIRS) {
                string word;
                for (int len = 0; len < n; len++) {
                    int i = (x + dir[0] * len + n) % n;
                    int j = (y + dir[1] * len + n) % n;
                    word += mat[i][j];
                    //cout << "Trying: " << word << endl;
                    if (word.length() >= MINLEN && d.binarySearch(word) != -1)
                        cout << word << endl;
                }
            }
        }
    }
}

void search() {
    string gridFile, dictionaryFile;
    cout << "Enter dictionary filename (no path assumes within the same folder): ";
    cin >> dictionaryFile;
    cout << "Enter grid filename (no path assumes within the same folder): ";
    cin >> gridFile;

    Dictionary dict(dictionaryFile);
    dict.selectionSort();
    cout << dict;

    Grid g(gridFile);

    findMatches(dict, g);
}

int main() {
    search();
    return 0;
}



