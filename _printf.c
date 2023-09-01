#include <stdio.h>
#include <stdarg.h>

/**
*_printf function: A function that produces output according to format.
* Returns character count always excluding the null byte at the end of strings.
*/

int _printf(const char *format, ...) {
    va_list args;
    int count, i, j;
    va_start(args, format);
    /*
    *Initialize character counter.
    */
    count=0;

    for (i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%' && format[i + 1] == 'd') {
            int value = va_arg(args, int);
            /*
            *Temporarily store the value
            */
            int temp = value;
            /*
            *initialize counter for digits in value
            */
            int digits = 0;

            if (temp == 0) {
                digits = 1;
            } else {
                /*
            *Divide value by ten to see how many times 10 goes in to it. allows us to know number of digits in value
            */
                while (temp != 0) {
                    temp /= 10;
                    digits++;
                }
            }
            /*
            *Increment character count by digits,
            *Restore the value
            */
            count += digits;
            temp = value;
             /*
            *+1 for null terminator
            */
            char *buff = (char *)malloc((digits + 1) * sizeof(char));
            if (buff == NULL) {
                fprintf(stderr, "Memory allocation failed\n");
                exit(1);
            }
            int index = digits - 1;

            while (temp != 0) {
                buff[index] = (temp % 10) + '0';
                temp /= 10;
                index--;
            }
	    /**
	     * Null terminate string
	     */
	      buff[digits] = '\0'; // Null-terminate the string
            for (int j = 0; j < digits; j++) {
                _putchar(buff[j]); // Print each digit character
            }
            /*
            *Skip 'd' after processing '%'
            */
            i++;
        }
        else if (format[i] == '%' && format[i + 1] == 'c') {
            char ch = va_arg(args, int);
                _putchar(ch);
        count++;
            i++;
        }
         else if (format[i] == '%' && format[i + 1] == 's') {
            char *str = va_arg(args, char*);

            while(*str!='\0')
            {
               count++;
                _putchar(*str);
                *str++;

            }
            i++; // Skip 'd' after processing '%'
        }
        else if (format[i] == '%' && format[i + 1] == '%') {
                _putchar('%');
               count++;


            i++;
        }

         else {
            _putchar(format[i]);
            count++; // Increment character count
        }
    }

    va_end(args);

    return count;
}
