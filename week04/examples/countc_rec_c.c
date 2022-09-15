int countc_rec1_c(char c, char *str) {
    char first_ch;

    first_ch = *str;

    if (first_ch == '\0') {
        return 0;
    } else {
        if (first_ch == c) {
            return countc_rec1_c(c, str + 1) + 1;
        } else {
            return countc_rec1_c(c, str + 1);
        }
    }
}

int countc_rec_c(char c, char *str) {
    char first_ch;
    int rv;
    
    first_ch = *str;

    if (first_ch == '\0') {
        rv = 0;
    } else {
        rv = countc_rec_c(c, str + 1);
        if (first_ch == c) {
            rv = rv + 1;
        }
    }

    return rv;
}
