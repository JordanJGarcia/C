#include "../lib/result.h"

los_t
make_los_state(const bool error, const int rc, const char * msg, const char * file, const int line, const int value)
{
    los_t r;

    r.error = error;
    r.rc = rc;
    snprintf(r.msg, MSG_SIZE, "%s", msg);
    snprintf(r.file, MSG_SIZE, "%s", file);
    r.line = line;
    r.value = value;

    return r;
}

void
print_los(los_t r)
{
    //printf("{ rc: %d    file: %s    line: %d    msg: %s }\n", r.rc, r.file, r.line, r.msg);
    printf("%s%s:%d\t%s\n", r.error ? "ERROR - " : "", r.file, r.line, r.msg);

    return;
}
