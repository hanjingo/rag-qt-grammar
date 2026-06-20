#include "Grammar.h"
#include "ui_Grammar.h"

Grammar::Grammar(QWidget *parent)
    : ui(new Ui::Grammar)
{
}

Grammar::~Grammar()
{
    delete ui;
}

QWidget *Grammar::Init(Bus *parent)
{
    m_pBus = parent;

    // init connect
    connect(m_pBus, &Bus::SignalPing, this, &Grammar::_slotPing);

    // create UI
    auto wgt = new QWidget(nullptr);
    wgt->setStyleSheet("background-color: transparent;");
    ui->setupUi(wgt);
    return wgt;
}

void Grammar::_slotPing()
{
    qDebug() << "Grammar received Ping signal from Bus.";
    emit m_pBus->SignalPong();
}