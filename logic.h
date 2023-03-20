#ifndef LOGIC_H
#define LOGIC_H
#include "app_context.h"
#include "string.h"
#include "malloc.h"
#include "stdlib.h"
#include <stdio.h>
#include <string>
#include <iostream>

void Init_function(App_context *main_struct);
void remove_zeroes(App_context *main_struct);
void summ_function(App_context *main_struct);
void substraction_function(App_context *main_struct);
void multiplication_function(App_context *main_struct);
void division_function(App_context *main_struct);
void sin_function(App_context *main_struct);
void cos_function(App_context *main_struct);
void tg_function(App_context *main_struct);
void ctg_function(App_context *main_struct);
void dot_function(App_context *main_struct);
void MC_function(App_context *main_struct);
void M_plus_function(App_context *main_struct);
void M_minus_function(App_context *main_struct);
void MR_function(App_context *main_struct);
void plus_minus_function(App_context *main_struct);
void del_function(App_context *main_struct);
void C_function(App_context *main_struct);
void eq_function(App_context *main_struct,int flag);
void add_num_function(App_context *main_struct, char* name_but);
void sqr_function(App_context *main_struct);
void MS_function(App_context *main_struct);
#endif // LOGIC_H
