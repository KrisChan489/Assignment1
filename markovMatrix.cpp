//
// Created by bigmi on 10/13/2019.
//

#include "markovMatrix.hpp"

markovMatrix::markovMatrix(int row, int col) : matrix(row ,col){

}

markovMatrix::markovMatrix(vector<double> vector1) : matrix(vector1){

}

markovMatrix::markovMatrix(int n) : matrix(n){

}

/**
 * Performs the markov process on a matrix
 * @param m
 * @param n
 * @return
 */
matrix &markovMatrix::markovProcess(matrix &m, matrix &n) {
    double top = n.square.at(0).at(0);
    n = operator*(m, n);
    if(top != n.square.at(0).at(0))
        markovProcess(m, n);
    return n;
}

/**
 * Determines the rank percentages for the pages
 * @param m
 * @return
 */
matrix &markovMatrix::getRank(matrix &m) {
    double total = 0.0;
    for(int i = 0; i < m.getRows(); i++) {
        for(int j = 0; j < m.getCols(); j++)
            total += m.square.at(i).at(j);
    }
    for(int i = 0; i < m.getRows(); i++) {
        for(int j = 0; j < m.getCols(); j++) {
            m.square.at(i).at(j) /= total;
            m.square.at(i).at(j) *= 100;
        }
    }
    char letters[]= {'A', 'B', 'C', 'D'};
    for(int i = 0; i < m.getRows(); i++) {
        for(int j = 0; j < m.getCols(); j++) {
            cout << "Page " << letters[i] << ": " << setprecision(2) << m.square.at(i).at(j) << "%" <<  endl;
        }
    }
    return m;
}