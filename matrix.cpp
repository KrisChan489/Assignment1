//
// Created by bigmi on 10/10/2019.
//

#include "matrix.hpp"

/**
 * Default Constructor.
 */
matrix::matrix() {
    square = vector<vector<double>>(1, vector<double>(1, 0.0));
    cout << "matrix created" << endl;
    rows = 1;
    cols = 1;
}

/**
 * Single Int constructor
 * @param n size of matrix (rows/cols)
 */
matrix::matrix(int n) {
    try {
        if(n < 1)
            throw numBelowZeroException();
        square.resize(n, vector<double>(n));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++){
                square[i][j] = 0.0;
            }
        }
        rows = n;
        cols = n;
    } catch (numBelowZeroException& e) {
        cout << e.what() << endl;
    }



}

/**
 * 2 param constructor
 * @param r rows of matrix
 * @param c cols of matrix
 */
matrix::matrix(int r, int c) {
    try {
        if(r < 1 || c < 1)
                throw numBelowZeroException();
        square.resize(r, vector<double>(c));
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++){
                square[i][j] = 0.0;
            }
        }
        rows = r;
        cols = c;
    } catch (numBelowZeroException& e) {
        cout << e.what() << endl;
    }

}

/**
 * constructor with vector
 * @param array vector used to build matrix
 */
matrix::matrix(vector<double> array) {
    int count = 0;
    vector1 = array;
    int x = sqrt(array.size());
    try {
        if((int) array.size() != (x * x))
            throw notPerfectSquareException();
        square.resize(x, vector<double>(x));
        for(int i = 0; i < x; i++) {
            for(int j = 0; j < x; j++){
                square[i][j] = array[count++];
            }
        }
        rows = x;
        cols = x;
    } catch (notPerfectSquareException& e) {
        cout << e.what() << endl;
    }


}

/**
 * clears matrix with 0s
 */
void matrix::clearMatrix() {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++){
            square[i][j] = 0.0;
        }
    }
}

matrix::~matrix() {
    square.resize(0, vector<double>(0));
}



/**
 * Overloaded insertion operator
 * @param out the ostream to insert to
 * @param m matrix to insert
 * @return the ostream
 */
ostream &operator<<(ostream &out, const matrix &m) {
    out << "==========================" << endl;
    for(int i = 0; i < m.rows; i++) {
        for(int j = 0; j < m.cols; j++){
            out << fixed << showpoint << setprecision(3) << m.square[i][j] << "\t";
        }
        out << endl;
    }
    out << "==========================" << endl;
    return out;
}

/**
 * Overloaded equality operator
 * @param m1 matrix 1
 * @param m2 matrix 2
 * @return true if all values in matrix are equal (0.001 tolerance), else false
 */
bool operator==(const matrix &m1, const matrix &m2) {
    if(m1.square.size() == m2.square.size()) {
        for(int i = 0; i < m1.rows; i++) {
            for(int j = 0; j < m1.cols; j++) {
                if(abs(m1.square[i][j] - m2.square[i][j]) > 0.001) {
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}

/**
 * Overloaded inequality operator
 * @param m1 matrix 1
 * @param m2 matrix 2
 * @return false if all values in matrix are equal (0.001 tolerance), else true
 */
bool operator!=(const matrix &m1, const matrix &m2) {
    if(m1.square.size() == m2.square.size()) {
        for(int i = 0; i < m1.rows; i++) {
            for(int j = 0; j < m1.cols; j++) {
                if(abs(m1.square[i][j] - m2.square[i][j]) > 0.001) {
                    return true;
                }
            }
        }
        return false;
    }
    return true;
}

/**
 * Overloaded addition operator
 * @param m1 matrix 1
 * @param m2 matrix 2
 * @return the added matrix
 */
matrix& operator+(matrix &m1, matrix &m2) {
    try {
        if((m1.square.size() != m2.square.size()) || (m1.square[0].size() != m2.square[0].size()))
            throw matrixSizeMismatchException();
        matrix *newM = new matrix(m1.rows, m1.cols);
        for(int i = 0; i < m1.rows; i++) {
            for (int j = 0; j < m1.cols; j++)
                newM->square[i][j] = m1.square[i][j] + m2.square[i][j];
        }
        return *newM;
    } catch (matrixSizeMismatchException& e) {
        cout << e.what() << endl;
     return m1;
    }

}

/**
 * Overloaded addition assignment operator
 * @param m1 matrix 1
 * @param m2 matrix 2
 * @return the added matrix
 */
matrix &operator+=(matrix &m1, matrix &m2) {
    try {
        if((m1.square.size() != m2.square.size())  || (m1.square[0].size() != m2.square[0].size()))
            throw matrixSizeMismatchException();
        for(int i = 0; i < m1.rows; i++)
            for(int j = 0; j < m1.cols; j++)
                m1.square[i][j] += m2.square[i][j];
        return m1;
    } catch (matrixSizeMismatchException& e) {
        cout << e.what() <<endl;
        return m1;
    }



}

/**
 * Overloaded subtraction operator
 * @param m1 matrix 1
 * @param m2 matrix 2
 * @return the subtracted matrix
 */
matrix& operator-(matrix &m1, matrix &m2) {
    try {
        if((m1.square.size() != m2.square.size()) || (m1.square[0].size() != m2.square[0].size()))
            throw matrixSizeMismatchException();
        matrix *newM = new matrix(m1.rows, m1.cols);
        for(int i = 0; i < m1.rows; i++)
            for(int j = 0; j < m1.cols; j++)
                newM->square[i][j] = m1.square[i][j] - m2.square[i][j];
        return *newM;
    } catch (matrixSizeMismatchException& e) {
        cout << e.what() << endl;
        return m1;
    }

}

/**
 * Overloaded subtraction assignment operator
 * @param m1 matrix 1
 * @param m2 matrix 2
 * @return the subtracted matrix
 */
matrix &operator-=(matrix &m1, matrix &m2) {
    try {
        if((m1.square.size() != m2.square.size()) || (m1.square[0].size() != m2.square[0].size()))
            throw matrixSizeMismatchException();
        for(int i = 0; i < m1.rows; i++)
            for(int j = 0; j < m1.cols; j++)
                m1.square[i][j] -= m2.square[i][j];
        return m1;
    } catch (matrixSizeMismatchException& e) {
        cout << e.what() << endl;
        return m1;
    }

}

/**
 * Overloaded pre-increment operator
 * @param m1 matrix 1
 * @return the incremented matrix
 */
matrix &operator++(matrix &m1) {
    for(int i = 0; i < m1.rows; i++) {
        for(int j = 0; j < m1.cols; j++)
            m1.square[i][j] += 1.0;
    }
    return m1;
}

/**
 * Overloaded post-increment operator
 * @param m1 matrix 1
 * @return the incremented matrix
 */
matrix &operator++(matrix &m1, int) {
    matrix &m2 = m1;
    operator++(m1);
    return m2;
}


/**
 * Overloaded pre-decrement operator
 * @param m1 matrix 1
 * @return the decremented matrix
 */
matrix &operator--(matrix &m1) {
    for(int i = 0; i < m1.rows; i++) {
        for(int j = 0; j < m1.cols; j++)
            m1.square[i][j] -= 1.0;
    }
    return m1;
}

/**
 * Overloaded post-decrement operator
 * @param m1 matrix 1
 * @return the decremented matrix
 */
matrix &operator--(matrix &m1, int) {
    matrix &m2  = m1;
    operator--(m1);
    return m2;
}

/**
 * Gets value of matrix at desired row & col
 * @param r row to check
 * @param c col to check
 * @return value at row if inbound, else failure
 */
int matrix::getValue(int r, int c) {
    try {
        if(r < 1 || c < 1)
            throw numBelowZeroException();
        return square[r][c];
    } catch (numBelowZeroException& e) {
        cout << e.what() << endl;
        return EXIT_FAILURE;
    }

}

/**
 * sets value given to matrix row/col given
 * @param r row
 * @param c col
 * @param val value to set
 */
void matrix::setValue(int r, int c, double val) {
    try {
        if(r < 1 || c < 1)
            throw numBelowZeroException();
        square[r][c] = val;
    } catch (numBelowZeroException& e) {
        cout << e.what() << endl;
    }

}

/**
 * Overloaded multiplication assignment operator
 * @param m1 matrix 1
 * @param m2 matrix 2
 * @return the multiplied matrix if successful, else the first matrix
 */
matrix &operator*=(matrix &m1, matrix &m2) {
    try {
        if(m1.cols != m2.rows)
            throw matrixMultSizeException();
        m1 = m1 * m2;
        return m1;
    } catch (matrixMultSizeException& e) {
        cout << e.what() << endl;
        return m1;
    }

}

/**
 * Overloaded multiplication assignment operator
 * @param m1 matrix 1
 * @param m2 matrix 2
 * @return the multiplied matrix if successful, else the first matrix
 */
matrix &operator*(matrix &m1, matrix &m2) {
    try {
        if(m1.cols != m2.rows)
            throw matrixMultSizeException();
        matrix *newM = new matrix(m1.rows, m2.cols);
        for(int i = 0; i < m1.rows; i++)
            for(int j = 0; j < m1.cols; j++)
                for(int k = 0; k < m1.cols; k++)
                    newM->square[i][j] += m1.square[i][k] * m2.square[k][j];
        return *newM;
    } catch (matrixMultSizeException& e) {
        cout << e.what() << endl;
        return m1;
    }

}

/**
 * swaps the two matrices
 * @param m1 first matrix
 * @param m2 second matrix
 */
void mySwap(matrix &m1, matrix &m2) {
    using std::swap;
    swap(m1.square, m2.square);
}

/**
 * Overloaded assignment operator
 * @param m1 matrix to assign
 * @return assigned matrix
 */
matrix &matrix::operator=(matrix &m1) {
    mySwap(*this, m1);
    return *this;
}
/**
 * gets the square
 * @return the square
 */
vector<vector<double>>  matrix::getSquare() {
    return square;
}

/**
 * gets the rows of the matrix
 * @return rows of matrix
 */
int matrix::getCols() {
    return cols;
}

/**
 * gets cols of matrix
 * @return cols of matrix
 */
int matrix::getRows() {
    return rows;
}











