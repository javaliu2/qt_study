#include "widget.h"
#include <QDebug>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent), teacher(new Teacher(this)), student(new Student(this)), subWidget(nullptr)
{
    // 因为发生信号重载和槽函数重载，所以需要使用函数指针来明确具体是哪一个函数
    void (Teacher::*sayShangKe_ptr)(void) = &Teacher::sayShangKe;  // 无参的信号
    void (Student::*sayQiLi_ptr)(void) = &Student::sayQiLi;  // 无参的槽函数
    connect(teacher, sayShangKe_ptr, student, sayQiLi_ptr);  // 信号连接槽函数
    dingLingLing();  // 通过emit关键字激活信号

    void (Teacher::*sayShangKe_ptr2)(QString) = &Teacher::sayShangKe;
    void (Student::*sayQiLi_ptr2)(QString) = &Student::sayQiLi;
    connect(teacher, sayShangKe_ptr2, student, sayQiLi_ptr2);

    QPushButton* btn = new QPushButton("上课", this);
    this->resize(600, 400);
    connect(btn, &QPushButton::clicked, teacher, [this](){
        if (teacher) {
            emit teacher->sayShangKe("刘老师");
        }
    });  // 信号连接信号
    //通过点击按钮，激活教师说上课信号

    QPushButton* btn2 = new QPushButton("open", this);
    btn2->move(200, 200);  // 左上角为(0, 0)
    bool is_open = true;
    connect(btn2, &QPushButton::clicked, this, [is_open, this, btn2]() mutable {
        if (is_open) {
            subWidget = new QWidget();
            subWidget->show();
            is_open = false;
            btn2->setText("close");
        } else {
            if (subWidget) {
                subWidget->close();
                delete subWidget;
                subWidget = nullptr;
            }
            is_open = true;
            btn2->setText("open");
        }
    });

}

void Widget::dingLingLing() {
    qDebug() << "叮铃铃";
    emit teacher->sayShangKe();
}
Widget::~Widget() {}
