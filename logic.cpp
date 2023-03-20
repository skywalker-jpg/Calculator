#include "logic.h"
#include "math.h"

void Init_function(App_context *main_struct){
    main_struct->Memory=0;
    main_struct->left_operand=0;
    main_struct->right_operand=0;
    main_struct->operators=process;
    main_struct->label_output[0]='\0';
    main_struct->number_in_process=1;
}

void remove_zeroes(App_context *main_struct) {
    int check_dot=0;
    int start=-1;
    int flag=0;
    for (size_t i=0;i<strlen(main_struct->label_output); i++){
        if (main_struct->label_output[i]=='.'){
            check_dot=1;
        }
        if (check_dot==1 and main_struct->label_output[i]!='0'){
            start=-1;
            flag=0;
        }
        if (check_dot==1 and main_struct->label_output[i]=='0' and flag!=1){
            start=i;
            flag=1;
        }
    }
    if(start!=-1){
        for (size_t i=start; i<strlen(main_struct->label_output);i++){
            main_struct->label_output[i]='\0';
            if(main_struct->label_output[i-1]=='.'){
                del_function(main_struct);
            }
        }
    }
    if(main_struct->label_output[strlen(main_struct->label_output)-1]=='.'){
        del_function(main_struct);
    }
}


void new_line(App_context* main_struct) {
    main_struct->label_output[0]='0';
    main_struct->label_output[1]='\0';
}


void summ_function(App_context *main_struct) {
    eq_function(main_struct,0);
    main_struct->number_in_process=1;
    main_struct->operators=plus;
}

void substraction_function(App_context *main_struct) {
    eq_function(main_struct,0);
    main_struct->number_in_process=1;
    main_struct->operators=minus;
}

void multiplication_function(App_context *main_struct) {
    eq_function(main_struct,0);
    main_struct->number_in_process=1;
    main_struct->operators=multiply;
}

void division_function(App_context *main_struct) {
    eq_function(main_struct,0);
    main_struct->number_in_process=1;
    main_struct->operators=divide;
}

void sin_function(App_context *main_struct){
    snprintf(main_struct->label_output, max_char, "%lf",sin(atof(main_struct->label_output)));
    main_struct->operators=equal;
    main_struct->left_operand=atof(main_struct->label_output);
    remove_zeroes(main_struct);
}

void cos_function(App_context *main_struct){
    snprintf(main_struct->label_output, max_char, "%lf",cos(atof(main_struct->label_output)));
    main_struct->operators=equal;
    main_struct->left_operand=atof(main_struct->label_output);
    remove_zeroes(main_struct);
}

void tg_function(App_context *main_struct){
    if(cos(atof(main_struct->label_output))!=0){
        snprintf(main_struct->label_output, max_char, "%lf",sin(atof(main_struct->label_output))/cos(atof(main_struct->label_output)));
        main_struct->operators=equal;
        main_struct->left_operand=atof(main_struct->label_output);
        remove_zeroes(main_struct);
    }
    else
        strcpy(main_struct->label_output, "Error");
}

void ctg_function(App_context *main_struct){
    if(sin(atof(main_struct->label_output))!=0){
        snprintf(main_struct->label_output, max_char, "%lf",cos(atof(main_struct->label_output))/sin(atof(main_struct->label_output)));
        main_struct->operators=equal;
        main_struct->left_operand=atof(main_struct->label_output);
        remove_zeroes(main_struct);
    }
    else
        strcpy(main_struct->label_output, "Error");
}

void sqr_function(App_context *main_struct){
     snprintf(main_struct->label_output, max_char, "%lf",atof(main_struct->label_output)*atof(main_struct->label_output));
     remove_zeroes(main_struct);
     main_struct->left_operand=atof(main_struct->label_output);
}

void dot_function(App_context *main_struct){
    if(strstr(main_struct->label_output,".")==NULL and strlen(main_struct->label_output)!=max_char-1 and main_struct->operators!=equal){
    main_struct->label_output[strlen(main_struct->label_output)+1]='\0';
    main_struct->label_output[strlen(main_struct->label_output)]='.';
    }
}

void MS_function(App_context *main_struct){
    main_struct->Memory=atof(main_struct->label_output);
}

void MC_function(App_context *main_struct){
    main_struct->Memory=0;
}

void M_plus_function(App_context *main_struct){
    main_struct->Memory+=atof(main_struct->label_output);
}

void M_minus_function(App_context *main_struct){
    main_struct->Memory-=atof(main_struct->label_output);
}

void MR_function(App_context *main_struct){
    snprintf(main_struct->label_output, max_char, "%.*g", max_char, main_struct->Memory);
}

void plus_minus_function(App_context *main_struct){
    int len = (int)strlen(main_struct->label_output);
    if (strcmp(main_struct->label_output, "") == 0 or main_struct->label_output[0]=='E')
        return;
    if (main_struct->label_output[0] == '-')
    {
        for(int i = 0; i < len - 1; i++)
        {
            main_struct->label_output[i] = main_struct->label_output[i + 1];
        }
        main_struct->label_output[len - 1] = '\0';
    }
    else
    {
        if(len>max_char-2)
            return;

        for(int i = len; i >= 0; i--)
        {
            main_struct->label_output[i + 1] = main_struct->label_output[i];
        }
        main_struct->label_output[0] = '-';
    }

    if(main_struct->operators==process)
        main_struct->left_operand=atof(main_struct->label_output);
    else
        main_struct->right_operand=atof(main_struct->label_output);
}

void del_function(App_context *main_struct){
    if(main_struct->label_output[0]!='\0'){
    main_struct->label_output[strlen(main_struct->label_output)-1]='\0';
    if (strcmp(main_struct->label_output,"\0")==0){
        main_struct->label_output[0]='0';
        main_struct->label_output[1]='\0';
    }
    }
    if(main_struct->operators==process)
        main_struct->left_operand=atof(main_struct->label_output);
    else
        main_struct->right_operand=atof(main_struct->label_output);
}

void C_function(App_context *main_struct){
    main_struct->label_output[0]='\0';
    main_struct->left_operand=0;
    main_struct->right_operand=0;
    main_struct->operators=equal;
}

void add_num_function(App_context *main_struct, char * num) {
    if(main_struct->number_in_process==1){
        new_line(main_struct);
        main_struct->number_in_process=0;
    }
    if(main_struct->operators==equal or main_struct->label_output[0]=='E'){
        C_function(main_struct);
        main_struct->operators=process;
    }
    if((main_struct->label_output[0]=='0' and  main_struct->label_output[1]=='\0') or (main_struct->label_output[0]=='-' and  main_struct->label_output[1]=='0')){
        main_struct->label_output[0]=*num;
        main_struct->label_output[1]='\0';
    }
    else if (strlen(main_struct->label_output)<max_char-1){
        main_struct->label_output[strlen(main_struct->label_output)+1]='\0';
        main_struct->label_output[strlen(main_struct->label_output)]=*num;
    }
    if(strlen(main_struct->label_output)<max_char){
        if(main_struct->operators==process)
            main_struct->left_operand=atof(main_struct->label_output);
        else
            main_struct->right_operand=atof(main_struct->label_output);
    }
}


void eq_function(App_context* main_struct, int check_clicked_button) {
    main_struct->right_operand=atof(main_struct->label_output);
    switch(main_struct->operators){
    case plus:
        snprintf(main_struct->label_output, max_char, "%lf", main_struct->left_operand+main_struct->right_operand);
        main_struct->left_operand+=main_struct->right_operand;
        break;
    case minus:
        snprintf(main_struct->label_output, max_char, "%lf", main_struct->left_operand-main_struct->right_operand);
        main_struct->left_operand-=main_struct->right_operand;
        break;
    case multiply:
        snprintf(main_struct->label_output, max_char, "%lf", main_struct->left_operand*main_struct->right_operand);
        main_struct->left_operand=main_struct->right_operand*main_struct->left_operand;
        break;
    case divide:
        if(main_struct->right_operand!=0){
            snprintf(main_struct->label_output, max_char, "%lf", main_struct->left_operand/main_struct->right_operand);
            main_struct->left_operand=main_struct->left_operand/main_struct->right_operand;
        }
        else{
            strcpy(main_struct->label_output, "Error");
            main_struct->left_operand=0;
            main_struct->right_operand=0;
        }
        break;
    case equal:
        main_struct->right_operand=0;
        main_struct->left_operand=atof(main_struct->label_output);
        break;
    }
    if (check_clicked_button==1){
        main_struct->operators=equal;
    }
    remove_zeroes(main_struct);
}

