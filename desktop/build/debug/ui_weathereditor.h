/********************************************************************************
** Form generated from reading UI file 'weathereditor.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEATHEREDITOR_H
#define UI_WEATHEREDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include "src/gui/temperaturelineedit.h"

QT_BEGIN_NAMESPACE

class Ui_WeatherEditor
{
public:
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *skyCombo;
    QLabel *label_2;
    TemperatureLineEdit *tempEdit;
    QLabel *label_3;
    QLineEdit *notesEdit;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QSplitter *splitter;
    QDialogButtonBox *buttonBox;
    QPushButton *deleteButton;

    void setupUi(QDialog *WeatherEditor)
    {
        if (WeatherEditor->objectName().isEmpty())
            WeatherEditor->setObjectName(QStringLiteral("WeatherEditor"));
        WeatherEditor->resize(268, 147);
        WeatherEditor->setSizeGripEnabled(true);
        WeatherEditor->setModal(true);
        gridLayout_2 = new QGridLayout(WeatherEditor);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(WeatherEditor);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        skyCombo = new QComboBox(WeatherEditor);
        QIcon icon;
        icon.addFile(QStringLiteral(":/main/icons/weather0"), QSize(), QIcon::Normal, QIcon::Off);
        skyCombo->addItem(icon, QString());
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/main/icons/weather1"), QSize(), QIcon::Normal, QIcon::Off);
        skyCombo->addItem(icon1, QString());
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/main/icons/weather2"), QSize(), QIcon::Normal, QIcon::Off);
        skyCombo->addItem(icon2, QString());
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/main/icons/weather3"), QSize(), QIcon::Normal, QIcon::Off);
        skyCombo->addItem(icon3, QString());
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/main/icons/weather4"), QSize(), QIcon::Normal, QIcon::Off);
        skyCombo->addItem(icon4, QString());
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/main/icons/weather5"), QSize(), QIcon::Normal, QIcon::Off);
        skyCombo->addItem(icon5, QString());
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/main/icons/weather6"), QSize(), QIcon::Normal, QIcon::Off);
        skyCombo->addItem(icon6, QString());
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/main/icons/weather7"), QSize(), QIcon::Normal, QIcon::Off);
        skyCombo->addItem(icon7, QString());
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/main/icons/weather8"), QSize(), QIcon::Normal, QIcon::Off);
        skyCombo->addItem(icon8, QString());
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/main/icons/weather9"), QSize(), QIcon::Normal, QIcon::Off);
        skyCombo->addItem(icon9, QString());
        skyCombo->setObjectName(QStringLiteral("skyCombo"));
        skyCombo->setEnabled(true);

        gridLayout->addWidget(skyCombo, 0, 1, 1, 1);

        label_2 = new QLabel(WeatherEditor);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        tempEdit = new TemperatureLineEdit(WeatherEditor);
        tempEdit->setObjectName(QStringLiteral("tempEdit"));

        gridLayout->addWidget(tempEdit, 1, 1, 1, 1);

        label_3 = new QLabel(WeatherEditor);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        notesEdit = new QLineEdit(WeatherEditor);
        notesEdit->setObjectName(QStringLiteral("notesEdit"));

        gridLayout->addWidget(notesEdit, 2, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(199, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 2, 0, 1, 1);

        splitter = new QSplitter(WeatherEditor);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        buttonBox = new QDialogButtonBox(splitter);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        splitter->addWidget(buttonBox);
        deleteButton = new QPushButton(splitter);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        splitter->addWidget(deleteButton);

        gridLayout_2->addWidget(splitter, 3, 0, 1, 1);


        retranslateUi(WeatherEditor);
        QObject::connect(buttonBox, SIGNAL(accepted()), WeatherEditor, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), WeatherEditor, SLOT(reject()));

        QMetaObject::connectSlotsByName(WeatherEditor);
    } // setupUi

    void retranslateUi(QDialog *WeatherEditor)
    {
        WeatherEditor->setWindowTitle(QApplication::translate("WeatherEditor", "Dialog", 0));
        label->setText(QApplication::translate("WeatherEditor", "Sky", 0));
        skyCombo->setItemText(0, QApplication::translate("WeatherEditor", "sunny", 0));
        skyCombo->setItemText(1, QApplication::translate("WeatherEditor", "partly cloudy", 0));
        skyCombo->setItemText(2, QApplication::translate("WeatherEditor", "mostly cloudy", 0));
        skyCombo->setItemText(3, QApplication::translate("WeatherEditor", "cloudy", 0));
        skyCombo->setItemText(4, QApplication::translate("WeatherEditor", "windy", 0));
        skyCombo->setItemText(5, QApplication::translate("WeatherEditor", "rain", 0));
        skyCombo->setItemText(6, QApplication::translate("WeatherEditor", "thunderstorm", 0));
        skyCombo->setItemText(7, QApplication::translate("WeatherEditor", "rain and snow", 0));
        skyCombo->setItemText(8, QApplication::translate("WeatherEditor", "snow shower", 0));
        skyCombo->setItemText(9, QApplication::translate("WeatherEditor", "snow", 0));

        label_2->setText(QApplication::translate("WeatherEditor", "Temperature", 0));
        label_3->setText(QApplication::translate("WeatherEditor", "Comment", 0));
        deleteButton->setText(QApplication::translate("WeatherEditor", "Delete", 0));
    } // retranslateUi

};

namespace Ui {
    class WeatherEditor: public Ui_WeatherEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEATHEREDITOR_H
