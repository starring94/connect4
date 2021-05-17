#ifndef MATRIX_HPP_INCLUDED
#define MATRIX_HPP_INCLUDED

class Matrix {
protected:
    int m_row;
    int m_column;
    int *m_matrix_elements;
public:
    Matrix(int row, int column);
    ~Matrix();

    int& at(int row, int column);
    void set(int row, int column, int value);
};

#endif // MATRIX_HPP_INCLUDED

