#pragma once
#include <QtWidgets/qwidget.h>
#include <qpainter.h>

class BaseObjectDrawer {

public:
	virtual void DrawTree(QPainter& painter) {};
};

class RenderArea : public QWidget
{
	Q_OBJECT

public:
	RenderArea(QWidget *parent = 0):QWidget(parent), Tree() {};
	std::shared_ptr <BaseObjectDrawer> Tree;
protected:
	void paintEvent(QPaintEvent *event) override;

};