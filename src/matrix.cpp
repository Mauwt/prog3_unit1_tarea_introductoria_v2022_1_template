//
// Created by rudri on 3/23/2022.
//

#include "matrix.h"
#include <iomanip>
std::ostream& utec::operator<<(std::ostream& out, matrix &mtx) {
    for (int fila = 0; fila < mtx.n_row; fila++) {
        for (int col = 0; col < mtx.n_col; col++) {
            out << mtx.matriz[fila][col] << std::setw(4);
        }
        out << '\n';
    }
    return out;
}

std::ostream& utec::operator<<(std::ostream& out, matrix &&mtx) {
    for (int fila = 0; fila < mtx.n_row; fila++) {
        for (int col = 0; col < mtx.n_col; col++) {
            out << mtx.matriz[fila][col] << std::setw(4);
        }
        out << '\n';
    }
    return out;
}

utec::matrix utec::operator*(int m, utec::matrix &m1) {

    matrix mr(m1.n_row, m1.n_col);
    for (int fila = 0; fila<m1.n_row; fila++){
        for (int col = 0; col<m1.n_col; col++){
            mr(fila, col) = m1.matriz[fila][col]*m;
        }
    }
    return mr;
}

utec::matrix utec::operator+(int m, matrix& m1){

    matrix mr(m1.n_row, m1.n_col);
    for (int fila= 0;fila<m1.n_row;fila++){
        for (int col = 0; col<m1.n_col;col++){
            mr(fila,col) = m1.matriz[fila][col] + m;
        }
    }
    return mr;
}