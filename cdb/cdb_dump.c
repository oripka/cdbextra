#include <cdb.h>
#include "cdbextra.h"

int cdb_dump(const char * name) {
	int numdump=0;
	struct cdb c;
	uint32 kpos;

	uint32 kp, klen, dp, dlen;
	unsigned char *key, *data;

	int fd = open_read(name);
	cdb_init(&c, fd);
	cdb_firstkey(&c, &kpos);

	do {

		kp = cdb_keypos(&c);
		klen = cdb_keylen(&c);
		dp = cdb_datapos(&c);
		dlen = cdb_datalen(&c);

		key = alloca(klen);
		data = alloca(dlen);
		cdb_read(&c, key, klen, kp);
		cdb_read(&c, data, dlen, dp);

		write(1, key, klen);
		write(1, "->", 2);
		write(1, data, dlen);
		write(1, "\n", 1);
		++numdump;
	} while (cdb_nextkey(&c, &kpos) == 1);
	close(fd);
	return numdump;
}
