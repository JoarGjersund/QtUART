#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_serialqt.h"
#include <QSerialPort>
#include <QStringListModel>
#include <QVector>
class serialqt : public QMainWindow
{
	Q_OBJECT
private slots:
	void readData();
	void writeData();
	void openSerialPort(QString port);

public:
	serialqt(QWidget *parent = Q_NULLPTR );
	QVector<int> dataStream;
	QVector<int> dataStreamFiltered;
private:
	Ui::serialqtClass ui;
	QSerialPort *m_serial = nullptr;
	QStringListModel *model;
	QStringList list;
};
