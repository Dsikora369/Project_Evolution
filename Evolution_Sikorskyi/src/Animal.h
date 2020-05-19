#pragma once
/*File Animal.h
Realization of class Animal for task "Evolution"
Done by Denys Sikorskyi*/
#include <vector>
#include <time.h>
#include <algorithm>
#include <fstream>
#include <string>
#include <iostream>
#include "FitnesFunction.h"
using namespace std;
class Animal
{
/*Private functions*/
private:
    char changeb(char a, int n); // Function that inverses n-th bit of a
    bool inlist(int a, int* list, int len); // Function that checks is element in list or not

public:
    /* Base element of Animal*/
    vector<char> genome;
    /* functions for Animal*/
    Animal();//  Simple constructor
    Animal(int n); // Constructor that makes Animal whose vector has n random elements
    Animal(vector <char> v); // Constructor that copies vector
    Animal mutate_new(int n, int m); // Function that return Animal which vector was changed in n elements in which element was changed max in  m bits 
    void mutate_old(int n, int m); // Function that changes n elements of Animal in which element was changed max in  m bits 
    Animal breed(Animal& A);// Return Animal that have vector that is average of Animals' vectors
    double fitness(FitnesFunction& FF); // Special function that gives "fitness"
    void input_console();// Input from console
    void input_file(string name); // Input from file
    void output_console(); // Output to console
    void output_file(string name); // Output to file
};
