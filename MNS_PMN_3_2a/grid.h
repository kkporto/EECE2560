#ifndef GRID_H
#define GRID_H

#include <vector>
#include <string>
using namespace std;

class Grid {
public:
    Grid(const string& filename);
    const vector<vector<char>>& getData() const;
    int getSize() const;

private:
    vector<vector<char>> matrix;
    int size;
};

#endif