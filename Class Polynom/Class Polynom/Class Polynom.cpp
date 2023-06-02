// в файле ввод - 2 3 -4 6 -7 0 -18
// это многочлен вида - 2x^6 + 3x^5 - 4x^4 + 6x^3 - 7x^2 +0x - 18

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

long int FastPow(int, int);

class Polynom {
private:
    vector<int> coefficients;

public:
    // Конструктор по умолчанию
    Polynom() {}

    // Конструктор из файла
    Polynom(const string& filename) {
        ifstream file(filename);
        int coefficient;

        while (file >> coefficient) {
            coefficients.push_back(coefficient);
        }

        file.close();
    }

    // Деструктор
    ~Polynom() {}

    // Конструктор копирования
    Polynom(const Polynom& other) {
        coefficients = other.coefficients;
    }

    // Функция возвращающая значение многочлена в заданной точке
    int evaluate(int x) {
        int result = 0;
        int power = coefficients.size() - 1;

        for (int coefficient : coefficients) {
            result += coefficient * FastPow(x, power);
            power--;
        }

        return result;
    }

    // Функция сложения двух многочленов
    Polynom add(const Polynom& other) {
        Polynom result;
        int size = max(coefficients.size(), other.coefficients.size());

        for (int i = 0; i < size; i++) {
            int coefficient = 0;

            if (i < coefficients.size()) {
                coefficient += coefficients[i];
            }

            if (i < other.coefficients.size()) {
                coefficient += other.coefficients[i];
            }

            result.coefficients.push_back(coefficient);
        }

        return result;
    }

    

    // Функция умножения двух многочленов
    Polynom multiply(const Polynom& other) {
        Polynom result;
        int size = coefficients.size() + other.coefficients.size() - 1;

        for (int i = 0; i < size; i++) {
            int coefficient = 0;

            for (int j = 0; j <= i; j++) {
                if (j < coefficients.size() && (i - j) < other.coefficients.size()) {
                    coefficient += coefficients[j] * other.coefficients[i - j];
                }
            }

            result.coefficients.push_back(coefficient);
        }

        return result;
    }

    // Печать многочлена
    void printPolynomial() {
        int power = coefficients.size() - 1;

        for (int i = 0; i < coefficients.size(); i++) {
            int coefficient = coefficients[i];

            if (coefficient != 0) {
                if (coefficient > 0 && i != 0) {
                    cout << "+ ";
                }

                if (coefficient != 1 && coefficient != -1) {
                    cout << coefficient;
                }
                else if (coefficient == -1) {
                    cout << "-";
                }

                cout << "x^" << power;

                if (power != 0) {
                    cout << " ";
                }
            }

            power--;
        }

        cout << endl;
    }


};


int main() {

    // Создание объекта многочлена из файла
    Polynom p1("poly1.txt");

    cout << "Polynom 1" << endl;
    p1.printPolynomial();
    cout << endl;

    // Вывод значения многочлена в точке
    int x = 2;
    int value = p1.evaluate(x);
    cout << "Polynom 1 value at x = " << x << " : " << value << endl;
    cout << endl;

    // Сложение двух многочленов
    Polynom p2("poly2.txt");

    cout << "Polynom 2" << endl;
    p2.printPolynomial();
    cout << endl;

    Polynom sum = p1.add(p2);

    // Вывод результата сложения
    cout << "Sum of polynoms" << endl;
    sum.printPolynomial();
    cout << endl;

    // Умножение двух многочленов

    Polynom multiply = p1.multiply(p2);

    // Вывод результата умножения
    cout << "Multiply of polynoms" << endl;
    multiply.printPolynomial();
    cout << endl;

}

long FastPow(int base, int exp) {
    if (exp== 0)
        return 1;

    if (exp % 2 == 0) {
        long temp = FastPow(base, exp / 2);
        return temp * temp;
    }
    else {
        long temp = FastPow(base, (exp - 1) / 2);
        return base * temp * temp;
    }
}
