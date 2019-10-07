#include "FillingMatrix.h"

double FillingData::read(std::istream& fin)
{
    double x;
    if (fin >> x)
    {
        return x;
    }
    else if (fin.bad())
        throw "Reading error";
    else if (fin.eof())
        throw "Incorrect size of matrix or incorrect file";
    else
        throw "Incorrect format";
}

Matrix FillingData::ReadSystem(std::istream& fin)
{
    size_t n;
    fin >> n;
    Matrix A(n);
    int tmp;
	for(size_t i = 0; i < n; ++i)
	{
		for(size_t j = 0; j < n; ++j)
		{
            A[i][j] = read(fin);
		}
	}
    fin >> tmp;
    if (!fin.eof())
        throw "Incorrect file";

    return A;
}

Matrix FillingData::FillingFromKeyboar()
{
    return ReadSystem(std::cin);
}

Matrix FillingData::FillingFromFile(char* filename)
{
    std::ifstream fin(filename);
    if (!fin)
        throw "Can't open the file";

    try
    {
        Matrix result = ReadSystem(fin);
        fin.close();
        return result;
    }
    catch (char* err)
    {
        fin.close();
        throw;
    }
}

//===================================----1----============================================
Matrix FillingData::FillingWithFunc1(size_t n)
{
	Matrix A(n);
	for (size_t i = 0; i < n; ++i)
	{
		for (size_t j = 0; j < n; ++j)
		{
			if(i == j)
			    A[i][j] = 5.0;
			else
				A[i][j] = 0;
		}
	}
    
    return A;
}

//===================================----2----============================================
Matrix FillingData::FillingWithFunc2(size_t n)
{
	Matrix A(n);
	for (size_t i = 0; i < n; ++i)
	{
		for (size_t j = 0; j < n; ++j)
		{
			if (j == i)
			{
				if (i == 0)
					A[i][j] = -1;
				else if (i == n - 1)
					A[i][j] = -((double)(n - 1) / n);
                else
				    A[i][j] = -2;
			}
            else
            {
                if ((j == i + 1) || (j == i - 1))
                    A[i][j] = 1;
                else
                    A[i][j] = 0;
            }
		}
	}
	return A;
}
//===================================----3----============================================
Matrix FillingData::FillingWithFunc3(size_t n)
{
	Matrix A(n);
	for (size_t i = 0; i < n; ++i)
	{
		for (size_t j = 0; j < n; ++j)
		{
			A[i][j] = 1. / (i + j + 1);
		}
	}
	return A;
}



