#include "student.h"
#include <QDebug>
Student::Student(QObject *parent)
    : QObject{parent}
{}


void Student::sayQiLi() {
    qDebug() << "起立";
}
void Student::sayQiLi(QString teacherName) {
    qDebug() << "起立，" << teacherName << "好";
}

