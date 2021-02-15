
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "generic.h"
#include "my_string.h"

MY_STRING my_string_init_default() {

	My_string *pString = (My_string *)malloc(sizeof(My_string));

	if (pString != NULL) {

		pString->capacity = 7;
		pString->size = 0;
		pString->data = (char *)malloc(pString->capacity);
		if (pString->data == NULL) {
			free(pString);
			pString = NULL;
		}
	}
	return (MY_STRING)pString;
}

void my_string_destroy(Item *pItem) {

	My_string *pString = (My_string *)*pItem;

	free(pString->data);
	free(pString);

	*pItem = NULL;

}

MY_STRING my_string_init_c_string(const char *c_string) {

	My_string *pString = (My_string *)malloc(sizeof(My_string));
	int i=0, n = 0;
	while (c_string[n] != '\0') {
		++n;
	}

	if (pString != NULL) {
		pString->size = n;
		pString->capacity = n++;
		pString->data = (char*)malloc(sizeof(char)*n);
		if (pString->data == NULL) {

			free(pString);
			return NULL;

		}
		while (c_string[i] != '\0') {
			pString->data[i] = c_string[i];
			i++;
		}
	}
	return (MY_STRING)pString;

}

int my_string_get_capacity(MY_STRING hMy_string) {
	My_string* pMy_string = (My_string*)hMy_string;
	return pMy_string->capacity;
}

int my_string_get_size(MY_STRING hMy_string) {
	My_string* pMy_string = (My_string*)hMy_string;
	return pMy_string->size;
}

int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string) {
	
	My_string* pString1 = (My_string*)hLeft_string;
	My_string* pString2 = (My_string*)hRight_string;

	int i = 0;
	int retVal = 0;
	int maxSize = (pString1->size > pString2->size) ? pString1->size : pString2->size;

	while (i < maxSize)
	{
		if (i > pString2->size) return 1;
		if (i > pString1->size) return -1;

		if (pString1->data[i] < pString2->data[i]) retVal = -1;
		else if (pString1->data[i] > pString2->data[i]) retVal = 1;

		if (retVal != 0) break;

		i++;
	}

	return retVal;
}

Status my_string_extraction(MY_STRING hMy_string, FILE *fp) {

	My_string *pString = (My_string *)hMy_string;
	char c;

	pString->size = 0;
	c = fgetc(fp);

	while (c == EOF || isspace(c)) {
		if (c == EOF) {
			return FAILURE;
		}
		c = fgetc(fp);
	}

	while (c != EOF && !(isspace(c))) {
		my_string_push_back(hMy_string, c);
		c = fgetc(fp);
	}

	if (c != EOF) {
		ungetc(c, fp);
	}

	return SUCCESS;

}

Status my_string_insertion(MY_STRING hMy_string, FILE *fp) {

	My_string *pString = (My_string*)hMy_string;
	int i;

	for (i = 0; i < pString->size; i++) {
		fprintf(fp, "%c", pString->data[i]);
	}

	return SUCCESS;

}

Status my_string_push_back(MY_STRING hMy_string, char item) {

	My_string *pString = (My_string *)hMy_string;
	int i;
	char *pTemp;

	if (pString->size >= pString->capacity-1) {
		pTemp = (char*)malloc(sizeof(char)*(pString->capacity) * 2);
		if (pTemp == NULL) {
			return FAILURE;
		}
		for (i = 0; i < pString->capacity; i++) {
			pTemp[i] = pString->data[i];
		}
		pString->data = pTemp;
		pString->capacity *= 2;
	}

	pString->data[(pString->size)++] = item;
	my_string_c_str(hMy_string);

	return SUCCESS;

}

Status my_string_pop_back(MY_STRING hMy_string) {

	My_string *pString = (My_string *)hMy_string;

	if (pString->size <= 0) {
		return FAILURE;
	}

	pString->size--;

	return SUCCESS;

}

char *my_string_at(MY_STRING hMy_string, int index) {

	My_string *pString = (My_string *)hMy_string;

	if (index >= 0 && index <= pString->size) {
		return &(pString->data[index]);
	}

	return NULL;

}

char *my_string_c_str(MY_STRING hMy_string) {

	My_string *pString = (My_string *)hMy_string;

	pString->data[pString->size] = '\0';
	return pString->data;

}

Status my_string_concat(MY_STRING hResult, MY_STRING hAppend) {

	My_string *phAppend = (My_string *)hAppend;
	int i;

	for (i = 0; i < phAppend->size; i++)
		if (!(my_string_push_back(hResult, phAppend->data[i]))) return FAILURE;

	return SUCCESS;

}

Boolean my_string_empty(MY_STRING hMy_string) {

	if (((My_string *)hMy_string)->size == 0) return TRUE;

	return FALSE;

}

void my_string_assignment(Item *pLeft, Item Right) {


	My_string *pMy_string_left = (My_string *)*pLeft;
	My_string *pMy_string_right = (My_string *)Right;
	int i;
	const char *temp;

	temp = my_string_c_str((MY_STRING)Right);

	if (pMy_string_left == NULL) {

		pMy_string_left = my_string_init_c_string(temp);

	}
	else {

		pMy_string_left->size = 0;

		for (i = 0; i < pMy_string_right->size + 1; i++) {

			my_string_push_back(pMy_string_left, pMy_string_right->data[i]);

		}

	}

	*pLeft = pMy_string_left;

}

Status get_word_key_value(MY_STRING current_word_family, MY_STRING new_key, MY_STRING word, char guess) {
	int i;
	while (!my_string_empty(new_key)) {
		my_string_pop_back(new_key);
	}
	for (i = 0; i < my_string_get_size(word); i++) {
		if (!my_string_push_back(new_key, *my_string_at(word, i) == guess ? guess : *my_string_at(current_word_family, i))) {
			return FAILURE;
		}
	}
	return SUCCESS;
}
