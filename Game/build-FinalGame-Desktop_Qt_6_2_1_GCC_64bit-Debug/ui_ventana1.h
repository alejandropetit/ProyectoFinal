/********************************************************************************
** Form generated from reading UI file 'ventana1.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VENTANA1_H
#define UI_VENTANA1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ventana1
{
public:
    QDialogButtonBox *buttonBox;
    QPushButton *pushButton;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QCheckBox *checkBox;

    void setupUi(QDialog *ventana1)
    {
        if (ventana1->objectName().isEmpty())
            ventana1->setObjectName(QString::fromUtf8("ventana1"));
        ventana1->resize(400, 300);
        ventana1->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 187, 197);"));
        buttonBox = new QDialogButtonBox(ventana1);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(210, 240, 161, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        pushButton = new QPushButton(ventana1);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(140, 190, 89, 25));
        verticalLayoutWidget = new QWidget(ventana1);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(70, 50, 241, 80));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_2 = new QLineEdit(verticalLayoutWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout_2->addWidget(lineEdit_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(verticalLayoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        checkBox = new QCheckBox(ventana1);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(130, 150, 151, 23));

        retranslateUi(ventana1);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, ventana1, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, ventana1, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(ventana1);
    } // setupUi

    void retranslateUi(QDialog *ventana1)
    {
        ventana1->setWindowTitle(QCoreApplication::translate("ventana1", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("ventana1", "PushButton", nullptr));
        label_2->setText(QCoreApplication::translate("ventana1", "Nickname", nullptr));
        lineEdit_2->setText(QString());
        label->setText(QCoreApplication::translate("ventana1", "Password", nullptr));
        checkBox->setText(QCoreApplication::translate("ventana1", "Is it your first time?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ventana1: public Ui_ventana1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANA1_H
