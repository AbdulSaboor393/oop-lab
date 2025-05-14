#include <iostream>
#include <sstream>
#include <exception>
using namespace std;

class MatrixMismatch : public exception {
    string msg;
public:
    MatrixMismatch(int aRows, int aCols, int bRows, int bCols) {
        ostringstream out;
        out << "MatrixMismatch: " << aRows << "x" << aCols << " vs " << bRows << "x" << bCols;
        msg = out.str();
    }

    const char* what() const noexcept override {
        return msg.c_str();
    }
};

template <typename T>
class Matrix {
    T** mat;
    int r, c;

public:
    Matrix(int rows, int cols) : r(rows), c(cols) {
        mat = new T*[r];
        for (int i = 0; i < r; ++i) {
            mat[i] = new T[c];
        }
    }

    ~Matrix() {
        for (int i = 0; i < r; ++i) {
            delete[] mat[i];
        }
        delete[] mat;
    }

    void fill() {
        cout << "Enter " << r << "x" << c << " values:\n";
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                cin >> mat[i][j];
            }
        }
    }

    void show() const {
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }

    Matrix<T> operator+(const Matrix<T>& other) {
        if (r != other.r || c != other.c) {
            throw MatrixMismatch(r, c, other.r, other.c);
        }

        Matrix<T> result(r, c);
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                result.mat[i][j] = mat[i][j] + other.mat[i][j];
            }
        }
        return result;
    }
};

int main() {
    try {
        Matrix<int> A(2, 2), B(2, 2), C(3, 2);

        cout << "Matrix A:\n";
        A.fill();

        cout << "Matrix B:\n";
        B.fill();

        Matrix<int> sum = A + B;
        cout << "Sum:\n";
        sum.show();

        Matrix<int> fail = A + C;
    } catch (const MatrixMismatch& ex) {
        cout << "Error: " << ex.what() << endl;
    }

    return 0;
}
