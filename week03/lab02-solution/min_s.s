.global min_s

# a0 - int a
# a1 - int b

# t0 - int r

min_s:
    bge a0, a1, min_s_else  # if a0 (a) >= a1 (b) jump to else
    mv t0, a0               # t0 (r) = a0 (a)
    j min_s_done            # jump to done (skip else code)
min_s_else:
    mv t0, a1               # t0 (r) = a1 (b)
min_s_done:
    mv a0, t0               # Need to put return value in a0
    ret
