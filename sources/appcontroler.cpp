#include <QApplication>
#include <QMessageBox>
#include "appcontroler.h"

AppControler::AppControler(QObject *parent)
    : QObject(parent)
{
    this->loadSettings();
}

AppControler::~AppControler()
{
    delete settings;
}

void AppControler::startApp(const QStringList &args)
{
    switch(args.count()){

    case 0:
        this->startDefaultMode();
        break;

    case 1:
        if(args.at(0)=="-b"){
            this->browserMode(startPath);
        }
        if(args.at(0)=="-s"){
            this->slideshowMode(startPath);
        }
        if(args.at(0)=="-v"){
            this->viewerMode(startPath);
        }
        else{
            this->showErrorMessage("warning","Error parsing arguments!");
            this->startDefaultMode();
        }
        break;

    case 2:
        QString path = args.at(1);
        if(args.at(0)=="-b"){
            this->browserMode(path);
        }
        if(args.at(0)=="-s"){
            this->slideshowMode(path);
        }
        if(args.at(0)=="-v"){
            this->viewerMode(path);
        }
        else{
            this->showErrorMessage("warning","Error parsing arguments!");
            this->startDefaultMode();
        }
        break;

    default:
        this->showErrorMessage("warning","Error parsing arguments!");
        this->startDefaultMode();
    }
}

void AppControler::changeMode(const QString &mode, const QString &path)
{
}

void AppControler::showErrorMessage(const QString &type, const QString &msg)
{
    QMessageBox::Icon icon;
    QMessageBox msgBox;

    if(type=="critical"){
        icon = QMessageBox::Critical;
    }
    else{
        icon = QMessageBox::Warning;
    }

    msgBox.setWindowTitle("Error");
    msgBox.setIcon(icon);
    msgBox.setText(msg);
    msgBox.addButton(QMessageBox::Ok);

    msgBox.exec();
    if(type=="critical"){
        QApplication::exit(1);
    }
}

void AppControler::loadSettings()
{
    settings = new AppSettings(this);
    startPath = settings->readSetting("general","DefaultPath").toString();
}

void AppControler::startDefaultMode()
{
}

void AppControler::browserMode(const QString &path)
{
}

void AppControler::slideshowMode(const QString &path)
{
}

void AppControler::viewerMode(const QString &path)
{
}
