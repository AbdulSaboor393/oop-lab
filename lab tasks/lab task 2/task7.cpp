#include <iostream>

using namespace std;

int main() {
    int rows1, cols1, rows2, cols2;

    cout << "Enter the dimensions of the first matrix (rows columns): ";
    cin >> rows1 >> cols1;

    cout << "Enter the dimensions of the second matrix (rows columns): ";
    cin >> rows2 >> cols2;

    if (cols1 != rows2) {
        cout << "Matrix multiplication not possible. Columns of first matrix must equal rows of second matrix." << endl;
        return 0;
    }

    int** mat1 = new int*[rows1];
    int** mat2 = new int*[rows2];
    int** result = new int*[rows1];

    for (int i = 0; i < rows1; i++) mat1[i] = new int[cols1];
    for (int i = 0; i < rows2; i++) mat2[i] = new int[cols2];
    for (int i = 0; i < rows1; i++) result[i] = new int[cols2];

    cout << "Enter elements of first matrix:" << endl;
    for (int i = 0; i < rows1; i++)
        for (int j = 0; j < cols1; j++)
            cin >> mat1[i][j];

    cout << "Enter elements of second matrix:" << endl;
    for (int i = 0; i < rows2; i++)
        for (int j = 0; j < cols2; j++)
            cin >> mat2[i][j];

    for (int i = 0; i < rows1; i++)
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++)
                result[i][j] += mat1[i][k] * mat2[k][j];
        }

    cout << "Resultant Matrix:" << endl;
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++)
            cout << result[i][j] << " ";
        cout << endl;
    }

    for (int i = 0; i < rows1; i++) delete[] mat1[i];
    for (int i = 0; i < rows2; i++) delete[] mat2[i];
    for (int i = 0; i < rows1; i++) delete[] result[i];

    delete[] mat1;
    delete[] mat2;
    delete[] result;

    return 0;
}
