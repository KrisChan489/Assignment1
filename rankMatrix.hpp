//
// Created by bigmi on 10/13/2019.
//

#ifndef ASSIGNMENT1_RANKMATRIX_HPP
#define ASSIGNMENT1_RANKMATRIX_HPP


#include "matrix.hpp"

class rankMatrix : public matrix {
public:
    rankMatrix();
    rankMatrix(int);

    rankMatrix(int, int);

    rankMatrix(vector<double>);

};


#endif //ASSIGNMENT1_RANKMATRIX_HPP
