/*!
 *  \file main.cpp
 *  \version 0.1
 *  \date 2011-10-20
 *  \author João Neves
 *  \brief This is the application main file.
 */
#include <QtGui/QApplication>

/*!
 *  \brief This is the main function.
 *  \param argc - The argument count.
 *  \param argv - The argument vector.
 *  \returns The application exit code.
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("nvImageBrowser");
    a.setApplicationVersion("0.1");
    a.setOrganizationName("NvSoft");
    // a.setWindowIcon(QIcon(":/icons/resources/app.png"));

    return a.exec();
}
