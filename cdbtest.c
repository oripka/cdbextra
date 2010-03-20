#include <unistd.h>

#include <alloca.h>
#include <str.h>
#include <open.h>

#include <cdb.h>
#include <cdb_make.h>
#include "cdbextra.h"

#define tmpfile "mydb.db"
#define newtmpfile "mynewdb.db"

int example_add(const char * name);

int example_add(const char * name) {
	struct cdb_make cdbm;
	int add = open_read(name);
	unsigned char key[] = "bla";
	unsigned char key2[] = "bla222";
	unsigned char val[] = "blussb";
	size_t klen = str_len((const char*)key);
	size_t vlen = str_len((const char*)val);
	cdb_make_start(&cdbm, add);
	cdb_make_add(&cdbm, key, klen, val, vlen);
	cdb_make_add(&cdbm, key2, klen + 3, val, vlen);
	cdb_make_add(&cdbm, key, klen, val, vlen);
	cdb_make_finish(&cdbm);
	close(add);
	return 3;
}

int main(int argc, char* argv[]) {
	struct cdb_make cdbm;

	example_add(tmpfile);
	cdb_dump(tmpfile);

	cdb_remake(tmpfile, newtmpfile, &cdbm);
	cdb_make_add_str(&cdbm, "xxx", "yyy");
	cdb_make_finish_close(&cdbm);

	write(1, "--\n", 3);

	cdb_dump(newtmpfile);

	return 0;
}
