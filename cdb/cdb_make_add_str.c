#include <cdb.h>
#include "cdbextra.h"

int cdb_make_add_str(struct cdb_make * cdbm, const char * nkey,
		const char * nval) {
	size_t nklen = str_len((const char *)nkey);
	size_t nvlen = str_len((const char *)nval);
	cdb_make_add(cdbm, (const unsigned char*) nkey, nklen, (const unsigned char*)nval, nvlen);
	return 1;
}
