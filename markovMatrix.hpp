//
// Created by bigmi on 10/13/2019.
//

#ifndef ASSIGNMENT1_MARKOVMATRIX_HPP
#define ASSIGNMENT1_MARKOVMATRIX_HPP


#include "matrix.hpp"

class markovMatrix : public matrix {
public:
    markovMatrix();
    markovMatrix(int);

    markovMatrix(int, int);

    markovMatrix(vector<double>);

    matrix& markovProcess(matrix& m, matrix & n);
    matrix& getRank(matrix& m);

};


#endif //ASSIGNMENT1_MARKOVMATRIX_HPP
