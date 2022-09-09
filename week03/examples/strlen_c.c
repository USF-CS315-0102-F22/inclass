int strlen_ptr_c(char *str) {
    int len = 0;

    while (*str != '\0') {
        len += 1;
        str += 1;
    }

    return len;
}

int strlen_index_c(char *str) {
    int len = 0;

    while (str[len] != '\0') {
        len += 1;
    }

    return len;
}
