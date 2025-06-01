#include "Grid.h"
#include <fstream>

Grid::Grid(const string& filename) {
    ifstream in(filename);
    in >> size >> size;
    matrix.resize(size, vector<char>(size));
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            in >> matrix[i][j];
    in.close();
}

const vector<vector<char>>& Grid::getData() const {
    return matrix;
}

int Grid::getSize() const {
    return size;
}