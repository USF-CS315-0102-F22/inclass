PROGS = pack_bytes unpack_bytes get_bitseq get_bitseq_signed merge merge_sort

PACKBYTES_OBJS = pack_bytes.o pack_bytes_c.o pack_bytes_s.o
UNPACKBYTES_OBJS = unpack_bytes.o unpack_bytes_c.o unpack_bytes_s.o 
GET_BITSEQ_OBJS = get_bitseq.o get_bitseq_s.o get_bitseq_c.o
GET_BITSEQ_SIGNED_OBJS = get_bitseq_signed.o\
						 get_bitseq_signed_c.o get_bitseq_c.o\
                         get_bitseq_signed_s.o get_bitseq_s.o
MERGE_OBJS = merge.o merge_c.o merge_util.o merge_s.o
MERGE_SORT_OBJS = merge_sort.o merge_sort_c.o merge_sort_s.o \
                  merge_c.o merge_util.o merge_s.o

OBJS = $(PACKBYTES_OBJS) $(UNPACKBYTES_OBJS) \
	   $(GET_BITSEQ_OBJS) $(GET_BITSEQ_SIGNED_OBJS) \
       $(MERGE_OBJS) $(MERGE_SORT_OBJS)

%.o: %.c
	gcc -c -g -o $@ $<

%.o: %.s
	as -g -o $@ $<

all: $(PROGS)

pack_bytes: $(PACKBYTES_OBJS)
	gcc -g -o $@ $^

unpack_bytes: $(UNPACKBYTES_OBJS)
	gcc -g -o $@ $^


get_bitseq: $(GET_BITSEQ_OBJS)
	gcc -g -o $@ $^

get_bitseq_signed: $(GET_BITSEQ_SIGNED_OBJS)
	gcc -g -o $@ $^

merge: $(MERGE_OBJS) merge_util.h
	gcc -g -o $@ $^

merge_sort: $(MERGE_SORT_OBJS) merge_util.h
	gcc -g -o $@ $^

clean:
	rm -rf $(PROGS) $(OBJS)
