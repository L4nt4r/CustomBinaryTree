#include "QtBinaryTreeDemo.h"
#include <qmessagebox.h>
QtBinaryTreeDemo::QtBinaryTreeDemo(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.actionInteger, SIGNAL(triggered()), this, SLOT(NewTreeInteger()));
	connect(ui.actionFloat, SIGNAL(triggered()), this, SLOT(NewTreeFloat()));
	connect(ui.actionString, SIGNAL(triggered()), this, SLOT(NewTreeString()));
	connect(ui.AddElementButton, SIGNAL(clicked()), this, SLOT(AddObjectButtonPushed()));
	connect(ui.DeleteElementButton, SIGNAL(clicked()), this, SLOT(RemoveObjectButtonPushed()));

}
void QtBinaryTreeDemo::NewTreeInteger() {
	FloatTree.reset();
	IntTree.reset();
	IntTree = std::shared_ptr < DrawingTree<int>>(new DrawingTree<int>());
	StringTree.reset();
	Mode = Integer;
	ui.TreeDisplay->Tree = IntTree;
	ui.TreeDisplay->update();
}
void QtBinaryTreeDemo::NewTreeFloat() {
	FloatTree.reset();
	FloatTree = std::shared_ptr < DrawingTree<float>>(new DrawingTree<float>());
	IntTree.reset();
	StringTree.reset();
	Mode = Float;
	ui.TreeDisplay->Tree = FloatTree;
	ui.TreeDisplay->update();
}
void QtBinaryTreeDemo::NewTreeString() {
	FloatTree.reset();
	IntTree.reset();
	StringTree.reset();
	StringTree = std::shared_ptr < DrawingTree<std::string>>(new DrawingTree<std::string>());
	Mode = String;
	ui.TreeDisplay->Tree = StringTree;
	ui.TreeDisplay->update();
}
void QtBinaryTreeDemo::AddObjectButtonPushed() {
	bool ok;
	int intValue;
	float floatValue;
	std:string stringValue;

	switch (Mode) {
	case Integer:
		intValue = ui.ObjectValueEditBox->toPlainText().toInt(&ok);
		if (ok)
			IntTree->push(intValue);
		else 
			QMessageBox::information(this, "Niepoprawna Wartosc", "Prosze wpisac poprawna wartosc");
			
		break;
	
	case Float:
		 floatValue = ui.ObjectValueEditBox->toPlainText().toFloat(&ok);
		 if (ok)
			 FloatTree->push(floatValue);
		else
			QMessageBox::information(this, "Niepoprawna Wartosc", "Prosze wpisac poprawna wartosc");
		break;
	
	case String:
		stringValue = ui.ObjectValueEditBox->toPlainText().toStdString();
		StringTree->push(stringValue);
		break;
	}
	ui.TreeDisplay->update();
}
void QtBinaryTreeDemo::RemoveObjectButtonPushed() {
	bool ok;
	int intValue;
	float floatValue;
	QString stringValue;

	QString ValueName = ui.ObjectNameEditBox->toPlainText();
	switch (Mode) {
	case Integer:
		intValue = ui.ObjectValueEditBox->toPlainText().toInt(&ok);
		if (ok) {
			if (IntTree->remove(intValue, ValueName.toStdString())) {
				ui.TreeDisplay->update();
			}
			else {
				QMessageBox::information(this, "Nieznaleziono Wartosci", "Nie znaleziono wartoœci. Value: " + QString::number(intValue) + " Name: " + ValueName);
			}
		}
		else
			QMessageBox::information(this, "Niepoprawna Wartosc", "Prosze wpisac poprawna wartosc, wymagany typ ca³kowity");
		break;

	case Float:
		floatValue = ui.ObjectValueEditBox->toPlainText().toFloat(&ok);
		if (ok) 
			if (FloatTree->remove(floatValue, ValueName.toStdString())) {
				ui.TreeDisplay->update();
			}
			else {
				QMessageBox::information(this, "Nieznaleziono Wartosci", "Nie znaleziono wartosci. Value: " + QString::number(floatValue) + " Name: " + ValueName);
			}
		
		else
			QMessageBox::information(this, "Niepoprawna Wartosc", "Prosze wpisac poprawna wartosc, wymagany typ zmiennoprzecinkowy");
		break;

	case String:
		stringValue = ui.ObjectValueEditBox->toPlainText();
		if (StringTree->remove(stringValue.toStdString(), ValueName.toStdString())) {
			ui.TreeDisplay->update();
		} 
		else {
			QMessageBox::information(this, "Nieznaleziono Wartosci", "Nie znaleziono wartoœci. Value: " + stringValue + " Name: " + ValueName);
		}
		break;
	}
}

template<typename T>
void DrawingTree<T>::DrawTree(QPainter & painter)
{
	if (this->TreeHeight > 5) {
		auto point = QPoint(200, 200);
		painter.drawText(point, "To many object to display");
		return;
	}
	auto point = QPoint(1, 1);
	DrawNode(point, painter, root);
}

template<typename T>
void DrawingTree<T>::DrawNode(QPoint& point, QPainter & painter, std::shared_ptr<Node>& node)
{
	
	int X = 1600 / (point.y() + 1)*point.x();
	int Y = log2(point.y()) * 110;

	painter.drawText(X, Y, "Name:");
	Y += 20;
	painter.drawText(X, Y, QString::fromStdString(node->name));
	Y += 20; 
	painter.drawText(X, Y, "Value:");
	Y += 20; 
	painter.drawText(X, Y, QString::fromStdString(toString<T>(node->value)));
	Y += 20;

	if (node->leftChild) {
		QPoint point2(point.x()*2-1, point.y() * 2);
		painter.drawLine(X,Y, 1600/(point2.y()+1)*point2.x(), Y+10);
		DrawNode(point2, painter, node->leftChild);
	}


	if (node->rightChild) {
		point.setY(point.y() * 2);
		point.setX(point.x() * 2);
			painter.drawLine(X,Y, 1600 / (point.y() + 1)*point.x(),Y+10);
		DrawNode(point, painter, node->rightChild);
	}

}
