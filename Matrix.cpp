#include "Matrix.hpp"

using namespace std;

Matrix::Matrix(int row, int column): m_row(row), m_column(column), m_matrix_elements(new int[row*column])
{
}

Matrix::~Matrix() {
//    for(int i = 0; i < m_row; i++) {
//        delete m_matrix_elements[i];
//    }
    delete[] m_matrix_elements;
}

int& Matrix::at(int row, int column) {
    return *(m_matrix_elements+row*m_column+column);
}

void Matrix::set(int row, int column, int value) {
    *(m_matrix_elements+row*m_column+column) = value;
}
