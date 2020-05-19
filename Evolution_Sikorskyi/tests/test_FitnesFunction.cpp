/* File  test_FitnesFunction.cpp
Realization of tests for FitnesFunction
Done by Denys Sikorskyi */
#include "../src/FitnesFunction.h"
int FF_test_fitFun()
{
        FitnesFunction F1;
        F1.input_console();
        unsigned char* test_function = new unsigned char[F1.n];
        for (int i = 0; i < F1.n; i++)
        {
            cout << "Enter char -->";
            cin >> test_function[i];
        }
        cout << F1.fitFun(test_function) << endl;
        return 1;
}
