#include "PaintArea.h"


void RenderArea::paintEvent(QPaintEvent * event)
{
	QPainter MyPainter(this);
	QPen pen(Qt::black , 2, Qt::DotLine, Qt::RoundCap, Qt::RoundJoin);
	MyPainter.setPen(pen);
	MyPainter.setFont(QFont("Arial", 10));
	if (Tree) Tree->DrawTree(MyPainter);

}