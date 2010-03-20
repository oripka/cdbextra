#include "cdbextra.h"
#include <unistd.h>

int cdb_make_finish_close(struct cdb_make * cdbm) {
	cdb_make_finish(cdbm);
	close(cdbm->fd);
	return 0;
}
