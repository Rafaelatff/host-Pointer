/*
 * pointer.c
 *
 *  Created on: 5 de dez de 2022
 *      Author: r.freitas
 */

#include <stdio.h>

int main (void){

	// 1. Create a chat type variable and initialize it to value 100
	char data = 100;
	printf("Value of data is: %d\n",data);
	// 2. Print the address of the above variable
	printf("Address of the variable data is: %p\n", &data);
	// 3. Create a pointer variable and store the address of the above variable
	char* pAddress = &data; //tip: start pointer variable with 'p'
	// 4. Perform read operation on the pointer variable to fetch 1B of data from the pointer
	char value = *pAddress;
	// 5. Print the data obtained from the read operation on the pointer
	printf("read value is: %d\n",value);
	// 6. Perform write operation on the pointer to store the value 65
	*pAddress = 65;
	// 7. Print the value of the variable defined in step 1
	printf("New value of data is: %d\n",data);
}
