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
	list << model->stringList();
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
	
	m_serial->setPortName(port);
	m_serial->setBaudRate(9600);
	//m_serial->setDataBits(8);
	//m_serial->setParity(0);
	//m_serial->setStopBits(0);
	//m_serial->setFlowControl(p.flowControl);
	if (m_serial->open(QIODevice::ReadWrite)) {

		qDebug("port opened");
	}
	else 
	{
		QMessageBox::critical(this, tr("Error"), m_serial->errorString());
	}
}


void serialqt::readData()
{
	const QByteArray data = m_serial->readAll();

	list.append(data);
	model->setStringList(list);
	ui.listView->setModel(model);
	


	int temp = list.last().simplified().toInt();
	if (temp>0) dataStream.append(temp);
	if (dataStream.size() > 3)
	{ 
		dataStreamFiltered.append(
		dataStream.at(dataStream.size() - 3) + dataStream.at(dataStream.size() - 2) + dataStream.at(dataStream.size() - 1) 
		);

		int pos = dataStreamFiltered.last();
		QCursor c = cursor();
		c.setPos(mapToGlobal(QPoint(pos * 100, 200)));
		setCursor(c);
	}



	

	ui.listView->scrollToBottom();
}
void serialqt::writeData()
{
	
	const QByteArray data = ui.lineEdit->text().QString::toUtf8();
	m_serial->write(data);
}

