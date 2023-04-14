//
// Created by rudri on 3/23/2022.
//

#include "matrix.h"

std::ostream& utec::operator<<(std::ostream& out, matrix& mtx) {
    for (int fila = 0; fila < mtx.n_row; fila++) {
        for (int col = 0; col < mtx.n_col; col++) {
            out << mtx.matriz[fila][col] << " ";
        }
        out << '\n';
    }
    return out;
}
/*namespace std {
    void swap(utec::matrix &_m1, utec::matrix &_m2);
}

void std::swap(utec::matrix& _m1, utec::matrix& _m2){
    _m1._swap(_m2);
}*/



