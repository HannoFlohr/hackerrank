#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#include<vector>
#include<iostream>

template<typename T> class Matrix {
    public:
        std::vector<std::vector<T>> m;
        unsigned rows;
        unsigned columns;
    
        Matrix(unsigned _rows, unsigned _columns, const T& _init);
        Matrix(const Matrix<T>& rhs);
        virtual ~Matrix();
        
        Matrix<T>& operator=(const Matrix<T>& rhs);
        
        //matrix mathematical operations
        Matrix<T> operator+(const Matrix<T>& rhs);
        Matrix<T>& operator+=(const Matrix<T>& rhs);
        Matrix<T> operator-(const Matrix<T>& rhs);
        Matrix<T>& operator-=(const Matrix<T>& rhs);
        Matrix<T> operator*(const Matrix<T>& rhs);
        Matrix<T>& operator*=(const Matrix<T>& rhs);
        Matrix<T> transpose();
        
        //matrix/scalar operations                                                                                                                                                                                                     
        Matrix<T> operator+(const T& rhs);
        Matrix<T> operator-(const T& rhs);
        Matrix<T> operator*(const T& rhs);
        Matrix<T> operator/(const T& rhs);
        
        //matrix/vector operations
        std::vector<T> operator*(const std::vector<T>& rhs);
        std::vector<T> diagonal_vector();
        
        //access elements
        T& operator()(const unsigned& row, const unsigned& col);
        const T& operator()(const unsigned& row, const unsigned& col) const;
    
        unsigned get_rows() const;
        unsigned get_columns() const;
        
        void printMatrix();
};

//constructor
template<typename T>
Matrix<T>::Matrix(unsigned _rows, unsigned _columns, const T& _init) {
    m.resize(_rows);
    for(unsigned i=0; i<m.size(); i++)
        m[i].resize(_columns, _init);
    
    rows = _rows;
    columns = _columns;
}    

//copy constructor
template<typename T>
Matrix<T>::Matrix(const Matrix<T>& rhs) {
    m = rhs.m;
    rows = rhs.get_rows();
    columns = rhs.get_columns();
}

//destructor
template<typename T>
Matrix<T>::~Matrix() {}

//assignment
template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& rhs) {
    if(&rhs == this)
        return *this;
    
    rows = rhs.get_rows();
    columns = rhs.get_columns();
    
    m.resize(rows);
    for(unsigned i=0; i<m.size(); i++) 
        m[i].resize(columns);
    
    for(unsigned i=0; i<rows; i++) 
        for(unsigned j=0; j<columns; j++)
            m[i][j] = rhs(i, j);
        
    return *this;
}

//addition
template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& rhs) {
  Matrix result(rows, columns, 0.0);

  for (unsigned i=0; i<rows; i++) 
    for (unsigned j=0; j<columns; j++) 
      result(i,j) = this->m[i][j] + rhs(i,j);

  return result;
}

template<typename T>
Matrix<T>& Matrix<T>::operator+=(const Matrix<T>& rhs) {
  for (unsigned i=0; i<rhs.get_rows(); i++) 
    for (unsigned j=0; j<rhs.get_columns(); j++) 
      this->mat[i][j] += rhs(i,j);

  return *this;
}

//subtraction
template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& rhs) {
  Matrix result(rhs.get_rows(), rhs.get_columns(), 0.0);

  for (unsigned i=0; i<rhs.get_rows(); i++) 
    for (unsigned j=0; j<rhs.get_columns(); j++) 
      result(i,j) = this->m[i][j] - rhs(i,j);

  return result;
}

template<typename T>
Matrix<T>& Matrix<T>::operator-=(const Matrix<T>& rhs) {
  for (unsigned i=0; i<rhs.get_rows(); i++) 
    for (unsigned j=0; j<rhs.get_columns(); j++) 
      this->m[i][j] -= rhs(i,j);
  
  return *this;
}

//multiplication
template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& rhs) {
  Matrix result(rhs.get_rows(), rhs.get_columns(), 0.0);

  for (unsigned i=0; i<rhs.get_rows(); i++) 
    for (unsigned j=0; j<rhs.get_columns(); j++) 
      for (unsigned k=0; k<rhs.get_rows(); k++) 
        result(i,j) += this->m[i][k] * rhs(k,j);

  return result;
}

template<typename T>
Matrix<T>& Matrix<T>::operator*=(const Matrix<T>& rhs) {
  return (*this) * rhs;
}

//calculate transpose
template<typename T>
Matrix<T> Matrix<T>::transpose() {
  Matrix result(rows, columns, 0.0);

  for (unsigned i=0; i<rows; i++) 
    for (unsigned j=0; j<columns; j++) 
      result(i,j) = this->m[j][i];

  return result;
}

//addition matrix+scalar
template<typename T>
Matrix<T> Matrix<T>::operator+(const T& rhs) {
  Matrix result(rows, columns, 0.0);

  for (unsigned i=0; i<rows; i++) 
    for (unsigned j=0; j<columns; j++) 
      result(i,j) = this->m[i][j] + rhs;

  return result;
}

//subtraction matrix-scalar
template<typename T>
Matrix<T> Matrix<T>::operator-(const T& rhs) {
  Matrix result(rows, columns, 0.0);

  for (unsigned i=0; i<rows; i++) 
    for (unsigned j=0; j<columns; j++) 
      result(i,j) = this->m[i][j] - rhs;

  return result;
}

//multiplication matrix*scalar
template<typename T>
Matrix<T> Matrix<T>::operator*(const T& rhs) {
  Matrix result(rows, columns, 0.0);

  for (unsigned i=0; i<rows; i++) 
    for (unsigned j=0; j<columns; j++) 
      result(i,j) = this->m[i][j] * rhs;

  return result;
}

//divison matrix/scalar
template<typename T>
Matrix<T> Matrix<T>::operator/(const T& rhs) {
  Matrix result(rows, columns, 0.0);

  for (unsigned i=0; i<rows; i++) 
    for (unsigned j=0; j<columns; j++) 
      result(i,j) = this->m[i][j] / rhs;

  return result;
}

//multiplication matrix*vector
template<typename T>
std::vector<T> Matrix<T>::operator*(const std::vector<T>& rhs) {
  std::vector<T> result(rhs.size(), 0.0);

  for (unsigned i=0; i<rows; i++) 
    for (unsigned j=0; j<columns; j++) 
      result[i] = this->m[i][j] * rhs[j];

  return result;
}

//returns a vector of the diagonal
template<typename T>
std::vector<T> Matrix<T>::diagonal_vector() {
  std::vector<T> result(rows, 0.0);

  for (unsigned i=0; i<rows; i++) 
    result[i] = this->mat[i][i];

  return result;
}

//access element of the matrix
template<typename T>
T& Matrix<T>::operator()(const unsigned& row, const unsigned& col) {
  return this->m[row][col];
}

template<typename T>
const T& Matrix<T>::operator()(const unsigned& row, const unsigned& col) const {
  return this->m[row][col];
}

template<typename T>
unsigned Matrix<T>::get_rows() const {
  return this->rows;
}
                                                                                                                                
template<typename T>
unsigned Matrix<T>::get_columns() const {
  return this->columns;
}

template<typename T>
void Matrix<T>::printMatrix() {
  for(unsigned int i=0; i<rows; i++) {
    for(unsigned int j=0; j<columns; j++) 
      std::cout << m[i][j] << " ";
    std::cout << std::endl;
  }
}


int main() {
    Matrix<int> A (3, 3, 0); 
    A.m[0][0] = 1; A.m[0][1] = 1; A.m[1][1] = 1; A.m[2][2] = 1;
    const Matrix<int> B = A;
    
    for(int i=1; i<100; i++) A = A * B;
    
    cout << A.m[0][0] << endl << A.m[0][1] << endl << A.m[1][1] << endl << A.m[2][1] << endl << A.m[2][2] << endl;
    
    return 0;
}
//https://www.hackerrank.com/challenges/linear-algebra-foundations-5-the-100th-power-of-a-matrix/problem?isFullScreen=true
