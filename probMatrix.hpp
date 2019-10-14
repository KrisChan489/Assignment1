//
// Created by bigmi on 10/13/2019.
//

#ifndef ASSIGNMENT1_PROBMATRIX_HPP
#define ASSIGNMENT1_PROBMATRIX_HPP

#include "matrix.hpp"

class probMatrix : public matrix{
public:
    probMatrix();
    probMatrix(int);

    probMatrix(int, int);

    probMatrix(vector<double>);
    int foo2 ();
};


#endif //ASSIGNMENT1_PROBMATRIX_HPP
