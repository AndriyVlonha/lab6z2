#include <iostream>
#include <cmath>  
#include <windows.h>
using namespace std;

class Data {
public:
    virtual double norm() const = 0;
    virtual ~Data() {} 
};

class Complex : public Data {
private:
    double real;
    double imag; 
public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}
    virtual double norm() const override {
        return real * real + imag * imag;
    }
    void print() const {
        cout << "(" << real << " + " << imag << "i)";
    }
};
class Vector10 : public Data {
private:
    double elements[10];
public:
    Vector10() {
        for (int i = 0; i < 10; ++i)
            elements[i] = 0.0;
    }
    Vector10(const double elems[10]) {
        for (int i = 0; i < 10; ++i)
            elements[i] = elems[i];
    }

    virtual double norm() const override {
        double sum = 0.0;
        for (int i = 0; i < 10; ++i) {
            sum += elements[i] * elements[i];
        }
        return sqrt(sum);
    }

    void print() const {
        cout << "[";
        for (int i = 0; i < 10; ++i) {
            cout << elements[i];
            if (i < 9) cout << ", ";
        }
        cout << "]";
    }
};

class Matrix2x2 : public Data {
private:
    double mat[2][2];
public:
    Matrix2x2() {
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                mat[i][j] = 0.0;
    }
    Matrix2x2(const double m[2][2]) {
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                mat[i][j] = m[i][j];
    }
    virtual double norm() const override {
        double sum = 0.0;
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                sum += mat[i][j] * mat[i][j];
        return sqrt(sum);
    }

    void print() const {
        cout << "[";
        for (int i = 0; i < 2; ++i) {
            cout << "[";
            for (int j = 0; j < 2; ++j) {
                cout << mat[i][j];
                if (j < 1) cout << ", ";
            }
            cout << "]";
            if (i < 1) cout << ", ";
        }
        cout << "]";
    }
};

int main() {
    SetConsoleOutputCP(1251);
    Complex comp(3.0, 4.0);
    double elems[10] = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0 };
    Vector10 vec(elems);
    double m[2][2] = { {1.0, 2.0}, {3.0, 4.0} };
    Matrix2x2 mat(m);

    cout << "Комплексне число: ";
    comp.print();
    cout << "\nНорма (модуль у квадраті): " << comp.norm() << "\n\n";

    cout << "Вектор: ";
    vec.print();
    cout << "\nЕвклідова норма: " << vec.norm() << "\n\n";

    cout << "Матриця 2x2: ";
    mat.print();
    cout << "\nНорма Фробеніуса: " << mat.norm() << "\n";

    return 0;
}
