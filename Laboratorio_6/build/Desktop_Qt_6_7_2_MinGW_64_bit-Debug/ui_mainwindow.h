/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *entradaPosicionX;
    QLineEdit *entradaPosicionY;
    QLineEdit *entradaVelocidadX;
    QLineEdit *entradaVelocidadY;
    QLineEdit *entradaMasa;
    QVBoxLayout *verticalLayout;
    QGraphicsView *vistaSimulacion;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *botonCargarMasa;
    QPushButton *botonSimular;
    QPushButton *Detener;
    QListWidget *listaCuerpos;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1300, 660);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        entradaPosicionX = new QLineEdit(centralwidget);
        entradaPosicionX->setObjectName("entradaPosicionX");

        horizontalLayout->addWidget(entradaPosicionX);

        entradaPosicionY = new QLineEdit(centralwidget);
        entradaPosicionY->setObjectName("entradaPosicionY");

        horizontalLayout->addWidget(entradaPosicionY);

        entradaVelocidadX = new QLineEdit(centralwidget);
        entradaVelocidadX->setObjectName("entradaVelocidadX");

        horizontalLayout->addWidget(entradaVelocidadX);

        entradaVelocidadY = new QLineEdit(centralwidget);
        entradaVelocidadY->setObjectName("entradaVelocidadY");

        horizontalLayout->addWidget(entradaVelocidadY);

        entradaMasa = new QLineEdit(centralwidget);
        entradaMasa->setObjectName("entradaMasa");

        horizontalLayout->addWidget(entradaMasa);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");

        gridLayout->addLayout(verticalLayout, 1, 2, 1, 1);

        vistaSimulacion = new QGraphicsView(centralwidget);
        vistaSimulacion->setObjectName("vistaSimulacion");

        gridLayout->addWidget(vistaSimulacion, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        botonCargarMasa = new QPushButton(centralwidget);
        botonCargarMasa->setObjectName("botonCargarMasa");

        horizontalLayout_2->addWidget(botonCargarMasa);

        botonSimular = new QPushButton(centralwidget);
        botonSimular->setObjectName("botonSimular");

        horizontalLayout_2->addWidget(botonSimular);

        Detener = new QPushButton(centralwidget);
        Detener->setObjectName("Detener");

        horizontalLayout_2->addWidget(Detener);


        gridLayout->addLayout(horizontalLayout_2, 0, 1, 1, 1);

        listaCuerpos = new QListWidget(centralwidget);
        listaCuerpos->setObjectName("listaCuerpos");

        gridLayout->addWidget(listaCuerpos, 1, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1300, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        entradaPosicionX->setPlaceholderText(QCoreApplication::translate("MainWindow", "Ingresa X Inicial", nullptr));
        entradaPosicionY->setPlaceholderText(QCoreApplication::translate("MainWindow", "Ingresa Y Inicial", nullptr));
        entradaVelocidadX->setPlaceholderText(QCoreApplication::translate("MainWindow", "Ingresa Vel_X Inicial", nullptr));
        entradaVelocidadY->setPlaceholderText(QCoreApplication::translate("MainWindow", "Ingresa Vel_Y Inicial", nullptr));
        entradaMasa->setPlaceholderText(QCoreApplication::translate("MainWindow", "Ingresa la Masa del cuerpo", nullptr));
        botonCargarMasa->setText(QCoreApplication::translate("MainWindow", "CargarMasa", nullptr));
        botonSimular->setText(QCoreApplication::translate("MainWindow", "Simular", nullptr));
        Detener->setText(QCoreApplication::translate("MainWindow", "Detener", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
