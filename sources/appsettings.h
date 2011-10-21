/*!
 *  \file appsettings.h
 *  \version 0.1
 *  \date 2011-10-21
 *  \author João Neves
 *  \brief This is the App Settings class declaration.
 */
#ifndef APPSETTINGS_H
#define APPSETTINGS_H

#include <QSettings>

/*!
 *  \class AppSettings
 *  \brief This class encapsulates the settings access.
 */
class AppSettings : public QSettings
{
    Q_OBJECT

public:
    explicit AppSettings(QObject *parent = 0);
    ~AppSettings();
    QVariant readSetting(const QString &grp, const QString &key);
    void writeSetting(const QString &grp, const QString &key, const QString &val);
    void reset();

signals:
    void error(const QString &type, const QString &msg);

private:
    bool validateSettings();
    void writeDefaultSettings();
};

#endif // APPSETTINGS_H
