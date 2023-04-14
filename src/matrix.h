//
// Created by rudri on 3/23/2022.
//

#ifndef PROG3_UNIT1_TAREA_INTRODUCTORIA_V2022_1_MATRIX_H
#define PROG3_UNIT1_TAREA_INTRODUCTORIA_V2022_1_MATRIX_H
#include <iostream>
#include <utility>
namespace utec {

    class matrix {
    private:
        int n_row = 0;
        int n_col = 0;

        int **matriz;
    public:
        matrix() = default;

        matrix(int row, int col) : n_row(row), n_col(col) {
            matriz = new int *[n_row];
            for (int i = 0; i < n_row; i++) {
                matriz[i] = new int[n_col];
            }
        }

        matrix(matrix &other) : n_row(other.n_row), n_col(other.n_col) {
            matriz = new int *[n_row];
            for (int i = 0; i < n_row; i++) {
                matriz[i] = new int[n_col];
            }

            for (int i = 0; i < n_row; i++) {
                for (int j = 0; j < n_col; j++) {
                    this->matriz[i][j] = other.matriz[i][j];
                }
            }
        }

        matrix(matrix &&other) noexcept: n_row(other.n_row), n_col(other.n_col), matriz(other.matriz) {

        }

        // Destructor
        virtual ~matrix() {
            for (int i = 0; i < n_row; i++) {
                delete[] matriz[i];
                matriz[i] = nullptr;
            }
            delete[] matriz;
            matriz = nullptr;
        }

        //Getters
        int rows() const { return n_row; }

        int cols() const { return n_col; }

        //Methods


        //Operator overload
        int &operator()(int row, int col) {
            return matriz[row][col];
        };

        friend std::ostream &operator<<(std::ostream &out, matrix &mtx);

        void _swap(matrix &_m2) {
            using std::swap;
            swap(this->matriz, _m2.matriz);
            swap(this->n_row, _m2.n_row);
            swap(this->n_col, _m2.n_col);
        }

};
    std::ostream &operator<<(std::ostream &out, matrix &mtx);

}


#endif //PROG3_UNIT1_TAREA_INTRODUCTORIA_V2022_1_MATRIX_H

