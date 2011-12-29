/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu Dec 29 14:26:02 2011
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *btnHear;
    QLabel *labLetters;
    QLineEdit *leInput;
    QPushButton *btnLetters;
    QPushButton *btnExit;
    QPushButton *btnHelp;
    QPushButton *btnWordFile;
    QLabel *labUser;
    QPushButton *btnNext;
    QFrame *frame;
    QLabel *labWordsHeader;
    QLabel *labWordCount;
    QLabel *labCorrectHeader;
    QLabel *labCorrect;
    QLabel *labInfo;
    QPushButton *btnScrWordFile;
    QLabel *labHooray;
    QLabel *labComment;
    QLabel *labUserName;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1000, 760);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(255, 243, 213, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        MainWindow->setPalette(palette);
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        MainWindow->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8("icons/spellListen-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        btnHear = new QPushButton(centralWidget);
        btnHear->setObjectName(QString::fromUtf8("btnHear"));
        btnHear->setGeometry(QRect(30, 380, 100, 100));
        btnHear->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("icons/player-volume-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnHear->setIcon(icon1);
        btnHear->setIconSize(QSize(60, 60));
        btnHear->setCheckable(false);
        btnHear->setFlat(true);
        labLetters = new QLabel(centralWidget);
        labLetters->setObjectName(QString::fromUtf8("labLetters"));
        labLetters->setGeometry(QRect(20, 490, 961, 71));
        QPalette palette1;
        QBrush brush2(QColor(255, 255, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush);
        labLetters->setPalette(palette1);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Georgia"));
        font1.setPointSize(36);
        font1.setBold(true);
        font1.setWeight(75);
        labLetters->setFont(font1);
        labLetters->setFrameShape(QFrame::NoFrame);
        labLetters->setFrameShadow(QFrame::Plain);
        labLetters->setAlignment(Qt::AlignCenter);
        leInput = new QLineEdit(centralWidget);
        leInput->setObjectName(QString::fromUtf8("leInput"));
        leInput->setGeometry(QRect(20, 570, 961, 91));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Georgia"));
        font2.setPointSize(36);
        leInput->setFont(font2);
        leInput->setAlignment(Qt::AlignCenter);
        btnLetters = new QPushButton(centralWidget);
        btnLetters->setObjectName(QString::fromUtf8("btnLetters"));
        btnLetters->setGeometry(QRect(210, 380, 100, 100));
        btnLetters->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("icons/text-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnLetters->setIcon(icon2);
        btnLetters->setIconSize(QSize(60, 60));
        btnLetters->setCheckable(false);
        btnLetters->setFlat(true);
        btnExit = new QPushButton(centralWidget);
        btnExit->setObjectName(QString::fromUtf8("btnExit"));
        btnExit->setGeometry(QRect(630, 400, 60, 60));
        btnExit->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("icons/remove-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnExit->setIcon(icon3);
        btnExit->setIconSize(QSize(30, 30));
        btnExit->setCheckable(false);
        btnExit->setFlat(true);
        btnHelp = new QPushButton(centralWidget);
        btnHelp->setObjectName(QString::fromUtf8("btnHelp"));
        btnHelp->setGeometry(QRect(630, 300, 60, 60));
        btnHelp->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("icons/help-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnHelp->setIcon(icon4);
        btnHelp->setIconSize(QSize(30, 30));
        btnHelp->setCheckable(false);
        btnHelp->setFlat(true);
        btnWordFile = new QPushButton(centralWidget);
        btnWordFile->setObjectName(QString::fromUtf8("btnWordFile"));
        btnWordFile->setGeometry(QRect(30, 270, 100, 100));
        btnWordFile->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("icons/wordfile.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnWordFile->setIcon(icon5);
        btnWordFile->setIconSize(QSize(60, 60));
        btnWordFile->setCheckable(false);
        btnWordFile->setFlat(true);
        labUser = new QLabel(centralWidget);
        labUser->setObjectName(QString::fromUtf8("labUser"));
        labUser->setGeometry(QRect(40, 80, 451, 51));
        QPalette palette2;
        QBrush brush3(QColor(85, 0, 127, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        QBrush brush4(QColor(0, 0, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush4);
        QBrush brush5(QColor(76, 76, 76, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush5);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush5);
        QBrush brush6(QColor(159, 158, 158, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        labUser->setPalette(palette2);
        QFont font3;
        font3.setFamily(QString::fromUtf8("Ubuntu"));
        font3.setPointSize(20);
        font3.setBold(true);
        font3.setItalic(true);
        font3.setWeight(75);
        labUser->setFont(font3);
        btnNext = new QPushButton(centralWidget);
        btnNext->setObjectName(QString::fromUtf8("btnNext"));
        btnNext->setGeometry(QRect(390, 380, 100, 100));
        btnNext->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("icons/next-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnNext->setIcon(icon6);
        btnNext->setIconSize(QSize(60, 60));
        btnNext->setCheckable(false);
        btnNext->setFlat(true);
        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setEnabled(true);
        frame->setGeometry(QRect(730, 10, 251, 471));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Georgia"));
        font4.setPointSize(14);
        frame->setFont(font4);
        frame->setFrameShape(QFrame::Panel);
        frame->setFrameShadow(QFrame::Raised);
        frame->setLineWidth(2);
        labWordsHeader = new QLabel(frame);
        labWordsHeader->setObjectName(QString::fromUtf8("labWordsHeader"));
        labWordsHeader->setGeometry(QRect(20, 20, 211, 51));
        labWordsHeader->setWordWrap(true);
        labWordCount = new QLabel(frame);
        labWordCount->setObjectName(QString::fromUtf8("labWordCount"));
        labWordCount->setGeometry(QRect(20, 80, 161, 21));
        labCorrectHeader = new QLabel(frame);
        labCorrectHeader->setObjectName(QString::fromUtf8("labCorrectHeader"));
        labCorrectHeader->setGeometry(QRect(20, 110, 211, 61));
        labCorrectHeader->setWordWrap(true);
        labCorrect = new QLabel(frame);
        labCorrect->setObjectName(QString::fromUtf8("labCorrect"));
        labCorrect->setGeometry(QRect(20, 180, 171, 21));
        labInfo = new QLabel(frame);
        labInfo->setObjectName(QString::fromUtf8("labInfo"));
        labInfo->setGeometry(QRect(20, 210, 211, 241));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        labInfo->setPalette(palette3);
        labInfo->setFrameShape(QFrame::Panel);
        labInfo->setFrameShadow(QFrame::Raised);
        labInfo->setLineWidth(2);
        labInfo->setScaledContents(false);
        labInfo->setAlignment(Qt::AlignCenter);
        labInfo->setWordWrap(true);
        btnScrWordFile = new QPushButton(centralWidget);
        btnScrWordFile->setObjectName(QString::fromUtf8("btnScrWordFile"));
        btnScrWordFile->setGeometry(QRect(210, 270, 100, 100));
        btnScrWordFile->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8("icons/wordfileScrambled.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnScrWordFile->setIcon(icon7);
        btnScrWordFile->setIconSize(QSize(60, 60));
        btnScrWordFile->setCheckable(false);
        btnScrWordFile->setFlat(true);
        labHooray = new QLabel(centralWidget);
        labHooray->setObjectName(QString::fromUtf8("labHooray"));
        labHooray->setGeometry(QRect(500, 30, 201, 201));
        labHooray->setPixmap(QPixmap(QString::fromUtf8("icons/tux.png")));
        labHooray->setScaledContents(true);
        labComment = new QLabel(centralWidget);
        labComment->setObjectName(QString::fromUtf8("labComment"));
        labComment->setGeometry(QRect(20, 670, 961, 20));
        labComment->setAlignment(Qt::AlignCenter);
        labUserName = new QLabel(centralWidget);
        labUserName->setObjectName(QString::fromUtf8("labUserName"));
        labUserName->setGeometry(QRect(40, 150, 451, 51));
        QPalette palette4;
        QBrush brush7(QColor(255, 85, 0, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush7);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush4);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush5);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush7);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush4);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush5);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        labUserName->setPalette(palette4);
        labUserName->setFont(font3);
        labUserName->setFrameShape(QFrame::NoFrame);
        labUserName->setFrameShadow(QFrame::Plain);
        labUserName->setLineWidth(0);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1000, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "SpellListen  -  Listen and learn to spell...", 0, QApplication::UnicodeUTF8));
        btnHear->setText(QApplication::translate("MainWindow", "F4", 0, QApplication::UnicodeUTF8));
        btnHear->setShortcut(QApplication::translate("MainWindow", "F4", 0, QApplication::UnicodeUTF8));
        labLetters->setText(QString());
        leInput->setText(QString());
        btnLetters->setText(QApplication::translate("MainWindow", "F5", 0, QApplication::UnicodeUTF8));
        btnLetters->setShortcut(QApplication::translate("MainWindow", "F5", 0, QApplication::UnicodeUTF8));
        btnExit->setText(QApplication::translate("MainWindow", "F10", 0, QApplication::UnicodeUTF8));
        btnExit->setShortcut(QApplication::translate("MainWindow", "F10", 0, QApplication::UnicodeUTF8));
        btnHelp->setText(QApplication::translate("MainWindow", "F1", 0, QApplication::UnicodeUTF8));
        btnHelp->setShortcut(QApplication::translate("MainWindow", "F1", 0, QApplication::UnicodeUTF8));
        btnWordFile->setText(QApplication::translate("MainWindow", "F2", 0, QApplication::UnicodeUTF8));
        btnWordFile->setShortcut(QApplication::translate("MainWindow", "F2", 0, QApplication::UnicodeUTF8));
        labUser->setText(QApplication::translate("MainWindow", "Name :", 0, QApplication::UnicodeUTF8));
        btnNext->setText(QApplication::translate("MainWindow", "F8", 0, QApplication::UnicodeUTF8));
        btnNext->setShortcut(QApplication::translate("MainWindow", "F8", 0, QApplication::UnicodeUTF8));
        labWordsHeader->setText(QApplication::translate("MainWindow", "Word number..:", 0, QApplication::UnicodeUTF8));
        labWordCount->setText(QString());
        labCorrectHeader->setText(QApplication::translate("MainWindow", "Spelled correct by user:", 0, QApplication::UnicodeUTF8));
        labCorrect->setText(QString());
        labInfo->setText(QString());
        btnScrWordFile->setText(QApplication::translate("MainWindow", "F3", 0, QApplication::UnicodeUTF8));
        btnScrWordFile->setShortcut(QApplication::translate("MainWindow", "F3", 0, QApplication::UnicodeUTF8));
        labHooray->setText(QString());
        labComment->setText(QString());
        labUserName->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
