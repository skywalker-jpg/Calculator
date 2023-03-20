#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->Button_zero, &QPushButton::clicked, this, &MainWindow::on_digit_button_clicked);
    connect(ui->Button_One, &QPushButton::clicked, this, &MainWindow::on_digit_button_clicked);
    connect(ui->Button_two, &QPushButton::clicked, this, &MainWindow::on_digit_button_clicked);
    connect(ui->Button_three, &QPushButton::clicked, this, &MainWindow::on_digit_button_clicked);
    connect(ui->Button_four, &QPushButton::clicked, this, &MainWindow::on_digit_button_clicked);
    connect(ui->Button_five, &QPushButton::clicked, this, &MainWindow::on_digit_button_clicked);
    connect(ui->Button_six, &QPushButton::clicked, this, &MainWindow::on_digit_button_clicked);
    connect(ui->Button_seven, &QPushButton::clicked, this, &MainWindow::on_digit_button_clicked);
    connect(ui->Button_eight, &QPushButton::clicked, this, &MainWindow::on_digit_button_clicked);
    connect(ui->Button_nine, &QPushButton::clicked, this, &MainWindow::on_digit_button_clicked);
    connect(ui->Button_sin, &QPushButton::clicked, this, &MainWindow::on_sin_button_clicked);
    connect(ui->Button_cos, &QPushButton::clicked, this, &MainWindow::on_cos_button_clicked);
    connect(ui->Button_tg, &QPushButton::clicked, this, &MainWindow::on_tg_button_clicked);
    connect(ui->Button_ctg, &QPushButton::clicked, this, &MainWindow::on_ctg_button_clicked);
    connect(ui->Button_dot, &QPushButton::clicked, this, &MainWindow::on_dot_button_clicked);
    connect(ui->Button_MC, &QPushButton::clicked, this, &MainWindow::on_MC_button_clicked);
    connect(ui->Button_MPLUS, &QPushButton::clicked, this, &MainWindow::on_MPLUS_button_clicked);
    connect(ui->Button_MMINUS, &QPushButton::clicked, this, &MainWindow::on_MMINUS_button_clicked);
    connect(ui->Button_MR, &QPushButton::clicked, this, &MainWindow::on_MR_button_clicked);
    connect(ui->Button_MS, &QPushButton::clicked, this, &MainWindow::on_MS_button_clicked);
    connect(ui->Button_C, &QPushButton::clicked, this, &MainWindow::on_C_button_clicked);
    connect(ui->Button_plusminus, &QPushButton::clicked, this, &MainWindow::on_PLUSMINUS_button_clicked);
    connect(ui->Button_plus, &QPushButton::clicked, this, &MainWindow::on_summ_button_clicked);
    connect(ui->Button_minus, &QPushButton::clicked, this, &MainWindow::on_substraction_button_clicked);
    connect(ui->Button_mult, &QPushButton::clicked, this, &MainWindow::on_multiplication_button_clicked);
    connect(ui->Button_div, &QPushButton::clicked, this, &MainWindow::on_division_button_clicked);
    connect(ui->Button_eq, &QPushButton::clicked, this, &MainWindow::on_equal_button_clicked);
    connect(ui->Button_sqr, &QPushButton::clicked, this, &MainWindow::on_sqr_button_clicked);
    connect(ui->Button_del, &QPushButton::clicked, this, &MainWindow::on_del_button_clicked);
    do_operation(init,&main_struct,NULL);
    update_label();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_digit_button_clicked(){
    QPushButton* button=(QPushButton*)sender();
    std::string std_text=button->text().toStdString();
    const char* char_text=std_text.c_str();
    char num=*char_text;
    do_operation(add_num,&main_struct,&num);
    update_label();
}
void MainWindow::on_sin_button_clicked(){
    do_operation(sin, &main_struct, NULL);
    update_label();
}
void MainWindow::on_cos_button_clicked(){
    do_operation(cos, &main_struct, NULL);
    update_label();
}
void MainWindow::on_tg_button_clicked(){
    do_operation(tg, &main_struct, NULL);
    update_label();
}
void MainWindow::on_ctg_button_clicked(){
    do_operation(ctg, &main_struct, NULL);
    update_label();
}
void MainWindow::on_dot_button_clicked(){
    do_operation(dot, &main_struct, NULL);
    update_label();
}
void MainWindow::on_MS_button_clicked(){
    do_operation(MS, &main_struct, NULL);
    update_label();
}
void MainWindow::on_MC_button_clicked(){
    do_operation(MC, &main_struct, NULL);
    update_label();
}
void MainWindow::on_MPLUS_button_clicked(){
    do_operation(M_plus, &main_struct, NULL);
    update_label();
}
void MainWindow::on_MMINUS_button_clicked(){
    do_operation(M_minus, &main_struct, NULL);
    update_label();
}
void MainWindow::on_MR_button_clicked(){
    do_operation(MR, &main_struct, NULL);
    update_label();
}
void MainWindow::on_C_button_clicked(){
    do_operation(C, &main_struct, NULL);
    update_label();
}
void MainWindow::on_PLUSMINUS_button_clicked(){
    do_operation(plus_minus, &main_struct, NULL);
    update_label();
}
void MainWindow::on_summ_button_clicked(){
    do_operation(summ, &main_struct, NULL);
    update_label();
}
void MainWindow::on_substraction_button_clicked(){
    do_operation(substraction, &main_struct, NULL);
    update_label();
}
void MainWindow::on_multiplication_button_clicked(){
    do_operation(multiplication, &main_struct, NULL);
    update_label();
}
void MainWindow::on_division_button_clicked(){
    do_operation(division, &main_struct, NULL);
    update_label();
}
void MainWindow::on_equal_button_clicked(){
    do_operation(eq, &main_struct, NULL);
    update_label();
}
void MainWindow::on_sqr_button_clicked(){
    do_operation(sqr, &main_struct, NULL);
    update_label();
}
void MainWindow::on_del_button_clicked(){
    do_operation(del, &main_struct, NULL);
    update_label();
}
void MainWindow::update_label(){
    ui->label->setText(main_struct.label_output);
}
