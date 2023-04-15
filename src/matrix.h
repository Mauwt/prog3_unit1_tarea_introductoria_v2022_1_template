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
                    matriz[i][j] = other.matriz[i][j];
                }
            }
        }
        matrix(matrix &&other) noexcept{

            this->n_row = other.n_row;
            this->n_col = other.n_col;

            matriz = other.matriz;
            other.matriz = nullptr;
            other.n_row = 0;
            other.n_col = 0;
            /*matriz = new int* [n_row];
            for (int i = 0; i < n_row; i++) {
                matriz[i] = new int[n_col];
            }*/
            /*
            for (int i = 0; i < n_row; i++) {
                for (int j = 0; j < n_col; j++) {
                    matriz[i][j] = other.matriz[i][j];
                }
            }

            for (int i = 0; i < n_row; i++) {
                delete[] other.matriz[i];
                other.matriz[i] = nullptr;
            }
            */

        }

        //Operadores de asignacion move y copy
        matrix& operator=(const matrix& other){
            if(this!=&other){
                for (int i = 0; i < n_row; i++) {
                    delete[] matriz[i];
                    matriz[i] = nullptr;
                }
                delete[] matriz;
                matriz = nullptr;

                this->n_row = other.n_row;
                this->n_col = other.n_col;


                matriz = new int* [n_row];
                for (int i = 0; i < n_row; i++) {
                    matriz[i] = new int[n_col];
                }

                for (int i = 0; i < n_row; i++) {
                    for (int j = 0; j < n_col; j++) {
                        matriz[i][j] = other.matriz[i][j];
                    }
                }
                return *this;
            }
            return *this;

        };
        matrix& operator= (matrix&& other) noexcept {
            if(this!=&other) {

                for (int i = 0; i < n_row; i++) {
                    delete[] matriz[i];
                    matriz[i] = nullptr;
                }
                delete[] matriz;
                matriz = nullptr;
                // Asignar el tamaño a esta matriz
                this->n_row = other.n_row;
                this->n_col = other.n_col;

                // Limpiar los datos dentro de esta matriz
                /*
                // Asignar nuevos tamaños a esta matriz
                matriz = new int *[n_row];
                for (int i = 0; i < n_row; i++) {
                    matriz[i] = new int[n_col];
                }


                //Asignar valores a esta matriz
                for (int i = 0; i < n_row; i++) {
                    for (int j = 0; j < n_col; j++) {
                        matriz[i][j] = other.matriz[i][j];
                    }
                }

                //Elimiar los datos dentro de la otra matriz
                for (int i = 0; i < n_row; i++) {
                    delete[] other.matriz[i];
                    other.matriz[i] = nullptr;
                }
                delete[] other.matriz;
                other.matriz = nullptr;
                */
                matriz = other.matriz;
                other.matriz = nullptr;
                other.n_row = 0;
                other.n_col = 0;
                return *this;
            }
            return *this;
        };

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

};
    std::ostream &operator<<(std::ostream &out, matrix &mtx);

}


#endif //PROG3_UNIT1_TAREA_INTRODUCTORIA_V2022_1_MATRIX_H

