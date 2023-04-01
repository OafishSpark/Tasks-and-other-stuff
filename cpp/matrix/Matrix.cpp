#include "Matrix.h" //cassert and iostream are there

Matrix operator+(const Matrix& mtrx1, const Matrix& mtrx2)
{
	assert((mtrx1.numberOfRows == mtrx2.numberOfRows) && (mtrx1.numberOfColumns == mtrx2.numberOfColumns));
	double** matrix = new double* [mtrx1.numberOfRows];
	for (int i = 0; i < mtrx1.numberOfRows; ++i)
	{
		matrix[i] = new double[mtrx1.numberOfColumns];
		for (int j = 0; j < mtrx1.numberOfColumns; ++j)
		{
			matrix[i][j] = mtrx1.matrix[i][j] + mtrx2.matrix[i][j];
		}
	}
	Matrix answer(matrix, mtrx1.numberOfRows, mtrx1.numberOfColumns);
	for (int i = 0; i < mtrx1.numberOfRows; ++i)
	{
		delete matrix[i];
	}
	delete[] matrix;
	return answer;
}

Matrix operator-(const Matrix& mtrx1, const Matrix& mtrx2)
{
	assert((mtrx1.numberOfRows == mtrx2.numberOfRows) && (mtrx1.numberOfColumns == mtrx2.numberOfColumns));
	double** matrix = new double* [mtrx1.numberOfRows];
	for (int i = 0; i < mtrx1.numberOfRows; ++i)
	{
		matrix[i] = new double[mtrx1.numberOfColumns];
		for (int j = 0; j < mtrx1.numberOfColumns; ++j)
		{
			matrix[i][j] = mtrx1.matrix[i][j] - mtrx2.matrix[i][j];
		}
	}
	Matrix answer(matrix, mtrx1.numberOfRows, mtrx1.numberOfColumns);
	for (int i = 0; i < mtrx1.numberOfRows; ++i)
	{
		delete matrix[i];
	}
	delete[] matrix;
	return answer;
}

std::ostream& operator<<(std::ostream& out, const Matrix& mtrx)
{
	out << std::endl;
	for (int i = 0; i < mtrx.numberOfRows; ++i)
	{
		for (int j = 0; j < mtrx.numberOfColumns; ++j)
		{
			out << mtrx.matrix[i][j] << " ";
		}
		out << std::endl;
	}
	return out;
}

Matrix operator*(const Matrix& mtrx1, const Matrix& mtrx2)
{
	assert(mtrx1.numberOfColumns == mtrx2.numberOfRows);
	int numOfRows{ mtrx1.numberOfRows }, numOfColumns{ mtrx2.numberOfColumns };
	double** matrix = new double* [numOfRows];
	for (int i = 0; i < numOfRows; ++i)
	{
		matrix[i] = new double[numOfColumns];
		for (int j = 0; j < numOfColumns; ++j)
		{
			matrix[i][j] = 0;
			for (int k = 0; k < mtrx1.numberOfColumns; ++k)
			{
				matrix[i][j] += mtrx1.matrix[i][k] * mtrx2.matrix[k][j];
			}
		}
	}
	Matrix answer(matrix, numOfRows, numOfColumns);
	for (int i = 0; i < numOfRows; ++i)
	{
		delete matrix[i];
	}
	delete[] matrix;
	return answer;
}
