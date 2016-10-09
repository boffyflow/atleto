/********************************************************************************
** Form generated from reading UI file 'aboutatleto.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTATLETO_H
#define UI_ABOUTATLETO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_AboutAtleto
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *aboutLabel;
    QDialogButtonBox *buttonBox;
    QSpacerItem *verticalSpacer;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QDialog *AboutAtleto)
    {
        if (AboutAtleto->objectName().isEmpty())
            AboutAtleto->setObjectName(QStringLiteral("AboutAtleto"));
        AboutAtleto->resize(320, 166);
        AboutAtleto->setModal(true);
        gridLayout = new QGridLayout(AboutAtleto);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(AboutAtleto);
        label->setObjectName(QStringLiteral("label"));
        label->setPixmap(QPixmap(QString::fromUtf8(":/main/icons/runner32.xpm")));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        aboutLabel = new QLabel(AboutAtleto);
        aboutLabel->setObjectName(QStringLiteral("aboutLabel"));

        gridLayout->addWidget(aboutLabel, 0, 1, 1, 1);

        buttonBox = new QDialogButtonBox(AboutAtleto);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 3, 0, 1, 3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 2);

        plainTextEdit = new QPlainTextEdit(AboutAtleto);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setReadOnly(true);

        gridLayout->addWidget(plainTextEdit, 1, 1, 1, 1);


        retranslateUi(AboutAtleto);
        QObject::connect(buttonBox, SIGNAL(accepted()), AboutAtleto, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AboutAtleto, SLOT(reject()));

        QMetaObject::connectSlotsByName(AboutAtleto);
    } // setupUi

    void retranslateUi(QDialog *AboutAtleto)
    {
        AboutAtleto->setWindowTitle(QApplication::translate("AboutAtleto", "Dialog", 0));
        label->setText(QString());
        aboutLabel->setText(QApplication::translate("AboutAtleto", "TextLabel", 0));
        plainTextEdit->setPlainText(QApplication::translate("AboutAtleto", "(c) 2010 Parallel Pixels Ltd. All rights reserved.\n"
"\n"
"Licensed under Gnu Public License v3\n"
"http://www.gnu.org/licenses/gpl-3.0.html", 0));
    } // retranslateUi

};

namespace Ui {
    class AboutAtleto: public Ui_AboutAtleto {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTATLETO_H
