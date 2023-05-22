#include <iostream>
#include <vector>
#include "matrix.h"

using namespace std;



int main() {

    SIZE_TYPE rows = 0, cols = 0;
    cout << "Filas y columnas: \n";
    cin >> rows >> cols;
    utec::matrix m1(rows, cols);
    for (size_t i = 0; i < m1.rows(); ++i) {
        cout << "Elementos de la fila " << i << "\n";
        for (size_t j = 0; j < m1.cols(); ++j)
            cin >> m1(i, j);
    }

    cout << "\nFilas y columnas: \n";
    cin >> rows >> cols;
    utec::matrix m2(rows, cols);
    for (size_t i = 0; i < m2.rows(); ++i) {
        cout << "Elementos de la fila " << i << "\n";
        for (size_t j = 0; j < m2.cols(); ++j)
            cin >> m2(i, j);
    }

    cout << "\nFilas y columnas: \n";
    cin >> rows >> cols;
    utec::matrix m3(rows, cols);
    for (size_t i = 0; i < m3.rows(); ++i) {
        cout << "Elementos de la fila " << i << "\n";
        for (size_t j = 0; j < m3.cols(); ++j)
            cin >> m3(i, j);
    }
    cout << m1;
    cout <<"\n\n";
    cout << m2;
    cout <<"\n\n";
    cout <<m3;
    cout <<"\n\n";


    // Multiplicación entre matrices
    cout << m2 * m3 << endl;
    //Suma de matrices
    auto m4 = m1 + m2;
    cout << m4 << endl;

    // Autoincremento
    m1 *= 5;
    cout << m1 << endl;

    // Multiplicación escalar
    auto m5 = 4 * m1 * 2  + m4 ;

    cout << m5 << endl;
}
