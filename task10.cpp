#include <iostream>

using namespace std;

int main() {
    int layers, rows, cols;

    cout << "Enter number of layers: ";
    cin >> layers;
    cout << "Enter number of rows per layer: ";
    cin >> rows;
    cout << "Enter number of columns per row: ";
    cin >> cols;

    int*** arr = new int**[layers];
    for (int i = 0; i < layers; ++i) {
        arr[i] = new int*[rows];
        for (int j = 0; j < rows; ++j) {
            arr[i][j] = new int[cols];
        }
    }

    cout << "Enter elements of the 3D array:" << endl;
    for (int i = 0; i < layers; ++i) {
        for (int j = 0; j < rows; ++j) {
            for (int k = 0; k < cols; ++k) {
                cin >> arr[i][j][k];
            }
        }
    }

    cout << "3D Array Contents:" << endl;
    for (int i = 0; i < layers; ++i) {
        cout << "Layer " << i + 1 << endl;
        for (int j = 0; j < rows; ++j) {
            for (int k = 0; k < cols; ++k) {
                cout << arr[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }


    delete[] arr;

    return 0;
}