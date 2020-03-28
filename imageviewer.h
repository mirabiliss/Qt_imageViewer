#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include <QMainWindow>
#include <QFileDialog>
#include <QScrollArea>
#include <QPrintDialog>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class imageViewer; }
QT_END_NAMESPACE

class imageViewer : public QMainWindow
{
    Q_OBJECT

public:
    imageViewer(QWidget *parent = nullptr);
    ~imageViewer();

private slots:
    void on_actionOpen_triggered();
    void on_actionPrint_triggered();
    void on_actionClose_triggered();
    void on_actionExit_triggered();

private:
    Ui::imageViewer *ui;
    bool isImageOpen = false;
};
#endif // IMAGEVIEWER_H
