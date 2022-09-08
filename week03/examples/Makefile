PROGS = sumarr sizes add4 strlen countc

SUMARR_OBJS = sumarr.o sumarr_c.o sumarr_s.o
ADD4_OBJS = add4.o add4_c.o add4_s.o
STRLEN_OBJS = strlen.o strlen_c.o strlen_s.o
COUNTC_OBJS = countc.o countc_c.o countc_s.o
SIZES_OBJS = sizes.o


all : $(PROGS)

%.o : %.c
	gcc -c -g -o $@ $<

%.o : %.s
	as -g -o $@ $<

sumarr : $(SUMARR_OBJS)
	gcc -g -o $@ $^

add4 : $(ADD4_OBJS)
	gcc -g -o $@ $^

strlen : $(STRLEN_OBJS)
	gcc -g -o $@ $^

countc : $(COUNTC_OBJS)
	gcc -g -o $@ $^


sizes : $(SIZES_OBJS)
	gcc -g -o $@ $^


clean :
	rm -rf $(PROGS) $(SUMARR_OBJS) $(SIZES_OBJS) $(ADD4_OBJS) \
		   $(STRLEN_OBJS) $(COUNTC_OBJS)
