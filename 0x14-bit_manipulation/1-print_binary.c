#include "main.h"

/**
 * print_binary - prints the binary representation of a number.
 * @n: unsigned long int
 * Return: void
 */
void print_binary(unsigned long int n)
{
	if (n == 0)
	{
		putchar('0');
		return;
	}
	if (n == 1)
	{
		putchar ('1');
		return;
	}
	print_binary(n >> 1);
	putchar('0' + (n & 1));
}
