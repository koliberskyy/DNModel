#include "creatorblock.h"

CreatorBlock::CreatorBlock(QWidget *parent): QDialog(parent)
{
    grid = new QGridLayout;
    buttonAdd = new QPushButton(tr("Добавить"));
    buttonDelete = new QPushButton(tr("Сброс"));
    comboBox = new QComboBox;

    grid->addWidget(comboBox,0,0,1,2);
    grid->addWidget(buttonAdd,1,0);
    grid->addWidget(buttonDelete,1,1);
    setLayout(grid);

    this->setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    QBrush br(Qt::black);
    QPalette plt = this->palette();
    plt.setBrush(QPalette::Background, br);
    this->setPalette(plt);
    this->show();
}
