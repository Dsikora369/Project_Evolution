#include "FitnesFunction.h"

double FitnesFunction::fitFun(unsigned char* v)
{
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        result += f[i] * v[i];
    }
    return result;
}
FitnesFunction::FitnesFunction() {}
unsigned FitnesFunction::n_return()
{
    return n;
}
void FitnesFunction::input_console()
{
    cout << "Enter size --> ";
    cin >> n;
    f = new unsigned char[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element --> ";
        cin >> f[i];
    }
}
