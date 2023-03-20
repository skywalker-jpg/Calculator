#ifndef ENTRYPOINT_H
#define ENTRYPOINT_H
#include "app_context.h"
#include "logic.h"
enum Operations{
    sin,
    cos,
    tg,
    ctg,
    dot,
    MC,
    M_plus,
    M_minus,
    MR,
    plus_minus,
    del,
    C,
    eq,
    add_num,
    summ,
    substraction,
    multiplication,
    division,
    sqr,
    init,
    MS
};

void do_operation(Operations operation, App_context *main_struct, void* button_number);
#endif // ENTRYPOINT_H
