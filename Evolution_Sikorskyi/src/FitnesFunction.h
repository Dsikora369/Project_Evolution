#pragma once
/* File  FitnesFunction.h
Realization of FitnesFunction for "Evolution"
Done by Denys Sikorskyi */

#include <vector>
#include <time.h>
#include <algorithm>
#include <fstream>
#include <string>
#include <iostream>
using namespace std;
class FitnesFunction
{
public:
    /* Base structure of FitnesFunction*/
    unsigned n; // size of f
    unsigned char* f; // list of chars
    /* functions of FitnesFunction*/
    double fitFun(unsigned char* v); // function that return multiplication of v and f
    unsigned n_return(); // return size
    FitnesFunction(); // simple constructor
    void input_console(); // input from console
};
