#pragma once
#include <stdio.h>
#include <iostream>
#include <vector>
#include "Matrix.h"

class FillingData
{
    static double read(std::istream& fin);
    static Matrix ReadSystem(std::istream& fin);
public:
    static Matrix FillingFromKeyboar();
    static Matrix FillingFromFile(char* filename);
	static Matrix FillingWithFunc1(size_t n);
	static Matrix FillingWithFunc2(size_t n);
	static Matrix FillingWithFunc3(size_t n);
};