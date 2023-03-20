#ifndef APP_CONTEXT_H
#define APP_CONTEXT_H

#define max_char 10

enum Operators{
    plus,
    minus,
    multiply,
    divide,
    equal,
    process
};

struct App_context{
    char label_output[max_char];
    Operators operators;
    double left_operand;
    double right_operand;
    double Memory;
    int number_in_process;
};

#endif // APP_CONTEXT_H
