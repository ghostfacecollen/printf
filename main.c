#include "main.h"
int main() {
    int num = 42;
    int printed_chars = _printf("The number is: %%%\n");
    _printf("Total characters printed: %d\n", printed_chars);
    return 0;
}
