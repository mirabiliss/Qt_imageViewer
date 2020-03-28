#include "imageviewer.h"
#include "ui_imageviewer.h"

imageViewer::imageViewer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::imageViewer)
{
    ui->setupUi(this);
}

imageViewer::~imageViewer()
{
    delete ui;
}


void imageViewer::on_actionOpen_triggered()
{
    QFileDialog* dialog = new QFileDialog(this);
    QString filename = dialog->getOpenFileName();
    QImage image(filename);

    if(image.load(filename)){
        image = image.scaledToWidth(ui->label->width(), Qt::SmoothTransformation);
        ui->label->setPixmap(QPixmap::fromImage(image));
        ui->scrollArea->setWidget(ui->label);
        isImageOpen = true;
    }
    else{
        ui->label->setText("error opening file.");
    }
}

void imageViewer::on_actionPrint_triggered()
{
    if(isImageOpen){
        QPrintDialog* dialog = new QPrintDialog(this);
        dialog->exec();
    }
}

void imageViewer::on_actionClose_triggered()
{
    if(isImageOpen){
        QMessageBox* box = new QMessageBox(this);
        box->setWindowTitle("Exit");
        box->setText("Are you sure you want to close current picture?");
        box->setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
        box->setDefaultButton(QMessageBox::Yes);

        auto res = box->exec();
        if (res == QMessageBox::Yes){
            ui->label->clear();
            isImageOpen = false;
        }
    }
}

void imageViewer::on_actionExit_triggered()
{
    QMessageBox* box = new QMessageBox(this);
    box->setWindowTitle("Exit");
    box->setText("Are you sure you want to leave?");
    box->setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
    box->setDefaultButton(QMessageBox::Yes);

    auto res = box->exec();
    if (res == QMessageBox::Yes){
        QApplication::quit();
    }
}
