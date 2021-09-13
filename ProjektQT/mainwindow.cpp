#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString sPath = "C:/";

    dirmodel = new QFileSystemModel(this);
    dirmodel->setFilter(QDir::Files | QDir::AllDirs | QDir::NoDotAndDotDot);
    dirmodel->setRootPath(sPath);
    dirmodel->setNameFilters(QStringList()<< "*.png" << "*.jpg" << "*.tif" << "*.tiff" << "*.bmp"
                                           << "*.jpeg" << "*.gif" << "*.eps" << "*.raw" << "*.cr2"
                                           << "*.nef" << "*.orf" << "*.sr2");
    ui->treeView->setModel(dirmodel);

//    myFileIconProvider fileIconProvider;
//    filemodel = new QFileSystemModel(this);
//    filemodel->setFilter(QDir::NoDotAndDotDot | QDir::Files);

//    filemodel->setNameFilters(QStringList()<< "*.png" << "*.jpg" << "*.tif" << "*.tiff" << "*.bmp"
//                                           << "*.jpeg" << "*.gif" << "*.eps" << "*.raw" << "*.cr2"
//                                           << "*.nef" << "*.orf" << "*.sr2");
//    filemodel->setRootPath(sPath);
//    ui->listView->setViewMode(QListView::IconMode);
//    ui->listView->setModel(filemodel);


}



MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_treeView_clicked(const QModelIndex &index)
{
    QString sPath = dirmodel->fileInfo(index).absoluteFilePath();
    QImage image(sPath);
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label->setScaledContents( true );

    ui->label->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
}
