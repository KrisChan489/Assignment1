//
// Created by bigmi on 10/13/2019.
//

#include "probMatrix.hpp"

probMatrix::probMatrix() {

}

probMatrix::probMatrix(vector<double> vector1) : matrix(vector1){

}

probMatrix::probMatrix(int rows, int cols) : matrix(rows, cols) {

}



probMatrix::probMatrix(int n) : matrix(n) {

}

/**
 * Returns a probability matrix
 * @param m
 * @return
 */
matrix& probMatrix::getProbMatrix(matrix& m) {
    double total = 0.0;
    auto *mat = new matrix(m.getRows(), m.getCols());
    mat->operator=(m);
    for(int i = 0; i < m.getCols(); i++) {
        for(int j = 0; j < m.getRows(); j++) {
            total += mat->square.at(j).at(i);
        }
        if(total == 0) {
            for (int k = 0; k < m.getRows(); k++)
                mat->square.at(k).at(i) = (double)(1.0/m.getRows());
        }
        else {
            for (int l = 0; l < m.getRows(); l++)
                mat->square.at(l).at(i) /= total;
        }
        total = 0;
    }
    return *mat;
}