/* File  test_Animal.cpp
Realization of tests for Animal
Done by Denys Sikorskyi */
#include "../src/Animal.h"
#include "../src/FitnesFunction.h"
int test_empty_constructor()
{
	Animal A1;
	int n;
	FitnesFunction F1;
	cout << "test_empty_constructor has started" << endl;
	cout << "Enter 0 to console output, 1 to file output --> ";
	cin >> n;
	if (n == 0)
	{
		A1.output_console();
	}
	else
	{
		if (n == 1)
		{
			A1.output_file("test_empty_constructor_result.txt");
		}
	}
	if (n != 0 && n != 1)
	{
		cout << "Wrong test_empty_constructor input" << endl;
	}
	return 1;
	
}
int test_random_Animal_file_input()
{
	FitnesFunction F1;
	cout << "test_random_Animal_file_input has started" << endl;
	fstream f;
	f.open("test_random_Animal_file_input.txt", ios::in);
	int n;
	f >> n;
	Animal A1(n);
	int v;
	cout << "Enter 0 to console output, 1 to file output --> ";
	cin >> v;
	if (v == 0)
	{
		A1.output_console();
	}
	else
	{
		if (v == 1)
		{
			A1.output_file("test_random_Animal_file_input_result.txt");
		}
	}
	if (v != 0 && v != 1)
	{
		cout << "Wrong input" << endl;
	}
	f.close();
	return 1;


}
int test_random_Animal_console_input()
{
	int n;
	FitnesFunction F1;
	cout << "test_random_Animal_console_input has started" << endl;
	cout << "Enter size --> ";
	cin >> n;
	Animal A1(n);
	int v;
	cout << "Enter 0 to console output, 1 to file output --> ";
	cin >> v;
	if (v == 0)
	{
		A1.output_console();
	}
	else
	{
		if (v == 1)
		{
			A1.output_file("test_random_Animal_console_input_result.txt");
		}
	}
	if (v != 0 && v != 1)
	{
		cout << "Wrong input" << endl;
	}

	return 1;


}
int test_vector_Animal()
{
	FitnesFunction F1;
	cout << "test_vector_Animal has started" << endl;
	fstream f;
	vector<char> v;
	f.open("test_vector_Animal.txt", ios::in);
	char s = 'f';
	int i = 0;
	while (f)
	{
		f >> s;
		v.push_back(s);
	}
	v.pop_back();
	Animal A1(v);
	A1.output_file("test_vector_Animal_result.txt");
	f.close();
	return 1;
}
int test_mutate_old_Animal()
{
	FitnesFunction F1;
	cout << "test_mutate_old_Animal has started" << endl;
	Animal A1;
	A1.input_file("test_mutate_old_Animal_vector.txt");
	fstream f;
	int n, m;
	f.open("test_mutate_old_Animal_nums.txt", ios::in);
	f >> n;
	f >> m;
	f.close();
	A1.mutate_old(n, m);
	A1.output_file("test_mutate_old_Animal_result.txt");
	return 1;
}
int test_mutate_new_Animal()
{
	FitnesFunction F1;
	cout << "test_mutate_new_Animal has started" << endl;
	Animal A1;
	A1.input_file("test_mutate_new_Animal_vector.txt");
	fstream f;
	int n, m;
	f.open("test_mutate_new_Animal_nums.txt", ios::in);
	f >> n;
	f >> m;
	f.close();
	A1.mutate_new(n, m).output_file("test_mutate_new_Animal_result.txt");
	return 1;
}
int test_breed_Animal()
{
	FitnesFunction F1;
	cout << "test_breed_Animal has started" << endl;
	Animal A1, A2;
	A1.input_file("test_breed_Animal_1.txt");
	A2.input_file("test_breed_Animal_2.txt");
	A1.breed(A2).output_file("test_breed_Animal_result.txt");
	return 1;
}
int test_fitness_Animal()
{
	FitnesFunction F1;
	cout << "test_fitness_Animal has started" << endl;
	F1.input_console();
	Animal A1;
	A1.input_file("test_fitness_Animal.txt");
	fstream f;
	f.open("test_fitness_Animal_result.txt", ios::out);
	f << A1.fitness(F1);
	f.close();
	return 1;
}
int test_input_console_Animal()
{
	cout << "test_input_console_Animal has started" << endl;
	FitnesFunction F1;
	Animal A1;
	A1.input_console();
	A1.output_file("test_input_console_Animal_result.txt");
	return 1;
}
