#include <stdio.h>
#include "status.h"
#include "unit_test.h"

//typedef enum status Status;

int main(int argc, char* argv[])
{
	
	Status (*tests[])(char*, int) = 
	{
		test_init_default_returns_nonNULL,
		test_get_size_on_init_default_returns_0,
		test_my_string_init_c_string_returns_nonNULL,
		test_my_string_get_capacity_returns_7,
		test_my_string_compare_returns_0,
		test_my_string_compare_returns_1,
		test_my_string_compare_returns_negative_1,
		test_my_string_empty_true,
		test_my_string_empty_false,
		test_my_string_concat,
		test_my_string_at_0,
		test_my_string_at_1,
		test_my_string_at_2,
		test_my_string_at_3,
		test_my_string_at_4,
		test_my_string_pop_back_4,
		test_my_string_pop_back_3,
		test_my_string_pop_back_2,
		test_my_string_pop_back_1,
		test_my_string_pop_back_0,
		test_my_string_push_back,
		test_my_string_push_back_2,
		test_my_string_push_back_3,
		test_my_string_push_back_4,
		test_my_string_push_back_5


		//list all functions 
	
	};
	
	int number_of_functions = sizeof(tests)/sizeof(tests[0]);
	int i;
	char buffer[500];
	int success_count = 0;
	int failure_count = 0;

	for(i = 0; i < number_of_functions; i++)
	{
		if((tests[i])(buffer, 500) == FAILURE)
		{
			printf("FAILED: Test %d failed miserably\n", i);
			printf("\t%s\n", buffer);
			failure_count++;
		}else{
			printf("PASS: Test %d passed\n", i);
			printf("\t%s\n", buffer);
			success_count++;
		}
	}
	printf("Total number of tests: %d\n", number_of_functions);
	printf("%d/%d Pass, %d/%d Failure\n", success_count, number_of_functions, failure_count, number_of_functions);

return 0;
}

