#include <iostream>

//define function to be called externally
//linker **need** to find matching name in the object
//code generated by NASM
extern "C" long long asm_foo(void);

//There's a small library of useless functions defined in assembly called library.asm and
//a header full of corresponding C extern symbols called library.hpp
#include "lib/library.hpp"

int main()
{
	fib();
}
