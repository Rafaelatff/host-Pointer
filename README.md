# host-Pointer
This project uses STM32CubeIDE and it's a program created to practice my C habilities during the course 'Microcontroller Embedded C Programming: Absolute Beginners' from FastBit Embedded Brain Academy.

## BoK

Pointer are memory addresses.

``` 
unsigned long int addressOfa1 = &a1; //this is a pointer (not a number), this returns a warning for data type mismatch (solve this with typecasting -> showed the next line).

unsigned long long int addressOfa1 = (unsigned long int) &a1; //pointers in host are 8 bytes (64-bit architeture).

printf(“address of variable a1 = %l64X\n”, addressOfa1); //addresses are unsigned  
``` 

O tamanho do endereço depende da arquitetura. Arquitetura 16 bits os endereços tem 2 bytes. 

``` 
<Pointer data type> <Variable name>; 

long long int someAddress = 0x00007FFF8E3C3824; //Not valid 

char* address1 = (char*) 0x00007FFF8E3C3824; //valid pointer definition & initialization 
``` 
O < Pointer data type > não controla o tamanho da memória para as variáveis de ponteiro. Apenas controle seu comportamento. Por exemplo, ele decide, pelo tipo de pointer a quantidade de bytes do dado a ser lido. To read, see the following code:

``` 
chat data = *address1; // dereferencing a pointer to read data 

*address1 = 0x89 // dereferencing a pointer to write data - to re-write its value (value inside the pointer)
``` 

Nota: * - “Value at Address” operator and & - “Address of” operator.

**Implementing pointer addresses:**

if the pointer data type is 'char' our uint8_t type, the ++ the pointer, 1 byte will be add to its address. See:

![image](https://user-images.githubusercontent.com/58916022/206286187-1ee2e1c9-a2a1-43c1-94b5-811f7a87e720.png)

if the pointer data type is 'short' or uint16_t type, the ++ the pointer, 2 bytes will be add to its address. See:

![image](https://user-images.githubusercontent.com/58916022/206286331-1ee54981-a79c-492e-ab0b-c1ff6fe0bb8b.png)

The same happens when implementing a 'int' or uint32_t pointer data type, but in this case, 4 Bytes are added to its address. See:

![image](https://user-images.githubusercontent.com/58916022/206286754-b2b5924d-00da-46e8-bc44-69c691d9b19f.png)

Note that the 'int' data type has 32 bits in STM32CubeIDE/MinGW, but it is compiler-dependent! It may have a diffent value such as 16-bit!

**Type Qualifiers in ‘C’ (to qualifing the declaration):**

Local const variable are placed in RAM (since its read-only). 

Global const variable are stored in ROM or FLASH (depend on linker script and hw). 
In STM32 target hw – Gloabal const variables – live in FLASH memory. The flash memory of the uC is write-protected so it can’t be changed even by writting in its address. The IDE crashes trying to do that. To make it happen, use a local variable.

Volatile qualifier it is used when the data can change, with or without the knowlege of the programmer. Mainly data that can depend on external world (such as inputs).

**const – also can be used to pointers**

``` 
uint8_t const *const pData = (uint8_t*) 0x20000000; 
// pData is a constant pointer (*) pointing to constant data of type unsigned integer_8
``` 

**volatile – also can be used to pointers**

``` 
uint32_t volatile *pPortCInReg = (uint32_t*) 0x40020810; 
// *pPortCInReg is a register, read-only, that change according to external voltage applied to input pins of C port
``` 

**volatile is important, mainly when using compiler optmization, once it can ignore that some data can change without notice.**
