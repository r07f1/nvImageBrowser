#ifndef APPSETTINGS_H
#define APPSETTINGS_H

#include <QSettings>

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
