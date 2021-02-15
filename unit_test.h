#ifndef UNIT_TEST_H
#define UNIT_TEST_H
#include "status.h"

//typedef enum status Status;

Status test_init_default_returns_nonNULL(char* buffer, int length);
Status test_get_size_on_init_default_returns_0(char* buffer, int length);
Status test_my_string_init_c_string_returns_nonNULL(char* buffer, int length);
Status test_my_string_get_capacity_returns_7(char* buffer, int length);
Status test_my_string_compare_returns_0(char* buffer, int length);
Status test_my_string_compare_returns_negative_1(char* buffer, int length);
Status test_my_string_compare_returns_1(char* buffer, int length);
Status test_my_string_empty_true(char* buffer, int length);
Status test_my_string_empty_false(char* buffer, int length);
Status test_my_string_concat(char* buffer, int length);
Status test_my_string_at_0(char* buffer, int length);
Status test_my_string_at_1(char* buffer, int length);
Status test_my_string_at_2(char* buffer, int length);
Status test_my_string_at_3(char* buffer, int length);
Status test_my_string_at_4(char* buffer, int length);
Status test_my_string_pop_back_4(char* buffer, int length);
Status test_my_string_pop_back_3(char* buffer, int length);
Status test_my_string_pop_back_2(char* buffer, int length);
Status test_my_string_pop_back_1(char* buffer, int length);
Status test_my_string_pop_back_0(char* buffer, int length);
Status test_my_string_push_back(char* buffer, int length);
Status test_my_string_push_back_2(char* buffer, int length);
Status test_my_string_push_back_3(char* buffer, int length);
Status test_my_string_push_back_4(char* buffer, int length);
Status test_my_string_push_back_5(char* buffer, int length);





#endif
