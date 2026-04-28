#ifndef RESULT_H
#define RESULT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MSG_SIZE 256

#define ERROR true
#define NOERROR false

#define NO_RESULT -1
#define EMPTY -2
#define NOT_FOUND -3
#define OUT_OF_RANGE -4
#define MEMORY_ERROR -5

/* macros */
#define SET_RESULT(r, status, message) \
    do                                                                              \
    {                                                                               \
        r.rc = status;                                                              \
        GENMSG(r.msg, message);                                                     \
    }                                                                               \
    while(0)

#define GENMSG(buffer, msg) \
    do                                                                              \
    {                                                                               \
        snprintf(buffer, sizeof(buffer), "%s:%d - %s", __FILE__, __LINE__, msg);    \
    }                                                                               \
    while(0)

#define MAKE_LOS_STATE(error, rc, msg, value) \
    make_los_state(error, rc, msg, __FILE__, __LINE__, value)

struct list_operation_state_st {
    bool    error;
    int     rc;
    char    msg[MSG_SIZE + 1];
    char    file[MSG_SIZE + 1];
    int     line;
    int     value;
};

typedef struct list_operation_state_st los_t;

/* prototypes */
los_t    make_los_state(const bool error, const int rc, const char * msg, const char * file, const int line, const int value);
void     print_los(los_t r);
char*    translate_rc(const int rc);

#endif
