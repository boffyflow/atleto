/********************************************************************************
** Form generated from reading UI file 'editorwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITORWIDGET_H
#define UI_EDITORWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditorWidget
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *prevButton;
    QDateEdit *dateEdit;
    QPushButton *todayButton;
    QPushButton *nextButton;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *horizontalSpacer;
    QLabel *weekdayLabel;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_7;
    QPushButton *editWeather;
    QSpacerItem *horizontalSpacer_8;
    QFormLayout *formLayout;
    QLabel *skyLabel;
    QLabel *tempLabel;
    QLabel *weatherNotesLabel;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_3;
    QLabel *weightLabel;
    QLabel *bmiLabel;
    QLabel *bodyfatLabel;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_6;
    QLabel *hrLabel;
    QLabel *ratingLabel;
    QPushButton *editPhysical;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_4;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *addButton;
    QPushButton *editButton;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *deleteButton;
    QTableWidget *woTable;
    QFrame *line;

    void setupUi(QWidget *EditorWidget)
    {
        if (EditorWidget->objectName().isEmpty())
            EditorWidget->setObjectName(QStringLiteral("EditorWidget"));
        EditorWidget->resize(562, 559);
        gridLayout = new QGridLayout(EditorWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        prevButton = new QPushButton(EditorWidget);
        prevButton->setObjectName(QStringLiteral("prevButton"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/main/icons/leftarrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        prevButton->setIcon(icon);
        prevButton->setFlat(true);

        horizontalLayout->addWidget(prevButton);

        dateEdit = new QDateEdit(EditorWidget);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setCalendarPopup(true);

        horizontalLayout->addWidget(dateEdit);

        todayButton = new QPushButton(EditorWidget);
        todayButton->setObjectName(QStringLiteral("todayButton"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/main/icons/cal.png"), QSize(), QIcon::Normal, QIcon::Off);
        todayButton->setIcon(icon1);
        todayButton->setFlat(true);

        horizontalLayout->addWidget(todayButton);

        nextButton = new QPushButton(EditorWidget);
        nextButton->setObjectName(QStringLiteral("nextButton"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/main/icons/rightarrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        nextButton->setIcon(icon2);
        nextButton->setFlat(true);

        horizontalLayout->addWidget(nextButton);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_9);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 0, 1, 1);

        weekdayLabel = new QLabel(EditorWidget);
        weekdayLabel->setObjectName(QStringLiteral("weekdayLabel"));
        weekdayLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(weekdayLabel, 2, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 2, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        groupBox = new QGroupBox(EditorWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_7 = new QGridLayout(groupBox);
        gridLayout_7->setContentsMargins(6, 6, 6, 6);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        editWeather = new QPushButton(groupBox);
        editWeather->setObjectName(QStringLiteral("editWeather"));

        gridLayout_7->addWidget(editWeather, 3, 0, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_8, 3, 1, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        skyLabel = new QLabel(groupBox);
        skyLabel->setObjectName(QStringLiteral("skyLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, skyLabel);

        tempLabel = new QLabel(groupBox);
        tempLabel->setObjectName(QStringLiteral("tempLabel"));
        tempLabel->setPixmap(QPixmap(QString::fromUtf8(":/main/icons/weather1")));
        tempLabel->setScaledContents(false);

        formLayout->setWidget(0, QFormLayout::FieldRole, tempLabel);

        weatherNotesLabel = new QLabel(groupBox);
        weatherNotesLabel->setObjectName(QStringLiteral("weatherNotesLabel"));

        formLayout->setWidget(1, QFormLayout::SpanningRole, weatherNotesLabel);


        gridLayout_7->addLayout(formLayout, 2, 0, 1, 2);


        horizontalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(EditorWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_4 = new QGridLayout(groupBox_2);
        gridLayout_4->setContentsMargins(6, 6, 6, 6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        weightLabel = new QLabel(groupBox_2);
        weightLabel->setObjectName(QStringLiteral("weightLabel"));

        gridLayout_3->addWidget(weightLabel, 0, 0, 1, 1);

        bmiLabel = new QLabel(groupBox_2);
        bmiLabel->setObjectName(QStringLiteral("bmiLabel"));

        gridLayout_3->addWidget(bmiLabel, 0, 1, 1, 1);

        bodyfatLabel = new QLabel(groupBox_2);
        bodyfatLabel->setObjectName(QStringLiteral("bodyfatLabel"));

        gridLayout_3->addWidget(bodyfatLabel, 1, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_5, 2, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_6, 3, 1, 1, 1);

        hrLabel = new QLabel(groupBox_2);
        hrLabel->setObjectName(QStringLiteral("hrLabel"));

        gridLayout_3->addWidget(hrLabel, 1, 1, 1, 1);

        ratingLabel = new QLabel(groupBox_2);
        ratingLabel->setObjectName(QStringLiteral("ratingLabel"));

        gridLayout_3->addWidget(ratingLabel, 2, 0, 1, 1);

        editPhysical = new QPushButton(groupBox_2);
        editPhysical->setObjectName(QStringLiteral("editPhysical"));

        gridLayout_3->addWidget(editPhysical, 3, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 0, 0, 1, 1);


        horizontalLayout_3->addWidget(groupBox_2);


        gridLayout->addLayout(horizontalLayout_3, 3, 0, 1, 3);

        pushButton = new QPushButton(EditorWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(pushButton, 4, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 4, 1, 1, 2);

        groupBox_3 = new QGroupBox(EditorWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout_2 = new QGridLayout(groupBox_3);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        addButton = new QPushButton(groupBox_3);
        addButton->setObjectName(QStringLiteral("addButton"));

        horizontalLayout_4->addWidget(addButton);

        editButton = new QPushButton(groupBox_3);
        editButton->setObjectName(QStringLiteral("editButton"));

        horizontalLayout_4->addWidget(editButton);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);

        deleteButton = new QPushButton(groupBox_3);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));

        horizontalLayout_4->addWidget(deleteButton);


        gridLayout_2->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        woTable = new QTableWidget(groupBox_3);
        if (woTable->columnCount() < 6)
            woTable->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        woTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        woTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        woTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        woTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        woTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        woTable->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        woTable->setObjectName(QStringLiteral("woTable"));
        woTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        woTable->setAlternatingRowColors(true);
        woTable->setSelectionMode(QAbstractItemView::SingleSelection);
        woTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        woTable->setIconSize(QSize(24, 24));
        woTable->setShowGrid(false);
        woTable->setSortingEnabled(true);
        woTable->horizontalHeader()->setVisible(false);
        woTable->horizontalHeader()->setHighlightSections(false);
        woTable->verticalHeader()->setVisible(false);
        woTable->verticalHeader()->setHighlightSections(false);
        woTable->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        woTable->verticalHeader()->setStretchLastSection(false);

        gridLayout_2->addWidget(woTable, 1, 0, 1, 1);


        gridLayout->addWidget(groupBox_3, 5, 0, 1, 3);

        line = new QFrame(EditorWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 1, 0, 1, 3);


        retranslateUi(EditorWidget);

        QMetaObject::connectSlotsByName(EditorWidget);
    } // setupUi

    void retranslateUi(QWidget *EditorWidget)
    {
        EditorWidget->setWindowTitle(QApplication::translate("EditorWidget", "Form", 0));
        EditorWidget->setStyleSheet(QString());
#ifndef QT_NO_TOOLTIP
        prevButton->setToolTip(QApplication::translate("EditorWidget", "Previous", 0));
#endif // QT_NO_TOOLTIP
        prevButton->setText(QString());
        dateEdit->setDisplayFormat(QApplication::translate("EditorWidget", "d-MMM-yyyy", 0));
#ifndef QT_NO_TOOLTIP
        todayButton->setToolTip(QApplication::translate("EditorWidget", "Today", 0));
#endif // QT_NO_TOOLTIP
        todayButton->setText(QString());
        todayButton->setShortcut(QApplication::translate("EditorWidget", "Ctrl+T", 0));
#ifndef QT_NO_TOOLTIP
        nextButton->setToolTip(QApplication::translate("EditorWidget", "Next", 0));
#endif // QT_NO_TOOLTIP
        nextButton->setText(QString());
        weekdayLabel->setStyleSheet(QApplication::translate("EditorWidget", "QLabel{ color:rgb(0,0,127); font: 12pt \"MS Shell Dlg 2\";}", 0));
        weekdayLabel->setText(QApplication::translate("EditorWidget", "Monday", 0));
        groupBox->setTitle(QApplication::translate("EditorWidget", "Weather", 0));
        editWeather->setText(QApplication::translate("EditorWidget", "Edit...", 0));
        skyLabel->setText(QApplication::translate("EditorWidget", "TextLabel", 0));
        tempLabel->setText(QString());
        weatherNotesLabel->setText(QApplication::translate("EditorWidget", "Comment:", 0));
        groupBox_2->setTitle(QApplication::translate("EditorWidget", "Physical", 0));
        weightLabel->setText(QApplication::translate("EditorWidget", "Weight:", 0));
        bmiLabel->setText(QApplication::translate("EditorWidget", "BMI: 00.0", 0));
        bodyfatLabel->setText(QApplication::translate("EditorWidget", "Bodyfat [%]:", 0));
        hrLabel->setText(QApplication::translate("EditorWidget", "Resting heartrate:", 0));
        ratingLabel->setText(QApplication::translate("EditorWidget", "Rating:", 0));
        editPhysical->setText(QApplication::translate("EditorWidget", "Edit...", 0));
        pushButton->setText(QApplication::translate("EditorWidget", "Journal...", 0));
        groupBox_3->setTitle(QApplication::translate("EditorWidget", "Workouts", 0));
        addButton->setText(QApplication::translate("EditorWidget", "Add", 0));
        editButton->setText(QApplication::translate("EditorWidget", "Edit", 0));
        deleteButton->setText(QApplication::translate("EditorWidget", "Delete", 0));
        QTableWidgetItem *___qtablewidgetitem = woTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("EditorWidget", "id", 0));
        QTableWidgetItem *___qtablewidgetitem1 = woTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("EditorWidget", "starttime", 0));
        QTableWidgetItem *___qtablewidgetitem2 = woTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("EditorWidget", "location", 0));
        QTableWidgetItem *___qtablewidgetitem3 = woTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("EditorWidget", "distance", 0));
        QTableWidgetItem *___qtablewidgetitem4 = woTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("EditorWidget", "time", 0));
        QTableWidgetItem *___qtablewidgetitem5 = woTable->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("EditorWidget", "pace_speed", 0));
        woTable->setStyleSheet(QApplication::translate("EditorWidget", "QTableView { background: white;}", 0));
    } // retranslateUi

};

namespace Ui {
    class EditorWidget: public Ui_EditorWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITORWIDGET_H
