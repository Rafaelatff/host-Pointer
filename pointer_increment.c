/*
 * pointer_increment.c
 *
 *  Created on: 5 de dez de 2022
 *      Author: r.freitas
 */


#include <stdio.h>

int main (void){

	long long int g_data = 0xFFFEABCD11112345;
	int *pAddress;

	pAddress = (int*)&g_data; // need to type casting
	printf("Value at address %p is: %x\n",pAddress,*pAddress);

	pAddress = pAddress + 1;
	printf("Value at address %p is: %x\n",pAddress,*pAddress);
}
