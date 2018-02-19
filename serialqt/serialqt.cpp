#include "serialqt.h"
#include <QtSerialPort>
#include <qmessagebox.h>
#include <QDebug>

serialqt::serialqt(QWidget *parent)
	: QMainWindow(parent), m_serial(new QSerialPort(this))
{
	openSerialPort();
	ui.setupUi(this);
	model = new QStringListModel(this);
	connect(m_serial, &QSerialPort::readyRead, this, &serialqt::readData);

}

void serialqt::openSerialPort()
{
	
	
	m_serial->setPortName("COM1");
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

	
	// Make data
	QStringList List;
	List << model->stringList() << data;

	// Populate our model
	model->setStringList(List);

	// Glue model and view together
	ui.listView->setModel(model);

	ui.listView->scrollToBottom();
}
void serialqt::writeData()
{
	qDebug("hallo");
	//m_serial->write(data);
}

