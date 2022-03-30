#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QLabel>
#include <QGraphicsBlurEffect>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QPainter>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    QImage blurImage(QImage source, int blurRadius);
    void setImage(QImage originalImage, int valueBlur);
    ~MainWindow();
public slots:
    void openFile();
private:
    QString filePath;
    QImage image;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
