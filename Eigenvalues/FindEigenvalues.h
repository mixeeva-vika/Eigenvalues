#pragma once
#include<iostream>
#include<math.h>
#include <iomanip>
#include "Matrix.h"
#define eps 0.00000000000001
class FindEigenvalues
{
    static size_t min(size_t n1, size_t n2);
public:
    static std::pair<double, std::vector<double>> PowerMethod(const Matrix& A);
    static std::vector<double> Generate(size_t n);
    static double ScalarProduct(std::vector<double>& x1, std::vector<double>& x2);
    static void print(const std::vector<double>& x);
    static double norma(const std::vector<double>& x);
    static std::vector<double> MultiplyVectorToNumber(const std::vector<double>& x, double coef);
};
