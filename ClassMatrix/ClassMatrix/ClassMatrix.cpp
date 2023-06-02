#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

class Matrix {
private:
    vector<vector<double>> data;
    int rows;
    int cols;

public:
    Matrix(int rows, int cols) {
        this->cols = cols;
        this->rows = rows;
        data.resize(rows, vector<double>(cols));
    }

    void read_from_file(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Error: cannot open file " << filename << endl;
            return;
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                file >> data[i][j];
            }
        }

        file.close();
    }

    void multiply_by_scalar(double scalar) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                data[i][j] *= scalar;
            }
        }
    }

    Matrix multiply_by_matrix(const Matrix& other) const {
        if (cols != other.rows) {
            cerr << "Error: cannot multiply matrices with incompatible dimensions" << endl;
            return Matrix(0, 0);
        }

        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                double sum = 0;
                for (int k = 0; k < cols; k++) {
                    sum += data[i][k] * other.data[k][j];
                }
                result.data[i][j] = sum;
            }
        }

        return result;
    }

    void to_upper_triangular() {
        for (int i = 0; i < rows; i++) {
            for (int j = i + 1; j < cols; j++) {
                double factor = double(data[j][i] / data[i][i]);
                for (int k = i; k < cols; k++) {
                    data[j][k] -= double(factor * data[i][k]);
                }
            }
        }
    }

    void set_element(int row, int col, double value) {
        data[row][col] = value;
    }

    double get_element(int row, int col) const {
        return data[row][col];
    }

    void print() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << fixed << setprecision(2) << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            cerr << "Error: cannot add matrices with incompatible dimensions" << endl;
            return Matrix(0, 0);
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }

        return result;
    }

    Matrix transpose() const {
        Matrix result(cols, rows);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[j][i] = data[i][j];
            }
        }

        return result;
    }
};


int main() {

    Matrix A(3, 2);
    A.read_from_file("matrix1.txt");
    cout << "Matrix A" << endl;
    A.print();

    cout << endl;

    Matrix B(2, 3);
    B.read_from_file("matrix2.txt");
    cout << "Matrix B" << endl;
    B.print();

    cout << endl;

    Matrix C = A.multiply_by_matrix(B);
    cout << "Matrix A*B" << endl;
    C.print();

    cout << endl;

    C.to_upper_triangular();
    cout << "Matrix A*B to Upper Triangular" << endl;
    C.print();

    cout << endl;

    C.set_element(1, 1, 5);
    cout << "Set element - " << C.get_element(1, 1) << endl;

    Matrix D = A + B;
    cout << "Matrix A+B" << endl;
    D.print();

    cout << endl;

    Matrix E = C.transpose();
    cout << "Matrix A*B transponse" << endl;
    E.print();

    return 0;
}