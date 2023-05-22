//
// Created by rudri on 3/23/2022.
//

#ifndef PROG3_UNIT1_TAREA_INTRODUCTORIA_V2022_1_MATRIX_H
#define PROG3_UNIT1_TAREA_INTRODUCTORIA_V2022_1_MATRIX_H
#include <iostream>
#include <utility>
#include <random>
typedef std::size_t SIZE_TYPE;
namespace utec {

    class matrix{
    private:
        SIZE_TYPE n_row = 0;
        SIZE_TYPE n_col = 0;

        int **matriz;
    public:


        matrix() = default;
        matrix(SIZE_TYPE row, SIZE_TYPE col) : n_row(row), n_col(col) {
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
        matrix& operator=(matrix&& other) noexcept {
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
        SIZE_TYPE rows() const { return n_row; }
        SIZE_TYPE cols() const { return n_col; }

        //Methods


        //Operator overload
        int &operator()(SIZE_TYPE row, SIZE_TYPE col) const {
            return matriz[row][col];
        };

        //operador *  rvalue +  lvalue +  int y auto incremeto
        matrix operator * (matrix& m1){

            if(n_col != m1.n_row) return *this;
            //instanciar nueva matriz
            matrix mr(n_row,m1.n_col);

            //for loop para multiplicar matrices
            for(int fila=0; fila<n_row; fila++){
                for (int col = 0; col<m1.n_col;col++){
                    int val = 0;
                    for(int i = 0; i< n_col; i++){
                        val += matriz[fila][i] * m1.matriz[i][col] ;
                    }
                    mr(fila,col)=val;
                }
            }
            return mr;
        }
        matrix operator * (matrix&& m1){

            if(n_col != m1.n_row) return *this;
            //instanciar nueva matriz
            matrix mr(n_row,m1.n_col);

            //for loop para multiplicar matrices
            for(int fila=0; fila<n_row; fila++){
                for (int col = 0; col<m1.n_col;col++){
                    int val = 0;
                    for(int i = 0; i< n_col; i++){
                        val += matriz[fila][i] * m1.matriz[i][col] ;
                    }
                    mr(fila,col)=val;
                }
            }
            return mr;
        }
        matrix operator * (int m) {
            matrix mr(n_row, n_col);
            for(int fila = 0; fila<n_row; fila++){
                for(int col= 0;  col<n_col; col++){
                    mr(fila,col) = matriz[fila][col] * m;
                }
            }
            return mr;
        }
        matrix& operator *=(int m){
            for (int fila = 0; fila <n_row; fila++)
                for (int col = 0; col<n_col; col++)
                    matriz[fila][col] *= m;

            return *this;
        }


        //operador + rvalue + lvalue
        matrix operator + (matrix& m1){
            if((n_row != m1.n_row)||(n_col != m1.n_col)) return *this;
            //if(n_col!=m1.n_row) return *this;
            matrix mr(n_row, n_col);
            for (int fila= 0;fila<n_row;fila++){
                for (int col = 0; col<n_col;col++){
                    mr(fila,col) = matriz[fila][col] + m1.matriz[fila][col];
                }
            }
            return mr;
        }
        matrix operator + (matrix&& m1){
            if((n_row != m1.n_row)||(n_col != m1.n_col)) return *this;
            //if(n_col!=m1.n_row) return *this;

            matrix mr(n_row, n_col);
            for (int fila= 0;fila<n_row;fila++){
                for (int col = 0; col<n_col;col++){
                    mr(fila,col) = matriz[fila][col] + m1.matriz[fila][col];
                }
            }
            return mr;
        }
        matrix operator + (int m){

            matrix mr(n_row, n_col);
            for (int fila= 0;fila<n_row;fila++){
                for (int col = 0; col<n_col;col++){
                    mr(fila,col) = matriz[fila][col] + m;
                }
            }
            return mr;
        }
        matrix& operator +=(int m){

            for (int fila= 0;fila<n_row;fila++){
                for (int col = 0; col<n_col;col++){
                     matriz[fila][col] = matriz[fila][col]+ m;
                }
            }
            return *this;
        }

        //operador == y !=

        friend bool operator == (matrix& m1, matrix& m2){
            if((m1.n_row != m2.n_row) ||(m1.n_col != m2.n_col)) return false;
            for (int fila = 0; fila<m1.n_row; fila++){
                for (int col = 0; col<m1.n_col; col++){
                    if (m1.matriz[fila][col] != m2.matriz[fila][col] ) return false;
                }
            }
            return true;
        }
        friend bool operator != (matrix& m1, matrix& m2){
            if((m1.n_row != m2.n_row) ||(m1.n_col != m2.n_col)) return true;
            for (int fila = 0; fila<m1.n_row; fila++){
                for (int col = 0; col<m1.n_col; col++){
                    if (m1.matriz[fila][col] != m2.matriz[fila][col] ) return true;
                }
            }
            return false;
        }

        //friend std::ostream &operator<<(std::ostream &out, matrix &mtx);
        friend std::ostream &operator<<(std::ostream &out, matrix& mtx);
        friend std::ostream &operator<<(std::ostream &out, matrix&& mtx);
        friend matrix operator*(int m, matrix& m1);
        friend matrix operator+(int m, matrix& m1);


};

    matrix operator*(int m, matrix& m1);
    matrix operator+(int m, matrix& m1);
    std::ostream &operator<<(std::ostream &out, matrix& mtx);
    std::ostream &operator<<(std::ostream &out, matrix&& mtx);

}


#endif //PROG3_UNIT1_TAREA_INTRODUCTORIA_V2022_1_MATRIX_H

