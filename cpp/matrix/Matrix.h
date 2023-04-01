#pragma once
#include <iostream>
#include <cassert>

class Matrix
{
	double** matrix;
	int numberOfRows;
	int numberOfColumns;
public:
	Matrix(double** mtrx, int nor, int noc) : numberOfRows(nor), numberOfColumns(noc)
	{
		matrix = new double * [nor];
		for (int i = 0; i < nor; ++i)
		{
			matrix[i] = new double[noc];
			for (int j = 0; j < noc; ++j)
			{
				matrix[i][j] = mtrx[i][j];
			}
		}
	}

	Matrix(const Matrix& mtrx) : numberOfRows(mtrx.numberOfRows), numberOfColumns(mtrx.numberOfColumns)
	{
		matrix = new double* [numberOfRows];
		for (int i = 0; i < numberOfRows; ++i)
		{
			matrix[i] = new double[numberOfColumns];
			for (int j = 0; j < numberOfColumns; ++j)
			{
				matrix[i][j] = mtrx.matrix[i][j];
			}
		}
	}

	~Matrix()
	{
		for (int i = 0; i < numberOfRows; ++i)
		{
			delete matrix[i];
		}
		delete[] matrix;
	}
	
	friend Matrix operator+(const Matrix& mtrx1, const Matrix& mtrx2);
	friend Matrix operator-(const Matrix& mtrx1, const Matrix& mtrx2);
	friend std::ostream& operator<<(std::ostream& out, const Matrix& mtrx);
	friend Matrix operator*(const Matrix& mtrx1, const Matrix& mtrx2);
/*
	double determinant()
	{
		assert(numberOfRows == numberOfColumns);
		double answer{ 0 };
		int n{ numberOfColumns };
		for (int i = 0; i < n; ++i)
		{

		}
	}
*/
};

