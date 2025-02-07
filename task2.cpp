#include <iostream>

using namespace std;

int main() {
    int rows1, cols1, rows2, cols2;

    cout << "Enter rows and columns for first matrix: ";
    cin >> rows1 >> cols1;
    cout << "Enter rows and columns for second matrix: ";
    cin >> rows2 >> cols2;


    int **matrixA = new int*[rows1];
    for (int i = 0; i < rows1; ++i) {
        matrixA[i] = new int[cols1];
    }

    int **matrixB = new int*[rows2];
    for (int i = 0; i < rows2; ++i) {
        matrixB[i] = new int[cols2];
    }

    int **resultAdd = new int*[rows1];
    int **resultSub = new int*[rows1];
    for (int i = 0; i < rows1; ++i) {
        resultAdd[i] = new int[cols1];
        resultSub[i] = new int[cols1];
    }

    cout << "Enter elements of first matrix:" << endl;
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols1; ++j) {
            cin >> matrixA[i][j];
        }
    }

    cout << "Enter elements of second matrix:" << endl;
    for (int i = 0; i < rows2; ++i) {
        for (int j = 0; j < cols2; ++j) {
            cin >> matrixB[i][j];
        }
    }

    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols1; ++j) {
            resultAdd[i][j] = matrixA[i][j] + matrixB[i][j];
            resultSub[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }

    cout << "Addition:" << endl;
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols1; ++j) {
            cout << resultAdd[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Subtraction:" << endl;
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols1; ++j) {
            cout << resultSub[i][j] << " ";
        }
        cout << endl;
    }


    delete[] matrixA;
    delete[] matrixB;
    delete[] resultAdd;
    delete[] resultSub;

    return 0;
}