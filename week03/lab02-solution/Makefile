PROGS = add4 quadratic min
ADD4_OBJS = add4_c.o add4_s.o add4.o
QUADRATIC_OBJS = quadratic.o quadratic_s.o quadratic_c.o
MIN_OBJS = min.o min_c.o min_s.o

%.o: %.s
	as -g -o $@ $<

%.o: %.c
	gcc -c -g -o $@ $<

all: $(PROGS)

add4: $(ADD4_OBJS)
	gcc -g -o $@ $^

quadratic: $(QUADRATIC_OBJS)
	gcc -g -o $@ $^

min: $(MIN_OBJS)
	gcc -g -o $@ $^

clean:
	rm -rf $(PROGS) $(ADD4_OBJS) $(QUADRATIC_OBJS) $(MIN_OBJS)
