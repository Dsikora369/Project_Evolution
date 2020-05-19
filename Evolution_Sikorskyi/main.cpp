#include "../Evolution_Sikorskyi/tests/test_FitnesFunction.h"
#include "../Evolution_Sikorskyi/tests/test_Animal.h"
#include "../Evolution_Sikorskyi/tests/test_Herb.h"

int main()
{
	if (FF_test_fitFun() == 1)
	{
		cout << "fitFun test passed" << endl;
	}
	if (test_add_Herb() == 1)
	{
		cout << "test_add_Herb passed" << endl;
	}
	if (test_add_Herb_big() == 1)
	{
		cout << "test_add_Herb_big passed" << endl;
	}
	if (test_selection_Herb() == 1)
	{
		cout << "test_selection_Herb passed" << endl;
	}
	if (test_crossover_Herb() == 1)
	{
		cout << "test_crossover_Herb passed" << endl;
	}
	if (test_output_console_Herb() == 1)
	{
		cout << "test_output_console_Herb passed" << endl;
	}
	if (test_input_console_Animal() == 1)
	{
		cout << "test_input_console_Animal passed" << endl;
	}
	if (test_empty_constructor() == 1)
	{
		cout << "test_empty_constructor passed" << endl;
	}
	if (test_random_Animal_file_input() == 1)
	{
		cout << "test_random_Animal passed" << endl;
	}
	if (test_random_Animal_console_input() == 1)
	{
		cout << "test_random_Animal_console_input passed" << endl;
	}
	if (test_vector_Animal() == 1)
	{
		cout << "test_vector_Animal passed" << endl;
	}
	if (test_mutate_old_Animal() == 1)
	{
		cout << "test_mutate_old_Animal passed" << endl;
	}
	if (test_mutate_new_Animal() == 1)
	{
		cout << "test_mutate_new_Animal passed" << endl;
	}
	if (test_breed_Animal() == 1)
	{
		cout << "test_breed_Animal passed" << endl;
	}
	if (test_fitness_Animal() == 1)
	{
		cout << "test_fitness_Animal passed" << endl;
	}
}