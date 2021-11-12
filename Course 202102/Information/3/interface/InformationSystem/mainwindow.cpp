#include "mainwindow.h"
#include "ui_mainwindow.h"


void MainWindow::sendQuery()
{
    QJsonObject json;
    json["type"] = "search";
    json["query"] = ui->lineEditQuery->text();
    QByteArray msg(QJsonDocument(json).toJson(QJsonDocument::Compact));

    sock->writeDatagram(msg, QHostAddress("127.0.0.1"), 62101);
    return;
}

void MainWindow::sendExtract()
{
    QJsonObject json;
    json["type"] = "extract";
    json["query"] = ui->lineEditQuery->text();
    QByteArray msg(QJsonDocument(json).toJson(QJsonDocument::Compact));

    sock->writeDatagram(msg, QHostAddress("127.0.0.1"), 62101);
    return;
}


void MainWindow::msgRcv()
{
    QByteArray msg;
    msg.resize(sock->pendingDatagramSize());
    sock->readDatagram(msg.data(), msg.size());

    auto text = QTextCodec::codecForName("utf-8")->toUnicode(msg);
    auto json = QJsonDocument::fromJson(text.toUtf8()).object();
    qDebug() << json;

    if(json["type"].toString() == "search")
    {
        auto query = json["query"].toString();
        auto resCount = json["resCount"].toInt();
        auto results = json["results"].toArray();

        ui->labelResCount->setText(QString::number(resCount));
        ui->tableWidgetQuery->setRowCount(resCount);
        int row = 0;
        for(auto iter : results)
        {
            auto res = iter.toObject();
            ui->tableWidgetQuery->setItem(row, 0, new QTableWidgetItem(res["score"].toString()));
            ui->tableWidgetQuery->setItem(row, 1, new QTableWidgetItem(res["title"].toString()));
            ui->tableWidgetQuery->setItem(row, 2, new QTableWidgetItem(res["url"].toString()));
            ui->tableWidgetQuery->setItem(row, 3, new QTableWidgetItem(res["content"].toString()));
            ++row;
        }
    }
    else //extract
    {
        auto query = json["query"].toString();
        auto adj = json["adjs"].toArray();
        auto pos = json["poss"].toArray();
        auto age = json["ages"].toArray();
        auto time = json["times"].toArray();

        ui->tableWidgetExtract->setRowCount(10);
        {
            int row = 0;
            for(auto iter : adj)
            {
                ui->tableWidgetExtract->setItem(row, 0, new QTableWidgetItem(iter.toString()));
                ++row;
            }
        }
        {
            int row = 0;
            for(auto iter : pos)
            {
                ui->tableWidgetExtract->setItem(row, 1, new QTableWidgetItem(iter.toString()));
                ++row;
            }
        }
        {
            int row = 0;
            for(auto iter : age)
            {
                ui->tableWidgetExtract->setItem(row, 2, new QTableWidgetItem(iter.toString()));
                ++row;
            }
        }
        {
            int row = 0;
            for(auto iter : time)
            {
                ui->tableWidgetExtract->setItem(row, 3, new QTableWidgetItem(iter.toString()));
                ++row;
            }
        }
    }
}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    sock = new QUdpSocket();
    connect(ui->pushButtonQuery, &QPushButton::clicked, [=](){
        sendQuery();
    });
    connect(ui->pushButtonExtract, &QPushButton::clicked, [=](){
        sendExtract();
    });
    connect(sock, &QUdpSocket::readyRead, this, &MainWindow::msgRcv);

    //ui optimized
    ui->tableWidgetQuery->setMouseTracking(true);
    connect(ui->tableWidgetQuery, &QTableWidget::cellEntered, [=](int x, int y){
        auto item = ui->tableWidgetQuery->item(x, y);
        QToolTip::showText(QCursor::pos(), item->text());
    });
    ui->tableWidgetQuery->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidgetQuery->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidgetExtract->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidgetExtract->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

MainWindow::~MainWindow()
{
    delete ui;
    sock->close();
    sock->deleteLater();
}

