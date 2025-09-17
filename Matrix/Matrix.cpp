#include"Matrix.h"
#include<iostream>
using namespace std;
Matrix Matrix::createMatrix(int r, int c)const
{
	Matrix mat;
	mat.data = new int* [r];
	for (int i = 0; i < r; i++)
	{
		mat.data[i] = new int[c];
	}
	mat.rows = r;
	mat.cols = c;
	return mat;
}
Matrix::Matrix()
{
	data = nullptr;
	rows = 0;
	cols = 0;
}
Matrix::Matrix(int r, int c)
{
	rows = r;
	cols = c;
	data = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		data[i] = new int[cols];
	}
}
Matrix::Matrix(const Matrix& mat) :Matrix(mat.rows, mat.cols)
{
	for (int i = 0; i < rows; i = i + 1)
	{
		for (int j = 0; j < cols; j = j + 1)
		{
			data[i][j] = mat.data[i][j];
		}
	}
}
Matrix::~Matrix()
{
	if (data == nullptr)
	{
		rows = 0;
		cols = 0;
		return;
	}
	for (int i = 0; i < rows; i++)
	{
		delete data[i];
	}
	delete[] data;
	data = nullptr;
	rows = 0;
	cols = 0;
}
int& Matrix::operator()(int r, int c)
{
	if(r > 0 && r <= rows && c > 0 && c <= cols)
	{
		int& a = data[r-1][c-1];
		return a;
	}
	exit(0);
}
const int& Matrix::operator()(int r, int c)const
{
	if (r > 0 && r <= rows && c > 0 && c <= cols)
	{
		const int& a = data[r - 1][c - 1];
		return a;
	}
	exit(0);
}
int Matrix::getRows()const
{
	return rows;
}
int Matrix::getColum()const
{
	return cols;
}
void Matrix::display()const
{
	if(data!=nullptr)
	{
		for (int i = 0; i < rows; i = i + 1)
		{
			for (int j = 0; j < cols; j = j + 1)
			{
				cout << data[i][j] << '\t';
			}
			cout << '\n';
		}
	}
}
Matrix Matrix::transpose()const
{
	if (data != nullptr)
	{
		Matrix resultantMatrix = createMatrix(cols, rows);
		for (int i = 0; i < resultantMatrix.rows; i = i + 1)
		{
			for (int j = 0; j < resultantMatrix.cols; j = j + 1)
			{
				resultantMatrix.data[i][j] = data[j][i];
			}
		}
		return resultantMatrix;
	}
	Matrix resultantMatrix;
	return resultantMatrix;		// in this case a pointer with "NULLPTR" will be returned creating No harm
}
Matrix Matrix::operator-(const Matrix& mat)const
{
	if (data != nullptr && mat.data != nullptr && rows == mat.rows && cols == mat.cols)
	{
		Matrix resultantMatrix = createMatrix(mat.rows, mat.cols);
		for (int i = 0; i < rows; i = i + 1)
		{
			for (int j = 0; j < cols; j = j + 1)
			{
				resultantMatrix.data[i][j] = mat.data[i][j] - data[i][j];
			}
		}
		return resultantMatrix;
	}
	else if (mat.data == nullptr && data != nullptr)
	{
		Matrix resultantMatrix = createMatrix(rows, cols);
		for (int i = 0; i < rows; i = i + 1)
		{
			for (int j = 0; j < cols; j = j + 1)
			{
				resultantMatrix.data[i][j] = data[i][j];
			}
		}
		return resultantMatrix;
	}
	else if (data == nullptr && mat.data != nullptr)
	{
		Matrix resultantMatrix = createMatrix(mat.rows, mat.cols);
		for (int i = 0; i < mat.rows; i = i + 1)
		{
			for (int j = 0; j < mat.cols; j = j + 1)
			{														 // A void Matrix is going to be treated as a "NULL Matrix",
				resultantMatrix.data[i][j] = 0 - mat.data[i][j];	//having '0' on every location 
			}
		}
		return resultantMatrix;
	}
	else
	{
		Matrix resultantMatrix;		// this block will be executed only when both the matrices are empty.
		return resultantMatrix;		// in this case a pointer with "NULLPTR" will be returned creating No harm
	}
}
Matrix Matrix::operator+(const Matrix& mat)const
{
	if (data != nullptr && mat.data != nullptr && rows == mat.rows && cols == mat.cols)
	{
		Matrix resultantMatrix = createMatrix(mat.rows, mat.cols);
		for (int i = 0; i < rows; i = i + 1)
		{
			for (int j = 0; j < cols; j = j + 1)
			{
				resultantMatrix.data[i][j] = mat.data[i][j] + data[i][j];
			}
		}
		return resultantMatrix;
	}
	else if (mat.data == nullptr && data != nullptr)
	{
		Matrix resultantMatrix = createMatrix(rows, cols);
		for (int i = 0; i < rows; i = i + 1)
		{
			for (int j = 0; j < cols; j = j + 1)
			{
				resultantMatrix.data[i][j] = data[i][j];
			}
		}
		return resultantMatrix;
	}
	else if (data == nullptr && mat.data != nullptr)
	{
		Matrix resultantMatrix = createMatrix(mat.rows, mat.cols);
		for (int i = 0; i < mat.rows; i = i + 1)
		{
			for (int j = 0; j < mat.cols; j = j + 1)
			{
				resultantMatrix.data[i][j] = mat.data[i][j];
			}
		}
		return resultantMatrix;
	}
	else
	{
		Matrix resultantMatrix;
		return resultantMatrix;		// in this case a pointer with "NULLPTR" will be returned creating No harm
	}
}
Matrix Matrix::operator*(const Matrix& mat)const
{
	if (data != nullptr && mat.data != nullptr && cols == mat.rows)
	{
		Matrix resultantMatrix = createMatrix(rows, mat.cols);
		for (int i = 0; i < rows; i = i + 1)
		{
			for (int j = 0; j < mat.cols; j = j + 1)
			{
				resultantMatrix.data[i][j] = 0;
				for (int k = 0; k < cols; k = k + 1)
				{
					resultantMatrix.data[i][j] = resultantMatrix.data[i][j] + (data[i][k] * mat.data[k][j]);
				}
			}
		}
		return resultantMatrix;
	}
	Matrix resultantMatrix;
	return resultantMatrix;		// in this case a pointer with "NULLPTR" will be returned creating No harm
}
void Matrix::reSize(int r, int c)
{
	if (data != nullptr)
	{
		if (r <= 0 || c <= 0)
		{
			this->~Matrix();
			return;
		}
		Matrix mat = createMatrix(r, c);
		for (int i = 0; i < rows && i < r; i = i + 1)
		{
			for (int j = 0; j < cols && j < c; j = j + 1)
			{
				mat.data[i][j] = data[i][j];
			}
		}
		this->~Matrix();	// Manually calling destructor for deleting current Matrix
		data = mat.data;	// Now data is pointing to newly created and populated Matrix, both are pointing to the same Matrix.
		mat.data = nullptr;	// "NULLPTR" is placed in mat.data so that when its destructor be called explicitly, no Matrix be harmed.
		rows = r;
		cols = c;
		return;
	}
	Matrix mat = createMatrix(r, c);
	data = mat.data;
	mat.data = nullptr;
	rows = r;
	cols = c;
}