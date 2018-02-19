#include "serialqt.h"
#include <QtSerialPort>
#include <qmessagebox.h>
#include <QDebug>
#include <QString>
serialqt::serialqt(QWidget *parent)
	: QMainWindow(parent), m_serial(new QSerialPort(this))
{

	ui.setupUi(this);
	model = new QStringListModel(this);
	List << model->stringList();
	ui.listView->setModel(model);


	QSignalMapper * signalMapper = new QSignalMapper(this);
	int i = 0;
	Q_FOREACH(QSerialPortInfo port, QSerialPortInfo::availablePorts())
	{
		QAction *act = ui.menuPort->addAction(port.portName());
		connect(act, SIGNAL(triggered()), signalMapper, SLOT(map()));
		signalMapper->setMapping(act, port.portName());
		i++;
	}

	QObject::connect(signalMapper, SIGNAL(mapped(QString)), this, SLOT(openSerialPort(QString)));
	QObject::connect(m_serial, &QSerialPort::readyRead, this, &serialqt::readData);
	QObject::connect(ui.pushButton, SIGNAL(released()), this, SLOT(writeData()));
}


void serialqt::openSerialPort(QString port)
{
	if (m_serial->isOpen()) m_serial->close();
	qDebug("port opened");
	m_serial->setPortName(port);
	m_serial->setBaudRate(9600);
	//m_serial->setDataBits(8);
	//m_serial->setParity(0);
	//m_serial->setStopBits(0);
	//m_serial->setFlowControl(p.flowControl);
	if (m_serial->open(QIODevice::ReadWrite)) {

		
	}
	else 
	{
		QMessageBox::critical(this, tr("Error"), m_serial->errorString());
	}
}


void serialqt::readData()
{
	const QByteArray data = m_serial->readAll();

	List.append(data);
	model->setStringList(List);
	ui.listView->setModel(model);
	

	ui.listView->scrollToBottom();
	
}
void serialqt::writeData()
{

	const QByteArray data = ui.lineEdit->text().QString::toUtf8();
	m_serial->write(data);
}

