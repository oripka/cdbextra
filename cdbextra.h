#ifndef _CDB_EXTRA_H
#define _CDB_EXTRA_H
#include <cdb_make.h>
int cdb_remake(const char * name, const char * newname, struct cdb_make * cdbm);
int cdb_make_finish_close(struct cdb_make * cdbm);
int cdb_make_add_str(struct cdb_make * cdbm, const char * nkey, const char * nval);
int cdb_dump(const char * name);
#endif
