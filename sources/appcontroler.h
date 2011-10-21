/*!
 *  \file appcontroler.h
 *  \version 0.1
 *  \date 2011-10-21
 *  \author João Neves
 *  \brief This is the App Controler class declaration.
 */
#ifndef APPCONTROLER_H
#define APPCONTROLER_H

#include <QObject>
#include "appsettings.h"

/*!
 *  \class
 *  \brief
 */
class AppControler : public QObject
{
    Q_OBJECT

public:
    explicit AppControler(QObject *parent = 0);
    ~AppControler();
    void startApp(const QStringList &args);

public slots:
    void changeMode(const QString &mode,const QString &path);
    void showErrorMessage(const QString &type, const QString &msg);

private:
    AppSettings *settings;
    QString startPath;
    void loadSettings();
    void startDefaultMode();
    void browserMode(const QString &path);
    void slideshowMode(const QString &path);
    void viewerMode(const QString &path);
};

#endif // APPCONTROLER_H
