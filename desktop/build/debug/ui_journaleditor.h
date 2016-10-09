/********************************************************************************
** Form generated from reading UI file 'journaleditor.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JOURNALEDITOR_H
#define UI_JOURNALEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_JournalEditor
{
public:
    QGridLayout *gridLayout;
    QLabel *distLabel;
    QLabel *weightLabel;
    QTextEdit *entryEdit;
    QDialogButtonBox *buttonBox;
    QPushButton *deleteButton;
    QLabel *locationLabel;

    void setupUi(QDialog *JournalEditor)
    {
        if (JournalEditor->objectName().isEmpty())
            JournalEditor->setObjectName(QStringLiteral("JournalEditor"));
        JournalEditor->resize(489, 416);
        gridLayout = new QGridLayout(JournalEditor);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        distLabel = new QLabel(JournalEditor);
        distLabel->setObjectName(QStringLiteral("distLabel"));

        gridLayout->addWidget(distLabel, 1, 0, 1, 1);

        weightLabel = new QLabel(JournalEditor);
        weightLabel->setObjectName(QStringLiteral("weightLabel"));

        gridLayout->addWidget(weightLabel, 3, 0, 1, 1);

        entryEdit = new QTextEdit(JournalEditor);
        entryEdit->setObjectName(QStringLiteral("entryEdit"));

        gridLayout->addWidget(entryEdit, 5, 0, 1, 2);

        buttonBox = new QDialogButtonBox(JournalEditor);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 6, 0, 1, 1);

        deleteButton = new QPushButton(JournalEditor);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));

        gridLayout->addWidget(deleteButton, 6, 1, 1, 1);

        locationLabel = new QLabel(JournalEditor);
        locationLabel->setObjectName(QStringLiteral("locationLabel"));

        gridLayout->addWidget(locationLabel, 0, 0, 1, 1);


        retranslateUi(JournalEditor);
        QObject::connect(buttonBox, SIGNAL(accepted()), JournalEditor, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), JournalEditor, SLOT(reject()));

        QMetaObject::connectSlotsByName(JournalEditor);
    } // setupUi

    void retranslateUi(QDialog *JournalEditor)
    {
        JournalEditor->setWindowTitle(QApplication::translate("JournalEditor", "Dialog", 0));
        distLabel->setText(QApplication::translate("JournalEditor", "TextLabel", 0));
        weightLabel->setText(QApplication::translate("JournalEditor", "TextLabel", 0));
        deleteButton->setText(QApplication::translate("JournalEditor", "Delete", 0));
        locationLabel->setText(QApplication::translate("JournalEditor", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class JournalEditor: public Ui_JournalEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JOURNALEDITOR_H
