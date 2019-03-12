#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtBinnaryTreeDemo.h"

class QtBinnaryTreeDemo : public QMainWindow
{
	Q_OBJECT

public:
	QtBinnaryTreeDemo(QWidget *parent = Q_NULLPTR);

private:
	Ui::QtBinnaryTreeDemoClass ui;
};
