CFLAGS+=-g -I/opt/diet/include -I.
LDFLAGS+=-g -L/opt/diet/lib -lowfat 

CDB_OBJS:= cdb/cdb_dump.o cdb/cdb_make_add_str.o cdb/cdb_make_finish_close.o cdb/cdb_remake.o

cdb/cdb_dump.o: cdb/cdb_dump.c cdbextra.h
cdb/cdb_make_add_str.o: cdb/cdb_make_add_str.c cdbextra.h
cdb/cdb_remake.o: cdb/cdb_remake.c cdbextra.h

cdbextra.a: $(CDB_OBJS)
	ar cr $@ $(CDB_OBJS)
	ranlib $@

all: $(CDB_OBJS) cdbtest.o cdbextra.a

clean:
	rm -rf *.o *~ $(CDB_OBJS) cdbtest.o cdbextra.a