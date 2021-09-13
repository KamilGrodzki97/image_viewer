#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QFileSystemModel>
#include <QFileIconProvider>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class myFileIconProvider:public QFileIconProvider {
public:
    QIcon icon(const QFileInfo &info) const{
        if(!QFileInfo(info.filePath()).isDir())
        {
            //if the file is image
            if( info.suffix().compare("jpg",Qt::CaseInsensitive)==0 ||
                    info.suffix().compare("bmp",Qt::CaseInsensitive)==0 ||
                    info.suffix().compare("png",Qt::CaseInsensitive)==0 ||
                    info.suffix().compare("jpeg",Qt::CaseInsensitive)==0 )
            {
                //creat a preview image to QIcon
                QIcon myIcon(info.filePath());
                return myIcon;
            }
        }
        //if the file is not image, return default icon
        return QFileIconProvider::icon(info);
    }
};
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_treeView_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;

    QFileSystemModel *dirmodel;
    QFileSystemModel *filemodel;


};
#endif // MAINWINDOW_H
