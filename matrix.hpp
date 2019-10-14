//
// Created by bigmi on 10/10/2019.
//

#ifndef ASSIGNMENT1_MATRIX_HPP
#define ASSIGNMENT1_MATRIX_HPP

#include <iostream>
#include <vector>
#include <math.h>
#include <fstream>
#include <iomanip>

#include "exceptions.hpp"
using namespace std;

class matrix {
public:
    matrix();

    matrix(int);

    matrix(int, int);

    matrix(vector<double>);

    ~matrix();

    void setValue(int, int, double);

    int getValue(int, int);

    void clearMatrix();

    friend ostream &operator<<(ostream &out, const matrix &m);

    friend bool operator==(const matrix &m1, const matrix &m2);

    friend bool operator!=(const matrix &m1, const matrix &m2);

    friend matrix &operator+(matrix &m1, matrix &m2);
    friend matrix &operator+=(matrix &m1, matrix &m2);

    friend matrix &operator++(matrix &m1);
    friend matrix &operator++(matrix &m1, int);

    friend matrix &operator--(matrix &m1);
    friend matrix &operator--(matrix &m1, int);

    friend matrix &operator-(matrix &m1, matrix &m2);
    friend matrix &operator-=(matrix &m1, matrix &m2);

    matrix& operator=(matrix &m1);
    friend void mySwap(matrix &m1, matrix &m2);

    friend matrix &operator*(matrix &m1, matrix &m2);
    friend matrix &operator*=(matrix &m1, matrix &m2);
    int getRows();
    int getCols();
    vector<vector<double>> getSquare();

    vector<vector<double>> square;
    matrix& getProbMatrix(matrix& m);
    matrix& getTransitionMatrix(matrix& m);
    matrix& markovProcess(matrix& m, matrix & n);
    matrix& getRank(matrix& m);
    int foo1();
protected:
    vector<double> vector1;
    int cols;
    int rows;
};


#endif //ASSIGNMENT1_MATRIX_HPP
