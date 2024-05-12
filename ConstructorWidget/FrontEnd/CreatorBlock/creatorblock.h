#ifndef CREATORBLOCK_H
#define CREATORBLOCK_H

#include <QWidget>
#include <QComboBox>
#include <QPushButton>
#include <QGridLayout>
#include "CreatorWgt/creatorwgt.h"
#include <QDialog>

class CreatorBlock : public QDialog
{
    //Q_OBJECT
public:
    CreatorBlock(QWidget *parent = 0);
    QPushButton *buttonAdd;
    QPushButton *buttonDelete;
    QComboBox *comboBox;


protected:
    QGridLayout *grid;
};

#endif // CREATORBLOCK_H
