// (c) 2009 Parallel Pixels Ltd.
// $Id: aboutatleto.h 324 2010-03-16 22:33:59Z boffyflow $

#ifndef ABOUTATLETO_H
#define ABOUTATLETO_H

#include <QDialog>

namespace Ui {
    class AboutAtleto;
}

class AboutAtleto : public QDialog {
    Q_OBJECT
public:
    AboutAtleto(QWidget *parent = 0);
    ~AboutAtleto();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::AboutAtleto *ui;
};

#endif // ABOUTATLETO_H
