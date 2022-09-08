.global add4_s

# Arguments in a0, a1, a2, a3

# a0 - int a
# a1 - int b
# a2 - int c
# a3 - int d

add4_s:
    add a0, a0, a1    # a0 = a0 (a) + a1 (b)
    add a0, a0, a2    # a0 = a0 (a + b) + a2 (c)
    add a0, a0, a3    # a0 = a0 (a + b + c) + a3 (d)
    # Return value in a0
    ret 
