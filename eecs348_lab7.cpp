#include <iostream>
using namespace std;

const int SIZE = 4; 

class Matrix{
private:
    int data[SIZE][SIZE];

public:
    void readToMatrix(){
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j){
                cin >> data[i][j];
            }
        }
    }
void display() const {
    for (int i = 0; i < SIZE; ++i){
        for (int j = 0; j < SIZE; ++j){
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}
Matrix operator+(const Matrix &other) const {
    Matrix result;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j){
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}
Matrix operator*(const Matrix &other) const {
    Matrix result;
    for (int i = 0; i < SIZE; ++i){
        for (int j = 0; j < SIZE; ++j){
            result.data[i][j] = 0;
            for (int k = 0; k < SIZE; ++k){
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    return result;
}
int sumOfDiagonals() const{
    int mainDiagonalSum = 0, secondaryDiagonalSum = 0;
    for (int i = 0; i < SIZE; ++i) {
        mainDiagonalSum += data[i][i];
        secondaryDiagonalSum += data[i][SIZE - i- 1];
    }
    return mainDiagonalSum + secondaryDiagonalSum;
}
void swapRows(int row1, int row2) {
    if (row1 >= 0 && row1 < SIZE && row2 >= 0 && row2 < SIZE){
        for (int j = 0; j < SIZE; ++j) {
            swap(data[row1][j], data[row2][j]);
        }
    }else{
        cout << "Invalid rows" << endl;
    }
}
};

int main(){
    Matrix matrix1;
    cout << "Enter numbers for Matrix 1:" <<endl;
    matrix1.readToMatrix();
    cout << "Matrix 1:"<< endl;
    matrix1.display();

    Matrix matrix2;
    cout << "Enter numbers for Matrix 2:" <<endl;
    matrix2.readToMatrix();
    cout << "Matrix 2:" <<endl;
    matrix2.display();

    Matrix sum = matrix1 + matrix2;
    cout << "Sum:" << endl;
    sum.display();

    Matrix product = matrix1 * matrix2;
    cout << "Product:" << endl;
    product.display();

    cout << "Sum of diagonals of Matrix 1: " <<matrix1.sumOfDiagonals() << endl;

    matrix1.swapRows(0,2);
    cout << "Matrix 1 after swapping rows:" <<endl;
    matrix1.display();

    return 0;
}