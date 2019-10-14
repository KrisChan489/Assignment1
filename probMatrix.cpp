//
// Created by bigmi on 10/13/2019.
//

#include "probMatrix.hpp"

probMatrix::probMatrix() {

}

probMatrix::probMatrix(vector<double> vector1) : matrix(vector1){

}

probMatrix::probMatrix(int r, int c) : matrix(rows, cols) {

}



probMatrix::probMatrix(int n) : matrix(n) {

}

int probMatrix::foo2 () {
    cout << "ass" << endl;
}