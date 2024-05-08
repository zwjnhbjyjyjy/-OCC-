#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "SARibbonMainWindow.h"
#include <QTextEdit>
#include <QActionGroup>

#include <STEPCAFControl_Reader.hxx>
#include <STEPControl_Writer.hxx>
#include <IGESCAFControl_Reader.hxx>
#include <IGESControl_Writer.hxx>
#include <IGESControl_Controller.hxx>
#include <Interface_Static.hxx>
#include <StlAPI.hxx>
#include <BRep_Builder.hxx>
#include <BRepTools.hxx>
#include <Quantity_Color.hxx>

#include "OccWidget.h"
#include "Robot.h"
#include "RobotCreator.h"

class SARibbonCategory;

class MainWindow : public SARibbonMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *par = nullptr);
    ~MainWindow();

    void initFunction();
    void initToolBar();
    void initRibbon();

private:
    void createCategoryStart(SARibbonCategory *page);
    void createCategoryDoc(SARibbonCategory *page);
    void createCategoryDraw(SARibbonCategory *page);
    void createCategoryDesign(SARibbonCategory *page);
    void createCategoryControl(SARibbonCategory *page);
    void createCategoryView(SARibbonCategory *page);
    void createCategoryProcess(SARibbonCategory *page);
    void createCategoryHelp(SARibbonCategory *page);

    void creatOperationDock();

    void readPath(std::string fileName);

private slots:
    // 导入
    void on_importModel();
    // 导出
    void on_exportModel();
    void on_exportSelected();
    // 图形选择
    // 导入机器人
    void on_importRobot();
    // 仿真机器人
    void on_emulateRobot();
    // 显示机器人
    void displayRobot();
    // 显示所有隐藏的元素
    void on_displayDelete();
    // 隐藏选中项目，先选择，后操作
    void on_deleteSelected();
    // 设置选中元素的颜色
    void on_setItemColor();
    // 选中形体
    void onShapeSelected();

    // 导入路径
    void on_importPath();

private:
    OccWidget *occWidget;
    QToolBar *toolBar_view;
    QActionGroup *group3D;
    QList <Handle(AIS_InteractiveObject)> m_displayedShapes;
    QTextEdit* entityInfo;
    Robot *myWorkRobot;

signals:
    void endDraw();
};

#endif // MAINWINDOW_H
