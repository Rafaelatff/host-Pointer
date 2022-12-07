/*
 * pointer_typecasting.c
 *
 *  Created on: 5 de dez de 2022
 *      Author: r.freitas
 */

#include <stdio.h>

int main (void){

	long long int g_data = 0xFFFEABCD11112345;
	char *pAddress1;
	pAddress1 = (char*)&g_data; // need to type casting
	printf("Value at address %p is: %x\n",pAddress1,*pAddress1);

	int *pAddress2;
	pAddress2 = (int*)&g_data; // need to type casting
	printf("Value at address %p is: %x\n",pAddress2,*pAddress2);
}
