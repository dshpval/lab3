#include "pch.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int* insertionSortColumns(int matrix[], const int numberOfElements)
{
	int bufferVariable = 0, matrixColumns = 0;
	for (int matrixRows = 1; matrixRows < numberOfElements; matrixRows++)
	{
		bufferVariable = matrix[matrixRows];
		matrixColumns = matrixRows - 1;
		while (matrixColumns >= 0 && matrix[matrixColumns] < bufferVariable)
		{
			matrix[matrixColumns + 1] = matrix[matrixColumns];
			matrixColumns--;
		}
		matrix[matrixColumns + 1] = bufferVariable;
	}
	return matrix;
}

double calculatinTheSumOfTheGeometricMean(int matrixTemp[])
{
	const int numberOfElements = 5;
	int matrix[numberOfElements][numberOfElements], y[numberOfElements], valueOfMediumGeometric;
	double matrixOfMediumGeometric[numberOfElements], avarageGeometric = 0;
	for (int matrixRows = 0; matrixRows < numberOfElements; matrixRows++)
	{
		for (int matrixColumns = 0; matrixColumns < numberOfElements; matrixColumns++)
		{
			matrix[matrixRows][matrixColumns] = matrixTemp[5 * matrixRows + matrixColumns];
		}
	}
	
	for (int matrixColumns = 1; matrixColumns < numberOfElements; matrixColumns++)
	{
		for (int matrixRows = 0; matrixRows < numberOfElements; matrixRows++)
		{
			y[matrixRows] = matrix[matrixRows][matrixColumns];
		}
		y[numberOfElements] = (int)insertionSortColumns(y, numberOfElements);
		for (int matrixRows = 0; matrixRows < numberOfElements; matrixRows++)
		{
			matrix[matrixRows][matrixColumns] = y[matrixRows];
		}
	}
	cout << '\n' << "Sorted array :\n";
	for (int matrixRows = 0; matrixRows < numberOfElements; matrixRows++)
	{
		for (int matrixColumns = 0; matrixColumns < numberOfElements; matrixColumns++)
		{
			cout << setw(3) << matrix[matrixRows][matrixColumns] << '\t';
		}
		cout << endl;
	}
	
	matrixOfMediumGeometric[0] = 0;
	for (int matrixRows = 1; matrixRows < numberOfElements; matrixRows++)
	{
		valueOfMediumGeometric = 1;
		for (int matrixColumns = 0; matrixColumns < numberOfElements; matrixColumns++)
		{
			if (matrixColumns < matrixRows)
			{
				valueOfMediumGeometric *= matrix[matrixRows][matrixColumns];
			}
		}
		matrixOfMediumGeometric[matrixRows] = pow(abs(valueOfMediumGeometric), 1.0 / matrixRows);
	}
	cout << '\n' << "Geometric mean of rows:\n";
	for (int matrixRows = 1; matrixRows < numberOfElements; matrixRows++)
	{
		cout << matrixOfMediumGeometric[matrixRows] << '\n';
	}
	for (int matrixRows = 0; matrixRows < numberOfElements; matrixRows++)
	{
		avarageGeometric = avarageGeometric + matrixOfMediumGeometric[matrixRows];
	}
	for (int matrixRows = 0; matrixRows < numberOfElements; matrixRows++)
	{
		y[matrixRows] = 0;
	}
	return avarageGeometric;
}

int main()
{
	const int n = 5;
	int a[n][n], b[n * n];
	double f[n], sumOfGeometricAverages;
	cout << '\n' << "Enter array elements:\n";
	for (int matrixRows = 0; matrixRows < n; matrixRows++)
	{
		for (int matrixColumns = 0; matrixColumns < n; matrixColumns++)
		{
			cin >> a[matrixRows][matrixColumns];
		}
	}
	for (int matrixRows = 0; matrixRows < n; matrixRows++)
	{
		for (int matrixColumns = 0; matrixColumns < n; matrixColumns++)
		{
			b[5 * matrixRows + matrixColumns] = a[matrixRows][matrixColumns];
		}
	}

	sumOfGeometricAverages = calculatinTheSumOfTheGeometricMean(b);
	cout << '\n' << "Geometric average sum=" << sumOfGeometricAverages;


	return 0;
}