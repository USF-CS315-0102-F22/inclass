#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NT_MAX_CHARS 64

int char_to_digit(char ch, int base) {
    switch (base) {
        case 2:
            if (ch == '0' || ch == '1') {
                return ch - '0';
            }
            break;
        case 10:
            if (ch >= '0' && ch <= '9') {
                return ch - '0';
            }
            break;
        case 16:
            if (ch >= '0' && ch <= '9') {
                return ch - '0';
            }
            if (ch >= 'a' && ch <= 'f') {
                return ch - 'a' + 0xa;
            }
            if (ch >= 'A' && ch <= 'F') {
                return ch - 'A' + 0xa;
            }
            break;
    }
    printf("Bad input\n");
    exit(-1);
}

int string_to_int(char *input_str, int base) {
    int i = 0;
    int v = 0;
    int cvalue;

    while (input_str[i] != '\0') {
        cvalue = char_to_digit(input_str[i], base);
        v = (v * base) + cvalue;
        i += 1;
    }

    return v;
}

void int_to_string(int value, char *result_str, int obase) {
    int div, rem;
    int i, j = 0, len = 0;
    char tmp[NT_MAX_CHARS];

    if (value == 0) {
        tmp[len] = '0';
        len += 1;
    } else {
        while (value != 0) {
            div = value / obase;
            rem = value % obase;
            if (rem <= 9) {
                tmp[len] = '0' + rem;
            } else if (rem >= 10 && rem <= 15) {
                tmp[len] = 'a' + (rem - 0xa); 
            }
            len += 1;
            value = div;
        }
    }

    /* Put base prefix into result string */
    if (obase == 2) {
        result_str[j] = '0';
        result_str[j + 1] = 'b';
        j += 2;
    } else if (obase == 16) {
        result_str[j] = '0';
        result_str[j + 1] = 'x';
        j += 2;
    }   

    /* Reverse tmp and put in to result_str after prefix */
    for (i = len; i > 0; i--, j++) {
        result_str[j] = tmp[i - 1];
    }
    result_str[j] = '\0';
}

void parse_args(int argc, char **argv, int *ibase, int *obase,
                char *input_str, int len) {
    int i = 1;

    while (i < argc) {
        if (argv[i][0] == '-' && argv[i][1] == 'o'
            && argv[i][2] == '\0') {
            *obase = string_to_int(argv[i + 1], 10);
            i += 2;
        } else {
            char *start_input;
            if (!strncmp(argv[i], "0x", 2)) {
                *ibase = 16;
                start_input = argv[i] + 2;
            } else if (!strncmp(argv[i], "0b", 2)) {
                *ibase = 2;
                start_input = argv[i] + 2;
            } else {
                *ibase = 10;
                start_input = argv[i];
            }
            strncpy(input_str, start_input, len);
            i += 1;
        }
    }
}

int main(int argc, char **argv) {
    int ibase;
    int obase;
    char input_str[NT_MAX_CHARS];
    char result_str[NT_MAX_CHARS];
    int value;

    parse_args(argc, argv, &ibase, &obase, input_str, sizeof(input_str));
    value = string_to_int(input_str, ibase);
    int_to_string(value, result_str, obase);
    printf("%s\n", result_str);

    return 0;    
}
