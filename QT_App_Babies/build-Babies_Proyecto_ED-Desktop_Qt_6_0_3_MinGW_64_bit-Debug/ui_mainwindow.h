/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *textPrincipal;
    QLabel *imagenPrincipal;
    QLabel *imagenPrincipal_2;
    QPushButton *desplegar;
    QLabel *label;
    QPushButton *listdir;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        textPrincipal = new QLabel(centralwidget);
        textPrincipal->setObjectName(QString::fromUtf8("textPrincipal"));
        textPrincipal->setGeometry(QRect(10, 20, 171, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Palatino Linotype"));
        font.setPointSize(15);
        textPrincipal->setFont(font);
        imagenPrincipal = new QLabel(centralwidget);
        imagenPrincipal->setObjectName(QString::fromUtf8("imagenPrincipal"));
        imagenPrincipal->setGeometry(QRect(150, 0, 61, 81));
        imagenPrincipal->setPixmap(QPixmap(QString::fromUtf8("../../../Rosado.png")));
        imagenPrincipal_2 = new QLabel(centralwidget);
        imagenPrincipal_2->setObjectName(QString::fromUtf8("imagenPrincipal_2"));
        imagenPrincipal_2->setGeometry(QRect(210, 0, 71, 81));
        imagenPrincipal_2->setPixmap(QPixmap(QString::fromUtf8("../../../Rosado.png")));
        desplegar = new QPushButton(centralwidget);
        desplegar->setObjectName(QString::fromUtf8("desplegar"));
        desplegar->setGeometry(QRect(60, 380, 91, 41));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(170, 385, 131, 31));
        listdir = new QPushButton(centralwidget);
        listdir->setObjectName(QString::fromUtf8("listdir"));
        listdir->setGeometry(QRect(70, 220, 131, 51));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        textPrincipal->setText(QCoreApplication::translate("MainWindow", "Babies Factory", nullptr));
        imagenPrincipal->setText(QString());
        imagenPrincipal_2->setText(QString());
        desplegar->setText(QCoreApplication::translate("MainWindow", "Desplegar", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Cantidad bebes: ", nullptr));
        listdir->setText(QCoreApplication::translate("MainWindow", "ListDir !!!!!!! hoho", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
