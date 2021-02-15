#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "status.h"
#include "my_string.h"

//typedef enum status Status;

Status test_init_default_returns_nonNULL(char* buffer, int length)
{
	MY_STRING hString = NULL;

	hString = my_string_init_default();

	if(hString == NULL)
	{
		my_string_destroy(&hString);
		strncpy(buffer, "test_init_default_returns_nonNULL\n"
				"my_string_init_default retrns NULL", length);

		return FAILURE;
	}else{
		my_string_destroy(&hString);
		strncpy(buffer, "\ttest_init_default_returns_nonNULL\n", length);
		return SUCCESS;
	}

}

Status test_get_size_on_init_default_returns_0(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;

	hString = my_string_init_default();

	if(my_string_get_size(hString) != 0)
	{
		status = FAILURE;
		printf("Expected a size of 0 but got %d\n", my_string_get_size(hString));
		strncpy(buffer, "test_get_size_on_init_default_returns_0\n"
				"Did not receive 0 from get_size init_default\n" , length);
	}else{
		status = SUCCESS;
		strncpy(buffer, "test_get_size_on_init_default_returns_0\n", length);
	}

	my_string_destroy(&hString);
	return status;
}

Status test_my_string_init_c_string_returns_nonNULL(char* buffer, int length)
{
	MY_STRING hString = NULL;
	char str[] = "apple";

	hString = my_string_init_c_string(str);

	if(hString == NULL)
	{
		my_string_destroy(&hString);
		strncpy(buffer, "test_init_c_string_returns_nonNULL\n"
				"my_string_init_c_string retrns NULL", length);

		return FAILURE;
		

	}else{
		my_string_destroy(&hString);
		strncpy(buffer, "\ttest_init_c_string_returns_nonNULL\n", length);
		return SUCCESS;
	}

}

Status test_my_string_get_capacity_returns_7(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;

	hString = my_string_init_default();

	if(my_string_get_capacity(hString) != 7)
	{
		status = FAILURE;
		printf("Expected a capacity of 7 but got %d\n", my_string_get_capacity(hString));
		strncpy(buffer, "test_get_capacity_on_init_default_returns_7\n"
				"Did not receive 7 from get_capacity init_default\n" , length);
	}else{
		status = SUCCESS;
		strncpy(buffer, "test_get_capacity_on_init_default_returns_7\n", length);
	}

	my_string_destroy(&hString);
	return status;

}

Status test_my_string_compare_returns_0(char* buffer, int length)
{
	MY_STRING l_string = my_string_init_c_string("apple");
	//MY_STRING r_string = my_string_init_c_string("apple");
	Status status = 0;


	if(my_string_compare(l_string, l_string) != 0)
	{
		status = FAILURE;
		printf("Expected a value of o but got %d\n", my_string_compare(l_string, l_string));
		strncpy(buffer, "test_mt_string_compare_returns_0\n"
				"Did not receive 0 from my_string_compare\n" , length);
	}else{
		status = SUCCESS;
		strncpy(buffer, "test_my_string_caompare_returns_0\n", length);
	}


	my_string_destroy(&l_string);
	return status;

}

Status test_my_string_compare_returns_negative_1(char* buffer, int length)
{
	MY_STRING l_string = my_string_init_c_string("app");
	MY_STRING r_string = my_string_init_c_string("apple");
	Status status = 0;


	if(my_string_compare(l_string, r_string) != (-1))
	{
		status = FAILURE;
		printf("Expected a value of o but got %d\n", my_string_compare(l_string, r_string));
		strncpy(buffer, "test_mt_string_compare_returns_-1\n"
				"Did not receive -1 from my_string_compare\n" , length);
	}else{
		status = SUCCESS;
		strncpy(buffer, "test_my_string_caompare_returns_-1\n", length);
	}


	my_string_destroy(&l_string);
	my_string_destroy(&r_string);
	return status;

}

Status test_my_string_compare_returns_1(char* buffer, int length)
{
	MY_STRING l_string = my_string_init_c_string("apple");
	MY_STRING r_string = my_string_init_c_string("app");
	Status status = 0;


	if(my_string_compare(l_string, r_string) != 1)
	{
		status = FAILURE;
		printf("Expected a value of o but got %d\n", my_string_compare(l_string, r_string));
		strncpy(buffer, "test_mt_string_compare_returns_-1\n"
				"Did not receive 1 from my_string_compare\n" , length);
	}else{
		status = SUCCESS;
		strncpy(buffer, "test_my_string_caompare_returns_1\n", length);
	}


	my_string_destroy(&l_string);
	my_string_destroy(&r_string);
	return status;

}

Status test_my_string_empty_true(char* buffer, int length)
{
	MY_STRING str = my_string_init_c_string("");
	Status status;

	if(my_string_empty(str) != TRUE){
	status = FAILURE;
		printf("Expected a value of true but got %d\n", my_string_empty(str));
		strncpy(buffer, "test_my_string_empty_returns_true\n"
				"Did not receive true from my_string_empty\n" , length);
	}else{
		status = SUCCESS;
		strncpy(buffer, "test_my_string_empty_returns_true\n", length);

	}

	my_string_destroy(&str);
	return status;
}

Status test_my_string_empty_false(char* buffer, int length)
{
	MY_STRING str = my_string_init_c_string("apple");
	Status status;

	if(my_string_empty(str) != FALSE){
	status = FAILURE;
		printf("Expected a value of false but got %d\n", my_string_empty(str));
		strncpy(buffer, "test_my_string_empty_returns_false\n"
				"Did not receive false from my_string_empty\n" , length);
	}else{
		status = SUCCESS;
		strncpy(buffer, "test_my_string_empty_returns_false\n", length);

	}

	my_string_destroy(&str);
	return status;

}

Status test_my_string_concat(char* buffer, int length)
{
	MY_STRING l_string = my_string_init_c_string("apple");
	MY_STRING r_string = my_string_init_c_string("mango");
	Status status;


	if(my_string_concat(l_string, r_string) != SUCCESS)
	{
		status = FAILURE;
		printf("Expected a value of SUCCESS but got %d\n", my_string_concat(l_string, r_string));
		strncpy(buffer, "test_mt_string_concat_returns_FAILURE\n"
				"Did not receive SUCCESS from my_string_concat\n" , length);
	}else{
		status = SUCCESS;
		strncpy(buffer, "test_my_string_concat_returns_SUCCESS\n", length);
	}


	my_string_destroy(&l_string);
	my_string_destroy(&r_string);
	return status;

}

Status test_my_string_at_0(char* buffer, int length)
{
	MY_STRING str = my_string_init_c_string("apple");
	Status status;

	if(*(my_string_at(str, 0)) != 'a'){
	status = FAILURE;
		printf("Expected a value of 'a' but got %c\n", *(my_string_at(str, 0)));
		strncpy(buffer, "test_my_string_at_returns_something_else\n"
				"Did not receive 'a' from my_string_at\n" , length);
	}else{
		status = SUCCESS;
		strncpy(buffer, "test_my_string_at_returns_a\n", length);

	}

	my_string_destroy(&str);
	return status;

}

Status test_my_string_at_1(char* buffer, int length)
{
	MY_STRING str = my_string_init_c_string("apple");
	Status status;

	if(*(my_string_at(str, 1)) != 'p'){
	status = FAILURE;
		printf("Expected a value of 'p' but got %c\n", *(my_string_at(str, 1)));
		strncpy(buffer, "test_my_string_at_returns_something_else\n"
				"Did not receive 'p' from my_string_at\n" , length);
	}else{
		status = SUCCESS;
		strncpy(buffer, "test_my_string_at_returns_p\n", length);

	}

	my_string_destroy(&str);
	return status;

}

Status test_my_string_at_2(char* buffer, int length)
{
	MY_STRING str = my_string_init_c_string("apple");
	Status status;

	if(*(my_string_at(str, 2)) != 'p'){
	status = FAILURE;
		printf("Expected a value of 'p' but got %c\n", *(my_string_at(str, 2)));
		strncpy(buffer, "test_my_string_at_returns_something_else\n"
				"Did not receive 'p' from my_string_at\n" , length);
	}else{
		status = SUCCESS;
		strncpy(buffer, "test_my_string_at_returns_p\n", length);

	}

	my_string_destroy(&str);
	return status;

}

Status test_my_string_at_3(char* buffer, int length)
{
	MY_STRING str = my_string_init_c_string("apple");
	Status status;

	if(*(my_string_at(str, 3)) != 'l'){
	status = FAILURE;
		printf("Expected a value of 'l' but got %c\n", *(my_string_at(str, 3)));
		strncpy(buffer, "test_my_string_at_returns_something_else\n"
				"Did not receive 'l' from my_string_at\n" , length);
	}else{
		status = SUCCESS;
		strncpy(buffer, "test_my_string_at_returns_l\n", length);

	}

	my_string_destroy(&str);
	return status;


}

Status test_my_string_at_4(char* buffer, int length)
{
	MY_STRING str = my_string_init_c_string("apple");
	Status status;

	if(*(my_string_at(str, 4)) != 'e'){
	status = FAILURE;
		printf("Expected a value of 'e' but got %c\n", *(my_string_at(str, 4)));
		strncpy(buffer, "test_my_string_at_returns_something_else\n"
				"Did not receive 'e' from my_string_at\n" , length);
	}else{
		status = SUCCESS;
		strncpy(buffer, "test_my_string_at_returns_e\n", length);

	}

	my_string_destroy(&str);
	return status;


}

Status test_my_string_pop_back_4(char* buffer, int length)
{
	MY_STRING str = my_string_init_c_string("apple");
	Status status;

	if(my_string_pop_back(str) != SUCCESS){
	status = FAILURE;
		printf("Expected a value of SUCCESS but got %d\n", my_string_pop_back(str));
		strncpy(buffer, "test_my_string_at_returns_something_else\n"
				"Did not receive SUCCESS from my_string_at\n" , length);
	}else{
		status = SUCCESS;
		strncpy(buffer, "test_my_string_at_returns_SUCCESS\n", length);

	}

	my_string_destroy(&str);
	return status;

}
Status test_my_string_pop_back_3(char* buffer, int length)
{
	MY_STRING str = my_string_init_c_string("apple");
	Status status;

	if(my_string_pop_back(str) != SUCCESS){
	status = FAILURE;
		printf("Expected a value of SUCCESS but got %d\n", my_string_pop_back(str));
		strncpy(buffer, "test_my_string_at_returns_something_else\n"
				"Did not receive SUCCESS from my_string_at\n" , length);
	}else{
		status = SUCCESS;
		strncpy(buffer, "test_my_string_at_returns_SUCCESS\n", length);

	}

	my_string_destroy(&str);
	return status;

}

Status test_my_string_pop_back_2(char* buffer, int length)
{
	MY_STRING str = my_string_init_c_string("apple");
	Status status;

	if(my_string_pop_back(str) != SUCCESS){
	status = FAILURE;
		printf("Expected a value of SUCCESS but got %d\n", my_string_pop_back(str));
		strncpy(buffer, "test_my_string_at_returns_something_else\n"
				"Did not receive SUCCESS from my_string_at\n" , length);
	}else{
		status = SUCCESS;
		strncpy(buffer, "test_my_string_at_returns_SUCCESS\n", length);

	}

	my_string_destroy(&str);
	return status;

}

Status test_my_string_pop_back_1(char* buffer, int length)
{
	MY_STRING str = my_string_init_c_string("apple");
	Status status;

	if(my_string_pop_back(str) != SUCCESS){
	status = FAILURE;
		printf("Expected a value of SUCCESS but got %d\n", my_string_pop_back(str));
		strncpy(buffer, "test_my_string_at_returns_something_else\n"
				"Did not receive SUCCESS from my_string_at\n" , length);
	}else{
		status = SUCCESS;
		strncpy(buffer, "test_my_string_at_returns_SUCCESS\n", length);

	}

	my_string_destroy(&str);
	return status;

}

Status test_my_string_pop_back_0(char* buffer, int length)
{
	MY_STRING str = my_string_init_c_string("apple");
	Status status;

	if(my_string_pop_back(str) != SUCCESS){
	status = FAILURE;
		printf("Expected a value of SUCCESS but got %d\n", my_string_pop_back(str));
		strncpy(buffer, "test_my_string_at_returns_something_else\n"
				"Did not receive SUCCESS from my_string_at\n" , length);
	}else{
		status = SUCCESS;
		strncpy(buffer, "test_my_string_at_returns_SUCCESS\n", length);

	}

	my_string_destroy(&str);
	return status;

}

Status test_my_string_push_back(char* buffer, int length)
{
	MY_STRING str = my_string_init_c_string("app");
	Status status;

	if(my_string_push_back(str, 'a') != SUCCESS){
	status = FAILURE;
		printf("Expected a value of SUCCESS but got %d\n", my_string_push_back(str, 'a'));
		strncpy(buffer, "test_my_string_at_returns_something_else\n"
				"Did not receive SUCCESS from my_string_at\n" , length);
	}else{
		status = SUCCESS;
		strncpy(buffer, "test_my_string_at_returns_SUCCESS\n", length);

	}

	my_string_destroy(&str);
	return status;

}

Status test_my_string_push_back_2(char* buffer, int length)
{
	MY_STRING str = my_string_init_c_string("app");
	Status status;

	if(my_string_push_back(str, 'l') != SUCCESS){
	status = FAILURE;
		printf("Expected a value of SUCCESS but got %d\n", my_string_push_back(str, 'l'));
		strncpy(buffer, "test_my_string_at_returns_something_else\n"
				"Did not receive SUCCESS from my_string_at\n" , length);
	}else{
		status = SUCCESS;
		strncpy(buffer, "test_my_string_at_returns_SUCCESS\n", length);

	}

	my_string_destroy(&str);
	return status;

}

Status test_my_string_push_back_3(char* buffer, int length)
{
	MY_STRING str = my_string_init_c_string("app");
	Status status;

	if(my_string_push_back(str, 'm') != SUCCESS){
	status = FAILURE;
		printf("Expected a value of SUCCESS but got %d\n", my_string_push_back(str, 'm'));
		strncpy(buffer, "test_my_string_at_returns_something_else\n"
				"Did not receive SUCCESS from my_string_at\n" , length);
	}else{
		status = SUCCESS;
		strncpy(buffer, "test_my_string_at_returns_SUCCESS\n", length);

	}

	my_string_destroy(&str);
	return status;
}

Status test_my_string_push_back_4(char* buffer, int length)
{
	MY_STRING str = my_string_init_c_string("app");
	Status status;

	if(my_string_push_back(str, 'g') != SUCCESS){
	status = FAILURE;
		printf("Expected a value of SUCCESS but got %d\n", my_string_push_back(str, 'g'));
		strncpy(buffer, "test_my_string_at_returns_something_else\n"
				"Did not receive SUCCESS from my_string_at\n" , length);
	}else{
		status = SUCCESS;
		strncpy(buffer, "test_my_string_at_returns_SUCCESS\n", length);

	}

	my_string_destroy(&str);
	return status;
}

Status test_my_string_push_back_5(char* buffer, int length)
{
	MY_STRING str = my_string_init_c_string("app");
	Status status;

	if(my_string_push_back(str, 'w') != SUCCESS){
	status = FAILURE;
		printf("Expected a value of SUCCESS but got %d\n", my_string_push_back(str, 'w'));
		strncpy(buffer, "test_my_string_at_returns_something_else\n"
				"Did not receive SUCCESS from my_string_at\n" , length);
	}else{
		status = SUCCESS;
		strncpy(buffer, "test_my_string_at_returns_SUCCESS\n", length);

	}

	my_string_destroy(&str);
	return status;
}







