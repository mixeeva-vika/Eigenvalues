#include "FindEigenvalues.h"

std::vector<double>FindEigenvalues::Generate(size_t n)
{
	std::vector<double> x(n);
	for (size_t i = 0; i < n; ++i)
		x[i] = rand() % 10;
	return x;
}

double FindEigenvalues::ScalarProduct(std::vector<double>& x1, std::vector<double>& x2)
{
	if (x1.size() != x2.size())
		throw "Different size of vectors";
	double sum = 0;
	for (size_t i = 0; i < x1.size(); ++i)
		sum += x1[i] * x2[i];
	return sum;
}
std::pair<double, std::vector<double>> FindEigenvalues::PowerMethod(const Matrix& A)
{
	std::vector<double> x_prev = FindEigenvalues::Generate(A.size());
	x_prev = MultiplyVectorToNumber(x_prev, (1.0 / norma(x_prev)));
	std::vector<double> x = A*x_prev;
	double lyambda_prev;
	double lyambda = ScalarProduct(x, x_prev) / ScalarProduct(x_prev, x_prev);

	int i = 0;
	do
	{
		++i;
		//std::cout << "================" << i << "===============" << std::endl;
		if (i % 5 == 0)
		{
			x = MultiplyVectorToNumber(x, 1.0 / norma(x));
		}
		x_prev = x;
		x = A*x_prev;
		lyambda_prev = lyambda;
		lyambda = ScalarProduct(x, x_prev) / ScalarProduct(x_prev, x_prev);


	} while (fabs(lyambda - lyambda_prev) > eps);

	std::vector<double> e = MultiplyVectorToNumber(x, 1.0 / norma(x));
	
	return std::make_pair(lyambda, e);
}

size_t FindEigenvalues::min(size_t n1, size_t n2)
{
	return (n1 > n2) ? n2 : n1;
}

void FindEigenvalues::print(const std::vector<double>& x)
{
	const size_t m = 30;
	for (size_t i = 0; i < min(m, x.size()); ++i)
		std::cout << x[i] << " ";
	std::cout << std::endl;
}

double FindEigenvalues::norma(const std::vector<double>& x)
{
	double sum = 0;
	for (size_t i = 0; i < x.size(); ++i)
		sum += x[i] * x[i];
	return sqrt(sum);
}

std::vector<double> FindEigenvalues::MultiplyVectorToNumber(const std::vector<double>& x, double coef)
{
	std::vector<double> res(x.size());
	for (size_t i = 0; i < x.size(); ++i)
		res[i] = x[i] * coef;
	return res;
}