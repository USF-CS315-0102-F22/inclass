void to_upper_c(char *orig, char *dst) {
    char ch;
    while ((ch = *orig++)) {
        if (ch >= 'a' && ch <= 'z')
            ch -= 32;
        *dst++ = ch;
    }
    *dst = '\0';
}
