//
// Created by bigmi on 10/13/2019.
//

#ifndef ASSIGNMENT1_EXCEPTIONS_HPP
#define ASSIGNMENT1_EXCEPTIONS_HPP

#include <exception>

using namespace std;

struct  numBelowZeroException : public exception {
    const char * what() const throw() {
        return "Numbers must be above zero.";
    }

};

struct  notPerfectSquareException : public exception {
    const char * what() const throw() {
        return "The size of the matrix must be a perfect square";
    }

};

struct  outOfBoundsException : public exception {
    const char * what() const throw() {
        return "The index provided is out of bounds.";
    }

};

struct  matrixSizeMismatchException : public exception {
    const char * what() const throw() {
        return "Matrices must be the same size.";
    }

};

struct  matrixMultSizeException : public exception {
    const char * what() const throw() {
        return "The columns of the first matrix must equal the rows of the second matrix.";
    }

};

#endif //ASSIGNMENT1_EXCEPTIONS_HPP
