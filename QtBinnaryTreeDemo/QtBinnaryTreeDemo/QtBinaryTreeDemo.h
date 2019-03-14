#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtBinaryTreeDemo.h"
#include "BinaryTree.h"
#include "PaintArea.h"
enum TreeModes {
	Integer = 1,
	Float = 2,
	String = 3
};


template <typename T>
class DrawingTree : public BinarySearchTree<T>, public BaseObjectDrawer {
public:
	DrawingTree() : BinarySearchTree<T>() {}
	void DrawTree(QPainter& painter) override;
protected:
	void DrawNode(QPoint& box, QPainter& painter, std::shared_ptr<Node>& node);
};

class QtBinaryTreeDemo : public QMainWindow
{
	Q_OBJECT

public:
	QtBinaryTreeDemo(QWidget *parent = Q_NULLPTR);

private:

	Ui::QtBinaryTreeDemoClass ui;
	std::shared_ptr<DrawingTree<int>> IntTree;
	std::shared_ptr <DrawingTree<float>> FloatTree;
	std::shared_ptr <DrawingTree<std::string>> StringTree;
	int Mode;

public slots:
	void NewTreeInteger();
	void NewTreeFloat();
	void NewTreeString();
	void AddObjectButtonPushed();
	void RemoveObjectButtonPushed();
};
