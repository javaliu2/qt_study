#pragma once

#include <QMainWindow>
QT_BEGIN_NAMESPACE
class QAction;
class QActionGroup;
class QLabel;
class QMenu;
QT_END_NAMESPACE
// QMainWindow继承自QWidget
class MainWindow : public QMainWindow
{
    Q_OBJECT
protected:
#ifndef QT_NO_CONTEXTMENU
    void contextMenuEvent(QContextMenuEvent* event) override;  // 本类对继承自QMainWindow中的方法进行重写
#endif
private:
    void newFile();
    void open();
    void save();
    void print();
    void undo();
    void redo();
    void cut();
    void copy();
    void paste();
    void bold();
    void italic();
    void leftAlign();
    void rightAlign();
    void justify();
    void center();
    void setLineSpacing();
    void setParagraphSpacing();
    void about();
    void aboutQt();

private:
    void createActions();
    void createMenus();
    QMenu* fileMenu;
    QMenu* editMenu;
    QMenu* formatMenu;
    QMenu* helpMenu;
    QActionGroup* alignmentGroup;
    QAction* newAct;
    QAction* openAct;
    QAction* saveAct;
    QAction* printAct;
    QAction* exitAct;
    QAction* undoAct;
    QAction* redoAct;
    QAction* cutAct;
    QAction* copyAct;
    QAction* pasteAct;
    QAction* boldAct;
    QAction* italicAct;
    QAction* leftAlignAct;
    QAction* rightAlignAct;
    QAction* justifyAct;
    QAction* centerAct;
    QAction* setLineSpacingAct;
    QAction* setParagraphSpacingAct;
    QAction* aboutAct;
    QAction* aboutQtAct;
    QLabel* infoLabel;
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};
