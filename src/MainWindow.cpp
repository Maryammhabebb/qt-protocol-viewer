#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    QWidget *central = new QWidget(this);
    setCentralWidget(central);

    protocolSelector = new QComboBox();
    protocolSelector->addItems({"HDMI", "DisplayPort", "CSI", "DSI"});

    runButton   = new QPushButton("Run Simulation");
    clearButton = new QPushButton("Clear");

    logOutput = new QTextEdit();
    logOutput->setReadOnly(true);
    logOutput->setFontFamily("Courier");

    statusBar()->showMessage("Ready — select a protocol and click Run");

    QHBoxLayout *controls = new QHBoxLayout();
    controls->addWidget(protocolSelector);
    controls->addWidget(runButton);
    controls->addWidget(clearButton);
    controls->addStretch();

    QVBoxLayout *mainLayout = new QVBoxLayout(central);
    mainLayout->addLayout(controls);
    mainLayout->addWidget(logOutput);

    connect(runButton, &QPushButton::clicked,
            this, &MainWindow::onRunClicked);

    connect(clearButton, &QPushButton::clicked,
            this, &MainWindow::onClearClicked);

    connect(protocolSelector, &QComboBox::currentTextChanged,
            this, &MainWindow::onProtocolChanged);
}

void MainWindow::onRunClicked() {
    QString protocol  = protocolSelector->currentText();
    QString timestamp = QDateTime::currentDateTime().toString("hh:mm:ss.zzz");
    logOutput->append(
        QString("[%1] %2 — packet received: value=0x%3  status=OK")
            .arg(timestamp)
            .arg(protocol)
            .arg(QString::number(rand() % 256, 16).toUpper())
        );
    statusBar()->showMessage("Running: " + protocol);
}

void MainWindow::onClearClicked() {
    logOutput->clear();
    statusBar()->showMessage("Log cleared");
}

void MainWindow::onProtocolChanged(const QString &protocol) {
    statusBar()->showMessage("Protocol selected: " + protocol);
}