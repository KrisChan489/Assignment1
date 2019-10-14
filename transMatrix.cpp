//
// Created by bigmi on 10/13/2019.
//

#include "transMatrix.hpp"

transMatrix::transMatrix() {

}

transMatrix::transMatrix(vector<double> vector1) : matrix(vector1){

}

transMatrix::transMatrix(int rows, int cols) : matrix(rows, cols) {

}

/**
 * Returns a transition matrix
 * @param m
 * @return
 */
matrix &transMatrix::getTransitionMatrix(matrix &m) {
    for(int i = 0; i < m.getRows(); i++) {
        for(int j = 0; j < m.getCols(); j++)
            m.square[i][j] *= 0.85;
    }
    auto q = new matrix(m.getRows(), m.getCols());
    for(int i = 0; i < m.getCols(); i++) {
        for (int k = 0; k < m.getRows(); k++)
            q->square.at(k).at(i) = (double) (1.0 / m.getRows());
    }
    for(int i = 0; i < m.getCols(); i++) {
        for (int k = 0; k < m.getRows(); k++)
            q->square.at(k).at(i) *= 0.15;
    }
    operator+=(m, *q);
    return m;
}



transMatrix::transMatrix(int n) : matrix(n) {

}