#include <iostream>
using namespace std;
int main()
{
    int rows_1, rows_2, cols_1, cols_2;
    cout << "Enter the dimensions of the first matrix" << endl;
    cin >> rows_1 >> cols_1;
    cout << "Enter the dimensions of the second matrix" << endl;
    cin >> rows_2 >> cols_2;
    if (rows_1 != rows_2 || cols_1 != cols_2)
    {
        cout << "Matrix addition or subtraction is not possible.The dimesions must be same." << endl;
        return 1;
    }
    int **matrix_1 = new int *[rows_1];
    for (int i = 0; i < rows_1; i++)
    {
        matrix_1[i] = new int[cols_1];
    }
    int **matrix_2 = new int *[rows_2];
    for (int i = 0; i < rows_2; i++)
    {
        matrix_2[i] = new int[cols_2];
    }
    int **result = new int *[rows_1];
    for (int i = 0; i < rows_1; i++)
    {
        result[i] = new int[cols_1];
    }

    cout << "Enter the elements for the first matrix" << endl;
    for (int i = 0; i < rows_1; i++)
    {
        for (int j = 0; j < cols_1; j++)
        {
            cin >> matrix_1[i][j];
        }
    }
    cout << "Enter the elements for the second matrix" << endl;
    for (int i = 0; i < rows_2; i++)
    {
        for (int j = 0; j < cols_2; j++)
        {
            cin >> matrix_2[i][j];
        }
    }

    for (int i = 0; i < rows_1; i++)
    {
        for (int j = 0; j < cols_1; j++)
        {
            result[i][j] = matrix_1[i][j] + matrix_2[i][j];
        }
    }
    cout << "Resultant matrix after addition." << endl;
    for (int i = 0; i < rows_1; i++)
    {
        for (int j = 0; j < cols_1; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < rows_1; i++)
    {
        for (int j = 0; j < cols_1; j++)
        {
            result[i][j] = matrix_1[i][j] - matrix_2[i][j];
        }
    }
    cout << "Resultant matrix after subtraction." << endl;
    for (int i = 0; i < rows_1; i++)
    {
        for (int j = 0; j < cols_1; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;

    }
    for (int i = 0; i < rows_1; i++)
    {
        delete[] matrix_1[i];
        delete[] matrix_2[i];
        delete[] result[i];
    }
    delete[] matrix_1;
    delete[] matrix_2;
    delete[] result;
    


    return 0;
}

