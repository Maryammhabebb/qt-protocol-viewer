#pragma once
#include <QMainWindow>
#include <QPushButton>
#include <QComboBox>
#include <QTextEdit>
#include <QLabel>
#include <QStatusBar>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:
    void onRunClicked();
    void onClearClicked();
    void onProtocolChanged(const QString &protocol);

private:
    QComboBox   *protocolSelector;
    QPushButton *runButton;
    QPushButton *clearButton;
    QTextEdit   *logOutput;
};