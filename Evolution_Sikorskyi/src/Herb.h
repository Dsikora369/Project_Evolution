#pragma once
/* File  Herb.h
Realization of Herb structure for "Evolution"
Done by Denys Sikorskyi */
#include <vector>
#include <time.h>
#include <algorithm>
#include <fstream>
#include <string>
#include <iostream>
#include "FitnesFunction.h"
#include "Animal.h"
using namespace std;
class Herb
{
public:
    /*Structure of Herb*/
    int size; // size of herb
    Animal* herb; // herb that contains elements of class Animals
    /*Functions of herb*/
    Herb(); // simple constructor
    void add(Animal& A); // add one Animal to herb
    void add(Animal* A, int sizeA); // add list of Animal to herb
    void selection(int m, FitnesFunction& FF); // leave m Animal that have the lowest "fitness"
    void crossover(int m, FitnesFunction& FF); // function that makes m Animal that have the lowest "fitness" to breed with random animals from herb( they can not breed with themselves
    void output_console(); // output to console
};
