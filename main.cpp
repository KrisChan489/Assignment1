#include "matrix.hpp"

#include "probMatrix.hpp"
#include "transMatrix.hpp"
#include "rankMatrix.hpp"
#include "markovMatrix.hpp"

static vector<double> openFile(const string& title) {
    fstream file;
    vector<double> matrix;
    matrix.resize(16);
    file.open(title);
    if (!file.is_open()) {
        cerr<< "Unable to open file" << endl;
        exit(1);
    }
    int count = 0;
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            file >> matrix[count++];
        }
    }
    file.close();
    return matrix;
}

static void runProgram() {
    vector<double> testArray = openFile("connectivity.txt");
    auto pMatrix = new probMatrix(testArray); //matrix to call methods
    operator<<(cout, *pMatrix);
    auto probMatrix2 = pMatrix->getProbMatrix(*pMatrix);
    operator<<(cout, probMatrix2);
    auto tm2 = new transMatrix(testArray); //matrix to call methods
    auto transMatrix2 = tm2->getTransitionMatrix(probMatrix2);
    operator<<(cout, transMatrix2);

    auto *rMatrix = new rankMatrix(4, 1);
    for(int i =0; i < transMatrix2.getRows(); i++) {
        rMatrix->square.at(i).at(0) = 1.0;
    }
    operator<<(cout, *rMatrix);
    auto *markov = new markovMatrix(4, 1); //matrix to call methods
    auto postMarkov = markov->markovProcess(probMatrix2, *rMatrix);
    operator<<(cout, postMarkov);
    markov->getRank(postMarkov);

    delete pMatrix;
    delete markov;
    delete tm2;
    delete rMatrix;
}

int main() {
    runProgram();
    return 0;
}

