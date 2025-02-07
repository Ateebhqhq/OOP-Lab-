// did this with gpt

#include <iostream>

using namespace std;

int main() {
    int r1, c1, r2, c2;

    cout << "Enter rows and columns for first matrix: ";
    cin >> r1 >> c1;
    cout << "Enter rows and columns for second matrix: ";
    cin >> r2 >> c2;


    int **matrixA = new int*[r1];
    for (int i = 0; i < r1; ++i) {
        matrixA[i] = new int[c1];
    }

    int **matrixB = new int*[r2];
    for (int i = 0; i < r2; ++i) {
        matrixB[i] = new int[c2];
    }

    int **result = new int*[r1];
    for (int i = 0; i < r1; ++i) {
        result[i] = new int[c2];
    }

    cout << "Enter elements of first matrix:" << endl;
    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c1; ++j) {
            cin >> matrixA[i][j];
        }
    }

    cout << "Enter elements of second matrix:" << endl;
    for (int i = 0; i < r2; ++i) {
        for (int j = 0; j < c2; ++j) {
            cin >> matrixB[i][j];
        }
    }

    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c2; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < c1; ++k) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    cout << "Resultant matrix:" << endl;
    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c2; ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < r1; ++i) {
        delete[] matrixA[i];
    }
    delete[] matrixA;

    for (int i = 0; i < r2; ++i) {
        delete[] matrixB[i];
    }
    delete[] matrixB;

    for (int i = 0; i < r1; ++i) {
        delete[] result[i];
    }
    delete[] result;

    return 0;
}