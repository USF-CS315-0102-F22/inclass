PROGS = to_upper max3 find_max_index sort 
TO_UPPER_OBJS = to_upper.o to_upper_c.o
MAX3_OBJS = max3.o max3_c.o
FIND_MAX_INDEX_OBJS = find_max_index.o find_max_index_c.o
SORT_OBJS = sort.o sort_c.o find_max_index_c.o

%.o: %.c
	gcc -g -c -o $@ $<

all: $(PROGS)

to_upper: $(TO_UPPER_OBJS)
	gcc -g -o $@ $^
	
max3: $(MAX3_OBJS)
	gcc -g -o $@ $^

find_max_index: $(FIND_MAX_INDEX_OBJS)
	gcc -g -o $@ $^

sort: $(SORT_OBJS)
	gcc -g -o $@ $^

clean:
	rm -rf $(PROGS) $(TO_UPPER_OBJS) $(MAX3_OBJS) $(FIND_MAX_INDEX_OBJS) $(SORT_OBJS)
