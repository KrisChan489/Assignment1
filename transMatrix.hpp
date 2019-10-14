//
// Created by bigmi on 10/13/2019.
//

#include "matrix.hpp"

#ifndef ASSIGNMENT1_TRANSMATRIX_HPP
#define ASSIGNMENT1_TRANSMATRIX_HPP


class transMatrix : public matrix {
public:
    transMatrix();
    transMatrix(int);

    transMatrix(int, int);

    transMatrix(vector<double>);

    matrix& getTransitionMatrix(matrix &m);
};


#endif //ASSIGNMENT1_TRANSMATRIX_HPP
