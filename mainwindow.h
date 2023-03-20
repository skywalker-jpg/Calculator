#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "app_context.h"
#include "entrypoint.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    App_context main_struct;
    void on_digit_button_clicked();
    void on_sin_button_clicked();
    void on_cos_button_clicked();
    void on_tg_button_clicked();
    void on_ctg_button_clicked();
    void on_dot_button_clicked();
    void on_MC_button_clicked();
    void on_MPLUS_button_clicked();
    void on_MMINUS_button_clicked();
    void on_MR_button_clicked();
    void on_C_button_clicked();
    void on_PLUSMINUS_button_clicked();
    void on_summ_button_clicked();
    void on_substraction_button_clicked();
    void on_multiplication_button_clicked();
    void on_division_button_clicked();
    void on_equal_button_clicked();
    void on_sqr_button_clicked();
    void on_del_button_clicked();
    void on_MS_button_clicked();
    void update_label();
};
#endif // MAINWINDOW_H
