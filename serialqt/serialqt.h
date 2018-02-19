#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_serialqt.h"
#include <QSerialPort>
#include <QStringListModel>
class serialqt : public QMainWindow
{
	Q_OBJECT
private slots:
	void readData();
	void writeData();
	
public:
	serialqt(QWidget *parent = Q_NULLPTR);

private:
	Ui::serialqtClass ui;
	void openSerialPort();
	QSerialPort *m_serial = nullptr;
	QStringListModel *model;
};
