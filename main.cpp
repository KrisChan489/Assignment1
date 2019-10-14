#include "matrix.hpp"

#include "probMatrix.hpp"

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
    auto m2 = new probMatrix(testArray);
    operator<<(cout, *m2);
    auto testMatrix = new matrix(testArray);
    operator<<(cout, *testMatrix);
    auto probMatrix2 = testMatrix->getProbMatrix(*testMatrix);
    operator<<(cout, probMatrix2);
    probMatrix2.getTransitionMatrix(probMatrix2);
    operator<<(cout, probMatrix2);

    auto rankMatrix = new matrix(4, 1);
    operator<<(cout, *rankMatrix);
    for(int i =0; i < probMatrix2.getRows(); i++) {
        rankMatrix->square.at(i).at(0) = 1.0;
    }
    auto *markov = new matrix(4, 1);
    *markov = probMatrix2.markovProcess(probMatrix2, *rankMatrix);
    operator<<(cout, *markov);
    markov->getRank(*markov);

    delete markov;
    delete testMatrix;
    delete rankMatrix;
}
int main() {
    runProgram();
    return 0;
}

