﻿#ifndef OCCWIDGET_H
#define OCCWIDGET_H

#include <QWidget>

#include <AIS_InteractiveContext.hxx>
#include <V3d_View.hxx>
#include <AIS_Manipulator.hxx>

class AIS_InteractiveContext;
class V3d_View;
class AIS_Manipulator;
class AIS_Shape;

class OccWidget:public QWidget
{
    Q_OBJECT

public:
    explicit OccWidget(QWidget *parent=nullptr);//set the parent arg to avoid error
    ~OccWidget();

    Handle(V3d_View) GetView()
    {
        return myView;
    }

    Handle(AIS_InteractiveContext) GetContext()
    {
        return myContext;
    }

    Handle(AIS_Manipulator) GetManipulator()
    {
        return myManipulator;
    }

    bool getViewMode(){
        return view3D;
    }

    gp_Pnt ConvertClickToPoint(Standard_Real x, Standard_Real y);

    void detachManipulator();

    void on_changeView(bool is3D);

    void stopActionHandler() {
        emit endAction();
    }

protected:
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);

    QPaintEngine *paintEngine() const;

private:
    Handle(AIS_InteractiveContext) myContext;
    Handle(V3d_View) myView;

    Handle(AIS_Manipulator) myManipulator;

    bool view3D;
    QPoint myPanStartPoint;
    Standard_Real anchorX, anchorY;

signals:
    void pickPixel(int x ,int y);
    void moveToPixel(int x, int y);
    void endPixel(int x, int y);
    void selectShapeChanged();
    void clearTreeItemSelectedShape();
    void endAction();
};

#endif // OCCWIDGET_H
