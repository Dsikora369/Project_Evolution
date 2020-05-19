/* File  test_Herb.cpp
Realization of tests for Herb
Done by Denys Sikorskyi */
#include "../src/Animal.h"
#include "../src/FitnesFunction.h"
#include "../src/Herb.h"
int test_add_Herb()
{
	cout << "test_add_Herb has started" << endl;
	Animal A1, A2;
	A1.input_file("test_add_Herb_1.txt");
	A2.input_file("test_add_Herb_2.txt");
	Herb H1;
	H1.add(A1);
	H1.add(A2);
	fstream f;
	f.open("test_add_Herb_result.txt", ios::out);
	for (int i = 0; i < H1.size; i++)
	{
		
		for (int j = 0; j < H1.herb[i].genome.size(); j++)
		{
			f << H1.herb[i].genome[j] << " ";
		}
		f << endl;
	}
	f.close();
	return 1;
}
int test_add_Herb_big()
{
	cout << "test_add_Herb_big has started" << endl;
	Animal A1, A2, A3;
	A1.input_file("test_add_Herb_1_big.txt");
	A2.input_file("test_add_Herb_2_big.txt");
	A3.input_file("test_add_Herb_3_big.txt");
	Herb H1;
	H1.add(A1);
	Animal H2[2] = { A2, A3 };
	H1.add(H2, 2);
	fstream f;
	f.open("test_add_Herb_big_result.txt", ios::out);
	for (int i = 0; i < H1.size; i++)
	{

		for (int j = 0; j < H1.herb[i].genome.size(); j++)
		{
			f << H1.herb[i].genome[j] << " ";
		}
		f << endl;
	}
	f.close();
	return 1;

}
int test_selection_Herb()
{
	cout << "test_selection_Herb has started" << endl;
	Animal A1, A2, A3;
	A1.input_file("test_selection_Herb_1.txt");
	A2.input_file("test_selection_Herb_2.txt");
	A3.input_file("test_selection_Herb_3.txt");
	Herb H1;
	H1.add(A1);
	H1.add(A2);
	H1.add(A3);
	FitnesFunction F1;
	F1.input_console();
	fstream f;
	H1.selection(2, F1);
	f.open("test_selection_Herb_result.txt", ios::out);
	for (int i = 0; i < H1.size; i++)
	{

		for (int j = 0; j < H1.herb[i].genome.size(); j++)
		{
			f << H1.herb[i].genome[j] << " ";
		}
		f << endl;
	}
	return 1;
	f.close();
	
}
int test_crossover_Herb()
{
	cout << "test_crossover_Herb has started" << endl;
	Animal A1, A2, A3;
	A1.input_file("test_crossover_Herb_1.txt");
	A2.input_file("test_crossover_Herb_2.txt");
	A3.input_file("test_crossover_Herb_3.txt");
	Herb H1;
	H1.add(A1);
	H1.add(A2);
	H1.add(A3);
	FitnesFunction F1;
	F1.input_console();
	fstream f;
	H1.crossover(2, F1);
	f.open("test_crossover_Herb_result.txt", ios::out);
	for (int i = 0; i < H1.size; i++)
	{

		for (int j = 0; j < H1.herb[i].genome.size(); j++)
		{
			f << H1.herb[i].genome[j] << " ";
		}
		f << endl;
	}
	f.close();
	return 1;
	

}
int test_output_console_Herb()
{
	cout << "test_output_console_Herb has started" << endl;
	Animal A1, A2, A3;
	A1.input_file("test_output_console_Herb_1.txt");
	A2.input_file("test_output_console_Herb_2.txt");
	A3.input_file("test_output_console_Herb_3.txt");
	Herb H1;
	H1.add(A1);
	H1.add(A2);
	H1.add(A3);
	H1.output_console();
	return 1;
}
