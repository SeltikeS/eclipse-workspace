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
		Reset(num_rows, num_cols);
	}

	void Reset(const int& num_rows, const int& num_cols)
	{
		if(num_rows < 0 || num_cols < 0)
		{
			throw out_of_range("reset");
		}

		m_matrix.resize(num_rows);
		for(auto& item : m_matrix)
		{
			item.resize(num_cols);
		}
	}

	const int& At(const int& raw_num, const int& col_num) const
	{
		if(raw_num < 0)
		{
			throw out_of_range("raw1 < 0");
		}
		if(raw_num > GetNumRows())
		{
			throw out_of_range("raw1 > size");
		}
		if(col_num < 0)
		{
			throw out_of_range("col1 < 0");
		}
		if(col_num > GetNumCols())
		{
			throw out_of_range("col1 > size");
		}


		return m_matrix.at(raw_num).at(col_num);
	}
	int& At(const int& raw_num, const int& col_num)
	{
		if(raw_num < 0)
		{
			throw out_of_range("raw2 < 0");
		}
		if(raw_num > GetNumRows())
		{
			throw out_of_range("raw2 > size");
		}
		if(col_num < 0)
		{
			throw out_of_range("col2 < 0");
		}
		if(col_num > GetNumCols())
		{
			throw out_of_range("col2 > size");
		}
		return m_matrix[raw_num][col_num];
	}

	int GetNumRows() const
	{
		return m_matrix.size();
	}
	int GetNumCols() const
	{
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
	int num_raws, num_cols;
	stream >> num_raws >> num_cols;

	m = Matrix(num_raws, num_cols);

	for(auto& raw : m.m_matrix) {
		for(auto& col : raw)
		{
			stream >> col;
		}
	}

	return stream;
}
ostream& operator<<(ostream& stream, const Matrix& m)
{
	int num_rows = m.GetNumRows();
	int num_cols = m.GetNumCols();
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
	if(a == b)
	{
		m = Matrix();
	}
	else if(a.GetNumRows() == b.GetNumRows() && a.GetNumCols() == b.GetNumCols())
	{
		int num_rows = a.GetNumRows();
		int num_cols = a.GetNumCols();

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
	Matrix one;
	Matrix two;

	cin >> one >> two;

	cout << one + two << endl;
	return 0;
}
