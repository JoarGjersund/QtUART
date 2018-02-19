/********************************************************************************
** Form generated from reading UI file 'serialqt.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIALQT_H
#define UI_SERIALQT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_serialqtClass
{
public:
    QAction *actionPort;
    QWidget *centralWidget;
    QFormLayout *formLayout;
    QListView *listView;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QMenuBar *menuBar;
    QMenu *menuPort;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *serialqtClass)
    {
        if (serialqtClass->objectName().isEmpty())
            serialqtClass->setObjectName(QStringLiteral("serialqtClass"));
        serialqtClass->resize(764, 668);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(serialqtClass->sizePolicy().hasHeightForWidth());
        serialqtClass->setSizePolicy(sizePolicy);
        actionPort = new QAction(serialqtClass);
        actionPort->setObjectName(QStringLiteral("actionPort"));
        centralWidget = new QWidget(serialqtClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        formLayout = new QFormLayout(centralWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        listView = new QListView(centralWidget);
        listView->setObjectName(QStringLiteral("listView"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(listView->sizePolicy().hasHeightForWidth());
        listView->setSizePolicy(sizePolicy1);

        formLayout->setWidget(0, QFormLayout::SpanningRole, listView);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy2);
        pushButton->setMaximumSize(QSize(50, 16777215));

        formLayout->setWidget(2, QFormLayout::LabelRole, pushButton);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(2);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy3);

        formLayout->setWidget(1, QFormLayout::SpanningRole, lineEdit);

        serialqtClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(serialqtClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 764, 22));
        menuPort = new QMenu(menuBar);
        menuPort->setObjectName(QStringLiteral("menuPort"));
        serialqtClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(serialqtClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        serialqtClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(serialqtClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        serialqtClass->setStatusBar(statusBar);

        menuBar->addAction(menuPort->menuAction());
        menuPort->addAction(actionPort);

        retranslateUi(serialqtClass);

        QMetaObject::connectSlotsByName(serialqtClass);
    } // setupUi

    void retranslateUi(QMainWindow *serialqtClass)
    {
        serialqtClass->setWindowTitle(QApplication::translate("serialqtClass", "serialqt", nullptr));
        actionPort->setText(QApplication::translate("serialqtClass", "Port", nullptr));
        pushButton->setText(QApplication::translate("serialqtClass", "Send", nullptr));
        menuPort->setTitle(QApplication::translate("serialqtClass", "Settings", nullptr));
    } // retranslateUi

};

namespace Ui {
    class serialqtClass: public Ui_serialqtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIALQT_H
