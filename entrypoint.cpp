#include "entrypoint.h"

void do_operation(Operations operation, App_context *main_struct, void* button_number){
    switch(operation){
    case init:
        Init_function(main_struct);
        break;
    case summ:
        summ_function(main_struct);
        break;
    case substraction:
        substraction_function(main_struct);
        break;
    case multiplication:
        multiplication_function(main_struct);
        break;
    case division:
        division_function(main_struct);
        break;
    case sqr:
        sqr_function(main_struct);
        break;
    case sin:
        sin_function(main_struct);
        break;
    case cos:
        cos_function(main_struct);
        break;
    case tg:
        tg_function(main_struct);
        break;
    case ctg:
        ctg_function(main_struct);
        break;
    case dot:
        dot_function(main_struct);
        break;
    case MC:
        MC_function(main_struct);
        break;
    case M_plus:
        M_plus_function(main_struct);
        break;
    case M_minus:
        M_minus_function(main_struct);
        break;
    case MR:
        MR_function(main_struct);
        break;
    case plus_minus:
        plus_minus_function(main_struct);
        break;
    case del:
        del_function(main_struct);
        break;
    case C:
        C_function(main_struct);
        break;
    case eq:
        eq_function(main_struct, 1);
        break;
    case MS:
        MS_function(main_struct);
        break;
    case add_num:
        add_num_function(main_struct, (char*) button_number);
        break;
    }
}
