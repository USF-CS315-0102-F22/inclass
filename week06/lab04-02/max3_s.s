# max3_s.s - find the maximum value of three arguments without using max2

.global max3_s

/* a0 - v0
 * a1 - v1
 * a2 - v2
 */
max3_s:
    bgt a0, a1, max2    # if a0 is already the greater of the first two
    mv a0, a1           # else a1 is the greater of the first two
max2:
    bgt a0, a2, done    # if a0 is the greater of the first to with the third
    mv a0, a2           # else the third is the greater of all three
done:
    ret                 # a0 contains the greater of all three
