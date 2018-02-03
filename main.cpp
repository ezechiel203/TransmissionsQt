#include "transmain.h"
#include "transtabwidget.h"
#include <secteur.h>
#include <QApplication>
#include <QList>
#include <QLibraryInfo>
#include <QtCore/QTranslator>
#include <QMessageBox>
#include <QSharedMemory>
#include <QSplashScreen>
#include <QStyleFactory>
#include <Windows.h>
#include <splashscreendialog.h>
#include <QThread>
#include <QComboBox>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator translator;
    translator.load(QString("qt_fr"), QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    a.installTranslator(&translator);

    a.setStyleSheet("QComboBox QAbstractItemView {selection-background-color: #75CEFF; selection-color: #FDFDFD; background-color: #FDFDFD;}"
                    "QComboBox {border : 1px solid #E0E0E0;}"
                    "QComboBox:disabled {color: #AFAFAF; background-color: #FDFDFD;}"
                    "QComboBox::drop-down {border-top : 0px solid #E0E0E0;border-right : 0px solid #E0E0E0;border-bottom : 0px solid #E0E0E0;background-color : #FDFDFD;}"
                    "QComboBox::drop-down:hover {background-color : #B5E3FC;}"
                    "QComboBox::down-arrow { image : url(:/arrow);}"
                    "QTextEdit {border: 1px solid #E0E0E0; border-radius: 2px;}"
                    "QTextEdit:hover { border: 1px solid #75CEFF;} QTextEdit:selected { border: 1px solid #75CEFF;} QTextEdit:selected { border-color: #75CEFF;} QLineEdit:hover { border-color: #75CEFF;} QLineEdit:selected { border-color: #75CEFF;} QComboBox:hover { border-color: #75CEFF;} QComboBox:selected { border-color: #75CEFF;} QCheckBox:hover { border-color: #75CEFF;} QCheckBox:selected { border-color: #75CEFF;}"
                    "QLineEdit {border: 1px solid #E0E0E0; border-radius: 2px;}"
                    "QPushButton {background-color : #F5F5F5; border: 1px solid #E0E0E0 ; border-radius: 2 px;}"
                    "QToolButton {background-color : #F5F5F5; border: 1px solid #E0E0E0 ; border-radius: 2 px;}"
                    "QPushButton:hover {border-color : #75CEFF; background-color: #FFFFFF;}"
                    "QToolButton:hover {border-color : #75CEFF; background-color: #FFFFFF;}"
                    "QToolBar {border : 0px;}"
                    "QTabWidget::pane {border-top: 0px;}"
                    "QTabBar::tab {background: #DFDFDF;height: 40px;}"
                    "QTabBar::tab:!selected:hover {background-color: #75CEFF; }"
                    "QTabBar::tab:selected {background-color : #FDFDFD;color : #444444;}"
                    "QTabBar::tab:focus {background-color : #FDFDFD;color : #444444;}");

    QApplication::setStyle(QStyleFactory::create("Fusion"));
    QPalette p;
    p = a.palette();
    p.setColor(QPalette::Active, QPalette::Window, QColor(253,253,253));
    p.setColor(QPalette::Inactive, QPalette::Window, QColor(253,253,253));
    p.setColor(QPalette::Disabled, QPalette::Window, QColor(253,253,253));
    p.setColor(QPalette::Active, QPalette::Button, QColor(255,255,255));
    p.setColor(QPalette::Inactive, QPalette::Button, QColor(255,255,255));
    p.setColor(QPalette::Disabled, QPalette::Button, QColor(210,210,210));
    p.setColor(QPalette::Active, QPalette::Highlight, QColor("#75CEFF"));
    p.setColor(QPalette::Inactive, QPalette::Highlight, QColor(240,240,240));
    p.setColor(QPalette::Disabled, QPalette::Highlight, QColor("#75CEFF"));
    p.setColor(QPalette::Active, QPalette::ButtonText, QColor(65,65,65));
    p.setColor(QPalette::Inactive, QPalette::ButtonText, QColor(65,65,65));
    p.setColor(QPalette::Disabled, QPalette::ButtonText, QColor(120,120,120));
    p.setColor(QPalette::Active, QPalette::Midlight, QColor(240,240,240));
    p.setColor(QPalette::Inactive, QPalette::Midlight, QColor(240,240,240));
    p.setColor(QPalette::Disabled, QPalette::Midlight, QColor(253,253,253));
    p.setColor(QPalette::Active, QPalette::Dark, QColor(160,160,160));
    p.setColor(QPalette::Inactive, QPalette::Dark, QColor(160,160,160));
    p.setColor(QPalette::Disabled, QPalette::Dark, QColor(160,160,160));
    p.setColor(QPalette::Active, QPalette::Mid, QColor(160,160,160));
    p.setColor(QPalette::Inactive, QPalette::Mid, QColor(160,160,160));
    p.setColor(QPalette::Disabled, QPalette::Mid, QColor(160,160,160));
    p.setColor(QPalette::Active, QPalette::Shadow, QColor(105,105,105));
    p.setColor(QPalette::Inactive, QPalette::Shadow, QColor(105,105,105));
    p.setColor(QPalette::Disabled, QPalette::Shadow, QColor(65,65,65));
    p.setColor(QPalette::Active, QPalette::AlternateBase, QColor(252,252,252));
    p.setColor(QPalette::Inactive, QPalette::AlternateBase, QColor(252,252,252));
    p.setColor(QPalette::Disabled, QPalette::AlternateBase, QColor(252,252,252));
    p.setColor(QPalette::Active, QPalette::WindowText, QColor(65,65,65));
    p.setColor(QPalette::Inactive, QPalette::WindowText, QColor(65,65,65));
    p.setColor(QPalette::Disabled, QPalette::WindowText, QColor(120,120,120));
    p.setColor(QPalette::Active, QPalette::Light, QColor(255,255,255));
    p.setColor(QPalette::Inactive, QPalette::Light, QColor(255,255,255));
    p.setColor(QPalette::Disabled, QPalette::Light, QColor(255,255,255));
    p.setColor(QPalette::Active, QPalette::Text, QColor(65,65,65));
    p.setColor(QPalette::Inactive, QPalette::Text, QColor(65,65,65));
    p.setColor(QPalette::Disabled, QPalette::Text, QColor(120,120,120));
    p.setColor(QPalette::Active, QPalette::BrightText, QColor(255,255,255));
    p.setColor(QPalette::Inactive, QPalette::BrightText, QColor(255,255,255));
    p.setColor(QPalette::Disabled, QPalette::BrightText, QColor(255,255,255));
    p.setColor(QPalette::Active, QPalette::Base, QColor(255,255,255));
    p.setColor(QPalette::Inactive, QPalette::Base, QColor(255,255,255));
    p.setColor(QPalette::Disabled, QPalette::Base, QColor(253,253,253));
    p.setColor(QPalette::Active, QPalette::HighlightedText, QColor(255,255,255));
    p.setColor(QPalette::Inactive, QPalette::HighlightedText, QColor(65,65,65));
    p.setColor(QPalette::Disabled, QPalette::HighlightedText, QColor(255,255,255));
    p.setColor(QPalette::Active, QPalette::Link, QColor(0,0,255));
    p.setColor(QPalette::Active, QPalette::LinkVisited, QColor(255,0,255));
    a.setPalette(p);

    QSharedMemory memInstanceLock("S1Bdjkfgnzsef3ND");
    if ( !memInstanceLock.create(512, QSharedMemory::ReadWrite) )
    {
        HWND mainWindow = FindWindow(L"Qt5QWindowIcon", L"Transmissions IDE");
        if(mainWindow)
        {
            ShowWindowAsync(mainWindow, SW_RESTORE);
            SetForegroundWindow(mainWindow);
        }
        else
        {
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Information);
            msgBox.setText("Transmissions IDE est déjà en cours d'exécution.");
            msgBox.setWindowTitle("Transmissions IDE");
            msgBox.setWindowFlags(Qt::WindowStaysOnTopHint);
            msgBox.setWindowFlags(msgBox.windowFlags() & ~Qt::WindowMinMaxButtonsHint);
            msgBox.exec();

        }

        exit(0);
    }


    SplashScreenDialog* dlg = new SplashScreenDialog(0);
    QApplication::processEvents();
    QApplication::processEvents();
    dlg->start();
    QApplication::processEvents();
    Transmain* w = new Transmain();
    dlg->setSelector(w);
    //w.show();
    //splash.close();
    return a.exec();
}

