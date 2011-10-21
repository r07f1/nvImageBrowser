/*!
 *  \file appsettings.cpp
 *  \version 0.1
 *  \date 2011-10-21
 *  \author João Neves
 *  \brief This is the App Settings class definition.
 */
#include <QFile>
#include <QDir>
#include <QColor>
#include "appsettings.h"

/*!
 *  \brief This is the App Settings constructor.
 *  \parent parent - The object parent.
 */
AppSettings::AppSettings(QObject *parent)
    : QSettings(parent)
{
    if(!isWritable()){
        emit error("critical","Settings I/O error!");
    }
    else{
        if(QFile::exists(this->fileName())){
            if(!validateSettings()){
                writeDefaultSettings();
            }
        }
        else{
            writeDefaultSettings();
        }
    }
}

/*!
 *  \brief This is the App Settings destructor.
 */
AppSettings::~AppSettings()
{
}

/*!
 *  \brief Function to read a setting value.
 *  \param grp - The setting group.
 *  \param key - The setting key.
 *  \returns The desired setting value.
 */
QVariant AppSettings::readSetting(const QString &grp, const QString &key)
{
    this->beginGroup(grp);
    return this->value(key);
    this->endGroup();
}

/*!
 *  \brief Function to write a setting value.
 *  \param grp - The setting group.
 *  \param key - The setting key.
 *  \param val - The setting value.
 */
void AppSettings::writeSetting(const QString &grp, const QString &key, const QString &val)
{
    this->beginGroup(grp);
    this->setValue(key,value);
    this->endGroup();
}

/*!
 *  \brief Function to reset the settings to default values.
 */
void AppSettings::reset()
{
    this->writeDefaultSettings();
}

/*!
 *  \brief Function to validate the settings.
 *  \returns true if all settings are valid.
 */
bool AppSettings::validateSettings()
{
    // General group
    this->beginGroup("general");
    if(!this->contains("StartMode"))
        return false;
    if(!this->contains("DefaultPath"))
        return false;
    if(!this->contains("FileTypes"))
        return false;
    this->endGroup();

    // Slideshow group
    this->beginGroup("slideshow");
    if(!this->contains("MainToolBarVisible"))
        return false;
    if(!this->contains("FullScreen"))
        return false;
    if(!this->contains("BackgroundColor"))
        return false;
    if(!this->contains("Timer"))
        return false;
    if(!this->contains("Order"))
        return false;
    this->endGroup();

    return true;
}

/*!
 *  \brief Function to write the default settings.
 */
void AppSettings::writeDefaultSettings()
{
    if(QFile::exists(this->fileName())){
        QFile::remove(this->fileName());
    }

    if(!isWritable()){
        emit error("critical","Settings I/O error!");
    }

    // General group:
    QStringList fileTypes;
    fileTypes << "*.jpg" << "*.png" << "*.bmp" << "*.xpm" << "*.gif";

    foreach(QString s,fileTypes){
        fileTypes << s.toUpper();
    }

    this->beginGroup("general");
    this->setValue("StartMode","Slideshow");
    this->setValue("DefaultPath",QDir::homePath());
    this->setValue("FileTypes",fileTypes);
    this->endGroup();

    // Slideshow group:
    this->beginGroup("slideshow");
    this->setValue("MainToolBarVisible",true);
    this->setValue("FullScreen",true);
    this->setValue("BackgroundColor",QColor(Qt::black).toRgb());
    this->setValue("Timer",3000);
    this->setValue("Order","normal");
    this->endGroup();

    // Read the settings
    this->validateSettings();
}
