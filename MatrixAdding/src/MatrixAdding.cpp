//============================================================================
// Name        : MatrixAdding.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

class Matrix
{
public:
	Matrix() {}
	Matrix(const int& num_rows, const int& num_cols)
	{
		if(num_rows < 0 || num_cols < 0)
		{
			throw out_of_range("");
		}

		Reset(num_rows, num_cols);
	}

	void Reset(const int& num_rows, const int& num_cols)
	{
		if(num_rows < 0 || num_cols < 0)
		{
			throw out_of_range("");
		}
		if(num_rows == 0 || num_cols == 0) {
			m_matrix.resize(0);
		} else {
			m_matrix.assign(num_rows, vector<int>(num_cols));
		}

	}

	const int& At(const int& row_num, const int& col_num) const
	{
		if(row_num < 0)
		{
			throw out_of_range("");
		}
		if(row_num >= GetNumRows())
		{
			throw out_of_range("");
		}
		if(col_num < 0)
		{
			throw out_of_range("");
		}
		if(col_num >= GetNumColumns())
		{
			throw out_of_range("");
		}


		return m_matrix.at(row_num).at(col_num);
	}
	int& At(const int& row_num, const int& col_num)
	{
		if(row_num < 0)
		{
			throw out_of_range("");
		}
		if(row_num >= GetNumRows())
		{
			throw out_of_range("");
		}
		if(col_num < 0)
		{
			throw out_of_range("");
		}
		if(col_num >= GetNumColumns())
		{
			throw out_of_range("");
		}
		return m_matrix[row_num][col_num];
	}

	int GetNumRows() const
	{
		return m_matrix.size();
	}
	int GetNumColumns() const
	{
		if(GetNumRows() == 0) {
			return 0;
		}
		return m_matrix.at(0).size();
	}

	friend istream& operator>>(istream& stream, Matrix& m);
	friend ostream& operator<<(ostream& stream, const Matrix& m);
	friend bool 	operator==(const Matrix& a, const Matrix& b);
	friend Matrix 	operator+ (const Matrix& a, const Matrix& b);

private:
	vector<vector<int>> m_matrix;
};

istream& operator>>(istream& stream, Matrix& m)
{
	int num_rows, num_cols;
	stream >> num_rows >> num_cols;

	m = Matrix(num_rows, num_cols);

	for(auto& row : m.m_matrix) {
		for(auto& col : row)
		{
			stream >> col;
		}
	}

	return stream;
}
ostream& operator<<(ostream& stream, const Matrix& m)
{
	int num_rows = m.GetNumRows();
	int num_cols = m.GetNumColumns();
	stream << num_rows << ' ' << num_cols << endl;

	for(const auto& row : m.m_matrix)
	{
		for(const auto& col : row)
		{
			stream << col << ' ';
		}
		stream << endl;
	}

	return stream;
}
bool operator==(const Matrix& a, const Matrix& b)
{
	return a.m_matrix == b.m_matrix;
}
Matrix operator+(const Matrix& a, const Matrix& b)
{
	Matrix m;
	if(a.GetNumRows() == b.GetNumRows() && a.GetNumColumns() == b.GetNumColumns())
	{
		int num_rows = a.GetNumRows();
		int num_cols = a.GetNumColumns();

		m = Matrix(num_rows, num_cols);

		for(int i = 0; i < num_rows; ++i)
		{
			for(int j = 0; j < num_cols; ++j)
			{
				m.At(i, j) = a.At(i, j) + b.At(i, j);
			}
		}
	}
	else
	{
		throw invalid_argument("");
	}

	return m;
}

int main()
{
	try
	{
//		Matrix one;
//		Matrix two;
//
		Matrix m;
		cin >> m;
		m.Reset(2, 3);
		cout << m;
//
//
//		cin >> one >> two;
//		cout << one + two << endl;
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}


	return 0;
}
