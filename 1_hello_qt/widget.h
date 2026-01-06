#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "student.h"
#include "teacher.h"
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void dingLingLing();
private:
    Teacher* teacher;
    Student* student;
    QWidget* subWidget;
};
#endif // WIDGET_H
