#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->horizontalSlider->setMaximum(10);
    QObject::connect(ui->horizontalSlider, &QSlider::valueChanged, [&](int valueBlur){
        blurImage(image, valueBlur);
        setImage(image, valueBlur);

    });
}
void MainWindow::setImage(QImage originalImage, int newValueBlur){
    ui->label->setPixmap(QPixmap::fromImage(blurImage(originalImage,newValueBlur)).scaled(
                             ui->label->width(),
                             ui->label->height(),
                             Qt::KeepAspectRatio));
}
QImage MainWindow::blurImage(QImage source, int blurRadius){
    if(source.isNull()) return QImage();
    QGraphicsScene scene;
    QGraphicsPixmapItem item;
    item.setPixmap(QPixmap::fromImage(source));
    auto *blur = new QGraphicsBlurEffect;
    blur->setBlurRadius(blurRadius);
    item.setGraphicsEffect(blur);
    scene.addItem(&item);
    QImage result(source.size(), QImage::Format_ARGB32);
    result.fill(Qt::transparent);
    QPainter painter(&result);
    scene.render(&painter, QRectF(), QRectF(0,0,source.width(),source.height()));
    return result;
}
void MainWindow::openFile(){
    filePath = QFileDialog::getOpenFileName(nullptr, "open image", "C:\\Users\\bagi3\\Pictures", "JPEG Files (*.jpg *.jpeg);;PNG Files (*.png)");
    image.load(filePath);
    setImage(image, 0);
    /*
    ui->label->setPixmap(QPixmap::fromImage(blurImage(image,0)).scaled(
                             ui->label->width(),
                             ui->label->height(),
                             Qt::KeepAspectRatio));
                             */
}
MainWindow::~MainWindow()
{
    delete ui;
}

