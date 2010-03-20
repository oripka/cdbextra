#include "cdbextra.h"
#include <cdb.h>
#include <open.h>

int cdb_remake(const char * name, const char * newname, struct cdb_make * cdbm) {

	int numrec = 0;
	struct cdb c;
	uint32 kpos;
	uint32 kp, klen, dp, dlen;
	unsigned char *key, *data;

	int new = open_write(newname);
	int old = open_read(name);
	cdb_init(&c, old);
	cdb_firstkey(&c, &kpos);

	cdb_make_start(cdbm, new);

	do {
		kp = cdb_keypos(&c);
		klen = cdb_keylen(&c);
		dp = cdb_datapos(&c);
		dlen = cdb_datalen(&c);
		key = alloca(klen);
		data = alloca(dlen);
		cdb_read(&c, key, klen, kp);
		cdb_read(&c, data, dlen, dp);
		cdb_make_add(cdbm, key, klen, data, dlen);
		++numrec;
	} while (cdb_nextkey(&c, &kpos) == 1);
	return numrec;
}
