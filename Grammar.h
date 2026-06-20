#ifndef GRAMMAR_H
#define GRAMMAR_H

#include <QObject>
#include <QtPlugin>
#include <QWidget>

#include "Bus.h"
#include "PluginInterface.h"

namespace Ui
{
class Grammar;
}

class Grammar : public QObject, public PluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "rag-qt.PluginInterface" FILE "grammarplugin.json")
    Q_INTERFACES(PluginInterface)

  public:
    explicit Grammar(QWidget *parent = nullptr);
    ~Grammar();

    QString  Id() override { return "grammar-v0.0.1"; }
    QString  Name() override { return "grammar"; }
    QString  Icon() override { return "GrammarIcon.png"; }
    QString  Version() override { return "0.0.1"; }
    QWidget *Init(Bus *parent = nullptr) override;

  private slots:
    void _slotPing();

  private:
    Ui::Grammar *ui;
    Bus         *m_pBus;
};

#endif