#ifndef MATRIX_H
#define MATRIX_H
class Matrix
{
	int rows, cols;
	int** data;
	Matrix createMatrix(int, int)const;
public:
	Matrix();
	Matrix(int, int);
	Matrix(const Matrix&);
	~Matrix();
	int& operator()(int, int);
	const int& operator()(int, int)const;
	int getRows()const;
	int getColum()const;
	void display()const;
	Matrix transpose()const;
	Matrix operator+(const Matrix&)const;
	Matrix operator*(const Matrix&)const;
	Matrix operator-(const Matrix&)const;
	void reSize(int, int);
};
#endif // ! MATRIX_H
