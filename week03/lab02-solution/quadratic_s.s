.global quadratic_s

# a0 - int x
# a1 - int a
# a2 - int b
# a3 - int c

quadratic_s:
    mul t0, a0, a0    # t0 = a0 (x) * a0 (x)
    mul t0, a1, t0    # t0 = a1 (a) * t0 (x * x)
    mul t1, a2, a0    # t1 = a2 (b) * a0 (x)
    add a0, t0, t1    # a0 = t0 (a * x * x) + t1 (b * x)
    add a0, a0, a3    # a0 = a0 ((a * x * x) + (b * x)) + a3 (c)
    ret
