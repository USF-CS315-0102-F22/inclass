PROGS = bits

BITS_OBJS = bits.o bits_c.o bits_s.o

OBJS = $(BITS_OBJS)

%.o: %.c
	gcc -c -g -o $@ $<

%.o: %.s
	as -g -o $@ $<

all: $(PROGS)

bits: $(BITS_OBJS)
	gcc -g -o $@ $^

clean:
	rm -rf $(PROGS) $(OBJS)
