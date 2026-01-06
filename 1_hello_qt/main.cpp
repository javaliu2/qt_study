#include "widget.h"
#include <QApplication>
#include <QFile>
#include <QString>
#include <QTextStream>

void myMessageHandler(QtMsgType type, const QMessageLogContext& context, const QString& msg) {
    static QFile file("log.txt");  // 1) 作用域在该函数内; 2) 生命周期和application一致
    // 另外，C++11起，函数内static的初始化是线程安全的 
    if (!file.isOpen()) {
        // open被声明为nodiscord，要求programmer主动检查返回值以避免因文件不存在或者磁盘空间不足造成后续的bug
        if (!file.open(QIODevice::Append | QIODevice::Text)) {
            return;
        }
    }
    QTextStream ts(&file);
    ts << msg << "\n";
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qInstallMessageHandler(myMessageHandler);
    Widget w;
    w.show();
    return a.exec();
}
