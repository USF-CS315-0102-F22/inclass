PROG = analyze
OBJS = analyze.o fib_rec_s.o is_pal_rec_s.o get_bitseq_s.o quadratic_s.o 

%.o: %.c
	gcc -c -g -o $@ $<

%.o: %.s
	as -g -o $@ $<

$(PROG): $(OBJS)
	gcc -g -o $@ $^
	
clean:
	rm -rf $(PROG) $(OBJS)

