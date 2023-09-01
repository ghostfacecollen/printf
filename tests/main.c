#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
      int len;
      int len2;
     

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
_printf("Length from _printf: %d\n", len);
    printf("Length from printf: %d\n", len2);
    return 0;
}
