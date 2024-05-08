#include "MainWindow.h"
#include "AIS_Shape.hxx"
#include "RobotLink.h"
#include "SARibbonBar.h"
#include "SARibbonCategory.h"
#include "SARibbonPannel.h"
#include "SARibbonMenu.h"
#include "SARibbonApplicationButton.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QColorDialog>
#include <QInputDialog>
#include <QToolBar>
#include <QDockWidget>
#include <QTableView>
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>
#include <QDebug>
#include <QTextCodec>
#include <QtConcurrent>

#include <gp_Circ.hxx>
#include <gp_Sphere.hxx>
#include <Geom_Line.hxx>
#include <Geom_Circle.hxx>
#include <Geom_BSplineCurve.hxx>
#include <Geom_TrimmedCurve.hxx>
#include <Geom_SphericalSurface.hxx>
#include <Geom_BSplineSurface.hxx>
#include <GC_MakeArcOfCircle.hxx>
#include <Geom_Axis2Placement.hxx>
#include <AIS_Trihedron.hxx>
#include <BRepBuilderAPI_MakeSolid.hxx>

#include "DesignCommand3D.h"
#include "DesignCommand.h"
#include "DrawCommand.h"
#include "TopoDS_Vertex.hxx"
#include "ModelMaker.hpp"
#include "BasicModeling.hpp"
#include "MyCreation.hpp"
#include "qapplication.h"

MainWindow::MainWindow(QWidget *par) :
    SARibbonMainWindow(par),
    myWorkRobot(nullptr)
{
    setWindowTitle("ISPP");
}

MainWindow::~MainWindow()
{
    delete myWorkRobot;
}

void MainWindow::initFunction()
{
    occWidget = new OccWidget(this);
    setCentralWidget(occWidget);

    // 选中形状时，通过此获取选中的形状信息
    connect(occWidget, &OccWidget::selectShapeChanged, this, &MainWindow::onShapeSelected);

    // 设置信息栏
    entityInfo = new QTextEdit(this);
    entityInfo->setMinimumWidth(200);
    QDockWidget* dock = new QDockWidget(this);
    dock->setWidget(entityInfo);
    addDockWidget(Qt::LeftDockWidgetArea, dock);

    group3D = new QActionGroup(this);
    group3D->setExclusive(false);
}

void MainWindow::initToolBar()
{
    toolBar_view = new QToolBar("视图",this);
    toolBar_view->setAllowedAreas(Qt::TopToolBarArea);

    QAction *act = new QAction(QIcon(":/icons/Axo.png"),"重置视图",this);
    act->setActionGroup(group3D);
    /* Your code here */
    connect(act,&QAction::triggered,this,[=](){
        occWidget->GetView()->SetProj(V3d_XposYnegZpos);
        occWidget->GetView()->FitAll();
    });
    toolBar_view->addAction(act);

    act = new QAction(QIcon(":/icons/Left.png"),"左视图",this);
    act->setActionGroup(group3D);
    /* Your code here */
    connect(act,&QAction::triggered,this,[=](){
        occWidget->GetView()->SetProj(V3d_Xneg);
        occWidget->GetView()->FitAll();
    });
    toolBar_view->addAction(act);

    act = new QAction(QIcon(":/icons/Right.png"),"右视图",this);
    act->setActionGroup(group3D);
    /* Your code here */
    connect(act,&QAction::triggered,this,[=](){
        occWidget->GetView()->SetProj(V3d_Xpos);
        occWidget->GetView()->FitAll();
    });
    toolBar_view->addAction(act);

    act = new QAction(QIcon(":/icons/Front.png"),"前视图",this);
    act->setActionGroup(group3D);
    /* Your code here */
    connect(act,&QAction::triggered,this,[=](){
        occWidget->GetView()->SetProj(V3d_Yneg);
        occWidget->GetView()->FitAll();
    });
    toolBar_view->addAction(act);

    act = new QAction(QIcon(":/icons/Back.png"),"后视图",this);
    act->setActionGroup(group3D);
    /* Your code here */
    connect(act,&QAction::triggered,this,[=](){
        occWidget->GetView()->SetProj(V3d_Ypos);
        occWidget->GetView()->FitAll();
    });
    toolBar_view->addAction(act);

    act = new QAction(QIcon(":/icons/Top.png"),"顶视图",this);
    act->setActionGroup(group3D);
    /* Your code here */
    connect(act,&QAction::triggered,this,[=](){
        occWidget->GetView()->SetProj(V3d_Zpos);
        occWidget->GetView()->FitAll();
    });
    toolBar_view->addAction(act);

    act = new QAction(QIcon(":/icons/Bottom.png"),"底视图",this);
    act->setActionGroup(group3D);
    /* Your code here */
    connect(act,&QAction::triggered,this,[=](){
        occWidget->GetView()->SetProj(V3d_Zneg);
        occWidget->GetView()->FitAll();
    });
    toolBar_view->addAction(act);

    toolBar_view->addSeparator();

    act = new QAction(QIcon(":/icons/view_shade.png"),"显示模式",this);
    act->setActionGroup(group3D);
    connect(act,&QAction::triggered,this,[=](){
        /* Your code here */
        if(occWidget->GetContext()->DisplayMode() == AIS_Shaded)
        {
            occWidget->GetContext()->SetDisplayMode(AIS_WireFrame,Standard_True);
            act->setIcon(QIcon(":/icons/view_wire.png"));
        }
        else
        {
            occWidget->GetContext()->SetDisplayMode(AIS_Shaded,Standard_True);
            act->setIcon(QIcon(":/icons/view_shade.png"));
        }
    });
    toolBar_view->addAction(act);

    act = new QAction(QIcon(":/icons/color_tool.png"),"设置颜色",this);
    connect(act,&QAction::triggered,this,&MainWindow::on_setItemColor);
    toolBar_view->addAction(act);

    act = new QAction(QIcon(":/icons/alpha.png"),"设置透明度",this);
    connect(act,&QAction::triggered,this,[=]() {
        /* Your code here */
        occWidget->GetContext()->InitSelected();
        if(occWidget->GetContext()->HasSelectedShape()) {
            double a = QInputDialog::getDouble(this, "透明度", "", 0, 0.0, 1.0);
            Handle(AIS_InteractiveObject) Current = occWidget->GetContext()->SelectedInteractive() ;
            Current->SetTransparency(a);
        }
    });
    toolBar_view->addAction(act);

    act = new QAction(QIcon(":/icons/hide.png"),"隐藏选中模型",this);
    connect(act,&QAction::triggered,this,&MainWindow::on_deleteSelected);
    toolBar_view->addAction(act);

    act = new QAction(QIcon(":/icons/display.png"),"显示隐藏的模型",this);
    connect(act,&QAction::triggered,this,&MainWindow::on_displayDelete);
    toolBar_view->addAction(act);

    toolBar_view->addSeparator();

    act = new QAction(QIcon(":/icons/selectReset.png"),"重置选择",this);
    connect(act,&QAction::triggered,this,[=](){
        BasicModeling::selection_activate(0, occWidget->GetContext());
    });
    toolBar_view->addAction(act);

    act = new QAction(QIcon(":/icons/selectPnt.png"),"选择点",this);
    connect(act,&QAction::triggered,this,[=](){
        BasicModeling::selection_activate(1, occWidget->GetContext());
    });
    toolBar_view->addAction(act);

    act = new QAction(QIcon(":/icons/selectEdge.png"),"选择边",this);
    connect(act,&QAction::triggered,this,[=](){
        BasicModeling::selection_activate(2, occWidget->GetContext());
    });
    toolBar_view->addAction(act);

    act = new QAction(QIcon(":/icons/selectFace.png"),"选择面",this);
    connect(act,&QAction::triggered,this,[=](){
        BasicModeling::selection_activate(4, occWidget->GetContext());
    });
    toolBar_view->addAction(act);
    act = new QAction(QIcon(":/icons/selectSolid.png"),"选择实体",this);
    act->setActionGroup(group3D);
    connect(act,&QAction::triggered,this,[=](){
        BasicModeling::selection_activate(6, occWidget->GetContext());
    });
    toolBar_view->addAction(act);

    addToolBar(Qt::TopToolBarArea,toolBar_view);
}

void MainWindow::initRibbon()
{
    SARibbonBar *ribbon = ribbonBar();
    ribbon->applitionButton()->setVisible(false);

    SARibbonCategory* categoryStart = ribbon->addCategoryPage("开始");
    createCategoryStart(categoryStart);
    SARibbonCategory* categoryDoc = ribbon->addCategoryPage("文件");
    createCategoryDoc(categoryDoc);
    SARibbonCategory* categoryDraw = ribbon->addCategoryPage("绘制");
    createCategoryDraw(categoryDraw);
    SARibbonCategory* categorDesign = ribbon->addCategoryPage("设计");
    createCategoryDesign(categorDesign);
    SARibbonCategory* categoryControl = ribbon->addCategoryPage("控制");
    createCategoryControl(categoryControl);
    SARibbonCategory* categoryView = ribbon->addCategoryPage("视图");
    createCategoryView(categoryView);
    SARibbonCategory* categoryProcess = ribbon->addCategoryPage("加工");
    createCategoryProcess(categoryProcess);
    SARibbonCategory* categoryHelp = ribbon->addCategoryPage("帮助");
    createCategoryHelp(categoryHelp);
}

void MainWindow::createCategoryStart(SARibbonCategory *page)
{
    SARibbonPannel* pannel = page->addPannel("");

    QAction* act2D = new QAction(this);
    QAction* act3D = new QAction(this);

    act2D->setIcon(QIcon(":/icons/2d.png"));
    act2D->setText("2D");
    pannel->addLargeAction(act2D);
    connect(act2D,&QAction::triggered,this,[=]() {
        occWidget->GetContext()->RemoveAll(true);
        occWidget->stopActionHandler();
        occWidget->on_changeView(false);

        act3D->setEnabled(true);
        group3D->setEnabled(false);
        act2D->setEnabled(false);
    });

    pannel->addSeparator();

    act3D->setIcon(QIcon(":/icons/3d_color.png"));
    act3D->setText("3D");
    pannel->addLargeAction(act3D);
    connect(act3D,&QAction::triggered,this,[=]() {
        occWidget->GetContext()->RemoveAll(true);
        occWidget->stopActionHandler();
        occWidget->on_changeView(true);

        act2D->setEnabled(true);
        group3D->setEnabled(true);
        act3D->setEnabled(false);
    });

//#ifndef VIEW3D
//    act2D->setEnabled(false);
//    group3D->setEnabled(false);
//#endif
}

void MainWindow::createCategoryDoc(SARibbonCategory *page)
{
    SARibbonPannel* pannel = page->addPannel("");

    QAction* act = new QAction(this);
    act->setIcon(QIcon(":/icons/import.png"));
    act->setText("导入");
    pannel->addLargeAction(act);
    connect(act,&QAction::triggered,this,&MainWindow::on_importModel);

    act = new QAction(this);
    act->setIcon(QIcon(":/icons/export.png"));
    act->setText("导出");
    pannel->addLargeAction(act);
    connect(act,&QAction::triggered,this,&MainWindow::on_exportModel);

    act = new QAction(this);
    act->setIcon(QIcon(":/icons/import_robot.png"));
    act->setText("导入机器人");
    act->setActionGroup(group3D);
    pannel->addLargeAction(act);
    connect(act,&QAction::triggered,this,&MainWindow::on_importRobot);
}

void MainWindow::createCategoryDraw(SARibbonCategory *page)
{
    SARibbonPannel* pannel = page->addPannel("");

    QAction* act = new QAction(this);
    act->setIcon(QIcon(":/icons/point.png"));
    act->setText("画点");
    pannel->addLargeAction(act);
    /* Your code here */
    connect(act, &QAction::triggered, this, [=]() {
        occWidget->stopActionHandler();
        occWidget->detachManipulator();
        DrawPointCommand* cmd = new DrawPointCommand(occWidget, this);
        connect(cmd, &DrawCommand::setDrawInfo, this, [=](QString info){
            entityInfo->setText(info);
        });
    });

    act = new QAction(this);
    act->setIcon(QIcon(":/icons/line.png"));
    act->setText("画线");
    pannel->addLargeAction(act);
    /* Your code here */
    // 设置按钮功能
    connect(act, &QAction::triggered, this, [=]() {
        occWidget->stopActionHandler();
        occWidget->detachManipulator();
        DrawLineCommand* cmd = new DrawLineCommand(occWidget, this);
        connect(cmd, &DrawCommand::setDrawInfo, this, [=](QString info){
            entityInfo->setText(info);
        });
    });

    act = new QAction(this);
    act->setIcon(QIcon(":/icons/circle.png"));
    act->setText("画圆");
    pannel->addLargeAction(act);
    /* Your code here */
    // 设置按钮功能
    connect(act, &QAction::triggered, this, [=]() {
        occWidget->stopActionHandler();
        occWidget->detachManipulator();
        DrawCircCommand* cmd = new DrawCircCommand(occWidget, this);
        connect(cmd, &DrawCommand::setDrawInfo, this, [=](QString info){
            entityInfo->setText(info);
        });
    });

    act = new QAction(this);
    act->setIcon(QIcon(":/icons/ellipse.png"));
    act->setText("画椭圆");
    pannel->addLargeAction(act);
    /* Your code here */
    // 设置按钮功能
    connect(act, &QAction::triggered, this, [=]() {
        occWidget->stopActionHandler();
        occWidget->detachManipulator();
        DrawElipsCommand* cmd = new DrawElipsCommand(occWidget, this);
        connect(cmd, &DrawCommand::setDrawInfo, this, [=](QString info){
            entityInfo->setText(info);
        });
    });

    act = new QAction(this);
    act->setIcon(QIcon(":/icons/spline.png"));
    act->setText("画样条");
    pannel->addLargeAction(act);
    /* Your code here */
    // 设置按钮功能
    connect(act, &QAction::triggered, this, [=]() {
        occWidget->stopActionHandler();
        occWidget->detachManipulator();
        DrawSplineCommand* cmd = new DrawSplineCommand(occWidget, this);
        connect(cmd, &DrawCommand::setDrawInfo, this, [=](QString info){
            entityInfo->setText(info);
        });
    });

    pannel = page->addPannel("");

    act = new QAction(this);
    act->setIcon(QIcon(":/icons/box.png"));
    act->setText("画长方体");
    act->setActionGroup(group3D);
    pannel->addLargeAction(act);
    /* Your code here */
    connect(act,&QAction::triggered,this,[=]() {
        occWidget->stopActionHandler();
        occWidget->detachManipulator();
        DrawBoxCommand* cmd = new DrawBoxCommand(occWidget, this);
        connect(cmd, &DrawCommand::setDrawInfo, this, [=](QString info){
            entityInfo->setText(info);
        });
    });

    act = new QAction(this);
    act->setIcon(QIcon(":/icons/cylinder.png"));
    act->setText("画圆柱体");
    act->setActionGroup(group3D);
    pannel->addLargeAction(act);
    /* Your code here */
    connect(act,&QAction::triggered,this,[=]() {
        occWidget->stopActionHandler();
        occWidget->detachManipulator();
        DrawCylinderCommand* cmd = new DrawCylinderCommand(occWidget, this);
        connect(cmd, &DrawCommand::setDrawInfo, this, [=](QString info){
            entityInfo->setText(info);
        });
    });

    act = new QAction(this);
    act->setIcon(QIcon(":/icons/cone.png"));
    act->setText("画圆锥体");
    act->setActionGroup(group3D);
    pannel->addLargeAction(act);
    /* Your code here */
    connect(act,&QAction::triggered,this,[=]() {
        occWidget->stopActionHandler();
        occWidget->detachManipulator();
        DrawConeCommand* cmd = new DrawConeCommand(occWidget, this);
        connect(cmd, &DrawCommand::setDrawInfo, this, [=](QString info){
            entityInfo->setText(info);
        });
    });

    act = new QAction(this);
    act->setIcon(QIcon(":/icons/sphere.png"));
    act->setText("画球体");
    act->setActionGroup(group3D);
    pannel->addLargeAction(act);
    /* Your code here */
    connect(act,&QAction::triggered,this,[=]() {
        occWidget->stopActionHandler();
        occWidget->detachManipulator();
        DrawSphereCommand* cmd = new DrawSphereCommand(occWidget, this);
        connect(cmd, &DrawCommand::setDrawInfo, this, [=](QString info){
            entityInfo->setText(info);
        });
    });

    act = new QAction(this);
    act->setIcon(QIcon(":/icons/torus.png"));
    act->setText("画圆环体");
    act->setActionGroup(group3D);
    pannel->addLargeAction(act);
    /* Your code here */
    connect(act,&QAction::triggered,this,[=]() {
        occWidget->stopActionHandler();
        occWidget->detachManipulator();
        DrawTorusCommand* cmd = new DrawTorusCommand(occWidget, this);
        connect(cmd, &DrawCommand::setDrawInfo, this, [=](QString info){
            entityInfo->setText(info);
        });
    });

    pannel = page->addPannel("");

    act = new QAction(this);
    act->setIcon(QIcon(":/icons/model.png"));
    act->setText("自定义模型");
    act->setActionGroup(group3D);
    pannel->addLargeAction(act);
    /* Your code here */
    connect(act,&QAction::triggered,this,[=]() {
        occWidget->stopActionHandler();
        occWidget->detachManipulator();
        TopoDS_Shape myDesignShape = MyCreation::MyDesign();
        Handle(AIS_Shape) anAisDesign = new AIS_Shape(myDesignShape);
        m_displayedShapes.append(anAisDesign);
        occWidget->GetContext()->Display(anAisDesign, true);
        occWidget->GetView()->FitAll();
    });
}

void MainWindow::createCategoryDesign(SARibbonCategory *page)
{
    SARibbonPannel* pannel = page->addPannel("");

    QAction* act = new QAction(this);
    act->setIcon(QIcon(":/icons/dispersion.png"));
    act->setText("离散");
    pannel->addLargeAction(act);
    /* Your code here */
    // 设置按钮功能
    connect(act, &QAction::triggered, this, [=]() {
        occWidget->stopActionHandler();
        occWidget->detachManipulator();
        DispersionCommand* cmd = new DispersionCommand(occWidget, this);
        connect(cmd, &DesignCommand::setDesignInfo, this, [=](QString info){
            entityInfo->setText(info);
        });
    });

    act = new QAction(this);
    act->setIcon(QIcon(":/icons/poler.png"));
    act->setText("求极值");
    pannel->addLargeAction(act);
    /* Your code here */
    // 设置按钮功能
    connect(act, &QAction::triggered, this, [=]() {
        occWidget->stopActionHandler();
        occWidget->detachManipulator();
        ExtremCommand* cmd = new ExtremCommand(occWidget, this);
        connect(cmd, &DesignCommand::setDesignInfo, this, [=](QString info){
            entityInfo->setText(info);
        });
    });

    act = new QAction(this);
    act->setIcon(QIcon(":/icons/project2curve.png"));
    act->setText("投影到线");
    pannel->addLargeAction(act);
    /* Your code here */
    // 设置按钮功能
    connect(act, &QAction::triggered, this, [=]() {
        occWidget->stopActionHandler();
        occWidget->detachManipulator();
        Project2CurveCommand* cmd = new Project2CurveCommand(occWidget, this);
        connect(cmd, &DesignCommand::setDesignInfo, this, [=](QString info){
            entityInfo->setText(info);
        });
    });

    pannel = page->addPannel("");

    act = new QAction(this); // 先点击按钮，后选择元素
    act->setText("交");
    act->setIcon(QIcon(":/icons/&.png"));
    act->setActionGroup(group3D);
    pannel->addLargeAction(act);
    /* Your code here */
    connect(act, &QAction::triggered, this, [=]() {
        occWidget->stopActionHandler();
        occWidget->detachManipulator();
        BoolDesignCommand* cmd = new BoolDesignCommand(1,occWidget, this);
        connect(cmd, &DesignCommand3D::setDesignInfo, this, [=](QString info){
            entityInfo->setText(info);
        });
    });

    act = new QAction(this); // 先点击按钮，后选择元素
    act->setText("并");
    act->setIcon(QIcon(":/icons/U.png"));
    act->setActionGroup(group3D);
    pannel->addLargeAction(act);
    /* Your code here */
    connect(act, &QAction::triggered, this, [=]() {
        occWidget->stopActionHandler();
        occWidget->detachManipulator();
        BoolDesignCommand* cmd = new BoolDesignCommand(0,occWidget, this);
        connect(cmd, &DesignCommand3D::setDesignInfo, this, [=](QString info){
            entityInfo->setText(info);
        });
    });

    act = new QAction(this); // 先点击按钮，后选择元素
    act->setText("差");
    act->setIcon(QIcon(":/icons/-.png"));
    act->setActionGroup(group3D);
    pannel->addLargeAction(act);
    /* Your code here */
    connect(act, &QAction::triggered, this, [=]() {
        occWidget->stopActionHandler();
        occWidget->detachManipulator();
        BoolDesignCommand* cmd = new BoolDesignCommand(2,occWidget, this);
        connect(cmd, &DesignCommand3D::setDesignInfo, this, [=](QString info){
            entityInfo->setText(info);
        });
    });

    act = new QAction(this);  // 先选择元素，后点击按钮
    act->setIcon(QIcon(":/icons/transform.png"));
    act->setText("变换");
    act->setActionGroup(group3D);
    pannel->addLargeAction(act);
    /* Your code here */
    connect(act,&QAction::triggered,this,[=]() {
        // TransformCommand* cmd = new TransformCommand(occWidget, this);
        occWidget->stopActionHandler();
        occWidget->GetContext()->InitSelected();
        if(occWidget->GetContext()->HasSelectedShape()) {
            Handle(AIS_InteractiveObject) Current = occWidget->GetContext()->SelectedInteractive() ;
            occWidget->GetManipulator()->Attach(Current);
            occWidget->GetView()->Update();
        } else {
            occWidget->detachManipulator();
            occWidget->GetView()->Update();
        }
    });

    act = new QAction(this); // 先点击按钮，后选择元素
    act->setText("投影到面");
    act->setIcon(QIcon(":/icons/project2face.png"));
    act->setActionGroup(group3D);
    pannel->addLargeAction(act);
    /* Your code here */
    connect(act, &QAction::triggered, this, [=]() {
        occWidget->stopActionHandler();
        occWidget->detachManipulator();
        Project2FaceCommand* cmd = new Project2FaceCommand(occWidget, this);
        connect(cmd, &DesignCommand3D::setDesignInfo, this, [=](QString info){
            entityInfo->setText(info);
        });
    });

    act = new QAction(this);  // 先选择元素，后点击按钮
    act->setText("圆角");
    act->setIcon(QIcon(":/icons/fillet.png"));
    act->setActionGroup(group3D);
    pannel->addLargeAction(act);
    /* Your code here */
    connect(act, &QAction::triggered, this, [=]() {
        occWidget->stopActionHandler();
        occWidget->detachManipulator();
        FilletCommand* cmd = new FilletCommand(occWidget, this);
        connect(cmd, &DesignCommand3D::setDesignInfo, this, [=](QString info){
            entityInfo->setText(info);
        });
    });

    act = new QAction(this);  // 先选择元素，后点击按钮
    act->setText("倒角");
    act->setIcon(QIcon(":/icons/corner.png"));
    act->setActionGroup(group3D);
    pannel->addLargeAction(act);
    /* Your code here */
    connect(act, &QAction::triggered, this, [=]() {
        occWidget->stopActionHandler();
        occWidget->detachManipulator();
        ChamferCommand* cmd = new ChamferCommand(occWidget, this);
        connect(cmd, &DesignCommand3D::setDesignInfo, this, [=](QString info){
            entityInfo->setText(info);
        });
    });

    pannel = page->addPannel("");

    act = new QAction(this);  // 先选择元素，后点击按钮
    act->setText("移动");
    act->setIcon(QIcon(":/icons/translate.png"));
    act->setActionGroup(group3D);
    pannel->addLargeAction(act);
    /* Your code here */
    connect(act, &QAction::triggered, this, [=]() {
        occWidget->stopActionHandler();
        occWidget->detachManipulator();
        TranslateCommand* cmd = new TranslateCommand(occWidget, this);
        connect(cmd, &DesignCommand3D::setDesignInfo, this, [=](QString info){
            entityInfo->setText(info);
        });
    });

    act = new QAction(this);  // 先选择元素，后点击按钮
    act->setText("旋转");
    act->setIcon(QIcon(":/icons/rotate.png"));
    act->setActionGroup(group3D);
    pannel->addLargeAction(act);
    /* Your code here */
    connect(act, &QAction::triggered, this, [=]() {
        occWidget->stopActionHandler();
        occWidget->detachManipulator();
        RotateCommand* cmd = new RotateCommand(occWidget, this);
        connect(cmd, &DesignCommand3D::setDesignInfo, this, [=](QString info){
            entityInfo->setText(info);
        });
    });

    act = new QAction(this);  // 先选择元素，后点击按钮
    act->setText("缩放");
    act->setIcon(QIcon(":/icons/scale.png"));
    act->setActionGroup(group3D);
    pannel->addLargeAction(act);
    /* Your code here */
    connect(act, &QAction::triggered, this, [=]() {
        occWidget->stopActionHandler();
        occWidget->detachManipulator();
        ScaleCommand* cmd = new ScaleCommand(occWidget, this);
        connect(cmd, &DesignCommand3D::setDesignInfo, this, [=](QString info){
            entityInfo->setText(info);
        });
    });

    act = new QAction(this);  // 先选择元素，后点击按钮
    act->setText("镜像");
    act->setIcon(QIcon(":/icons/mirror.png"));
    act->setActionGroup(group3D);
    pannel->addLargeAction(act);
    /* Your code here */
    connect(act, &QAction::triggered, this, [=]() {
        occWidget->stopActionHandler();
        occWidget->detachManipulator();
        MirrorCommand* cmd = new MirrorCommand(occWidget, this);
        connect(cmd, &DesignCommand3D::setDesignInfo, this, [=](QString info){
            entityInfo->setText(info);
        });
    });

    act = new QAction(this);  // 先选择元素，后点击按钮
    act->setText("偏置");
    act->setIcon(QIcon(":/icons/offset.png"));
    act->setActionGroup(group3D);
    pannel->addLargeAction(act);
    /* Your code here */
    connect(act, &QAction::triggered, this, [=]() {
        occWidget->stopActionHandler();
        occWidget->detachManipulator();
        OffsetCommand* cmd = new OffsetCommand(occWidget, this);
        connect(cmd, &DesignCommand3D::setDesignInfo, this, [=](QString info){
            entityInfo->setText(info);
        });
    });
}

void MainWindow::createCategoryControl(SARibbonCategory *page)
{

}

void MainWindow::createCategoryProcess(SARibbonCategory *page)
{
    SARibbonPannel* pannel = page->addPannel("");
    QAction* act = new QAction(this);
    act->setText("导入工件");
    pannel->addLargeAction(act);
}

void MainWindow::createCategoryView(SARibbonCategory *page)
{
    SARibbonPannel* pannel = page->addPannel("");
    QAction* act = new QAction(this);
    pannel->addLargeAction(act);
}

void MainWindow::createCategoryHelp(SARibbonCategory *page)
{
    SARibbonPannel* pannel = page->addPannel("");
    QAction* act = new QAction(this);
    act->setText("About ISPP");
    pannel->addLargeAction(act);
}

void MainWindow::creatOperationDock()
{

}

void MainWindow::on_importModel()
{
    QString modelFileName = QFileDialog::getOpenFileName(this, tr("选择模型文件"), "", "*.step *.STEP *.stp *.STP\n"
        "*.iges *.IGES *.igs *.IGS\n"
        "*.stl *.STL\n"
        "*.brep *.brp");
    if (modelFileName.isEmpty())
        return;

    TCollection_AsciiString theAscii(modelFileName.toUtf8().data());

    QFileInfo info(modelFileName);

    std::shared_ptr<XSControl_Reader> aReader;
    if (info.suffix() == "step" || info.suffix() == "stp" || info.suffix() == "STEP" || info.suffix() == "STP")
    {
        aReader = std::make_shared<STEPControl_Reader>();
    }
    else if (info.suffix() == "iges" || info.suffix() == "igs" || info.suffix() == "IGES" || info.suffix() == "IGS")
    {
        aReader = std::make_shared<IGESControl_Reader>();
    }
    else if (info.suffix() == "stl" || info.suffix() == "STL")
    {
        TopoDS_Shape aShape;
        StlAPI::Read(aShape, theAscii.ToCString());
        Handle(AIS_Shape) anAIS = new AIS_Shape(aShape);
        m_displayedShapes.append(anAIS);
        occWidget->GetContext()->Display(anAIS, false);
        return;
    }
    else if (info.suffix() == "brep" || info.suffix() == "brp")
    {
        TopoDS_Shape aShape;
        BRep_Builder aBuilder;
        BRepTools::Read(aShape, theAscii.ToCString(), aBuilder);
        Handle(AIS_Shape) anAIS = new AIS_Shape(aShape);
        anAIS->Attributes()->SetFaceBoundaryDraw(true);
        anAIS->Attributes()->SetFaceBoundaryAspect(
            new Prs3d_LineAspect(Quantity_NOC_BLACK, Aspect_TOL_SOLID, 1.));
        anAIS->Attributes()->SetIsoOnTriangulation(true);
        m_displayedShapes.append(anAIS);
        occWidget->GetContext()->Display(anAIS, false);
        return;
    }

    if (!aReader->ReadFile(theAscii.ToCString()))
    {
        QMessageBox::critical(this, tr("错误"), tr("模型导入失败!"));
        return;
    }

    for (int i = 0; i < aReader->TransferRoots(); ++i)
    {
        Handle(AIS_Shape) anAIS = new AIS_Shape(aReader->Shape(i + 1));
        anAIS->Attributes()->SetFaceBoundaryDraw(true);
        anAIS->Attributes()->SetFaceBoundaryAspect(
            new Prs3d_LineAspect(Quantity_NOC_BLACK, Aspect_TOL_SOLID, 1.));
        anAIS->Attributes()->SetIsoOnTriangulation(true);
        m_displayedShapes.append(anAIS);
        occWidget->GetContext()->Display(anAIS, false);
    }

    occWidget->GetView()->FitAll();
}

void MainWindow::on_exportModel()
{
    if (m_displayedShapes.isEmpty())
    {
        QMessageBox::information(this, tr("提示"), tr("场景内容为空!"));
        return;
    }

    QString modelFileName = QFileDialog::getSaveFileName(this, tr("选择要保存的位置"), "", "*.step *.STEP *.stp *.STP\n"
        "*.iges *.IGES *.igs *.IGS\n"
        "*.brep");
    if (modelFileName.isEmpty())
        return;

    QFileInfo info(modelFileName);
    TCollection_AsciiString theAscii(modelFileName.toUtf8().data());
    if (info.suffix() == "step" || info.suffix() == "stp" || info.suffix() == "STEP" || info.suffix() == "STP")
    {
        STEPControl_Writer stepWriter;

        for (int i = 0; i < m_displayedShapes.size(); i++)
        {
            Handle(AIS_Shape) anIS = Handle(AIS_Shape)::DownCast(m_displayedShapes.at(i));
            if (anIS.IsNull())
            {
                return;
            }

            if (stepWriter.Transfer(anIS->Shape(), STEPControl_AsIs) != IFSelect_RetDone)
            {
                QMessageBox::critical(this, tr("错误"), tr("模型导出失败!"));
                return;
            }
            if (!stepWriter.Write(theAscii.ToCString()))
            {
                QMessageBox::critical(this, tr("错误"), tr("模型导出失败!"));
                return;
            }
        }
    }
    else if (info.suffix() == "iges" || info.suffix() == "igs" || info.suffix() == "IGES" || info.suffix() == "IGS")
    {
        IGESControl_Writer igesWriter(Interface_Static::CVal("XSTEP.iges.unit"),
            Interface_Static::IVal("XSTEP.iges.writebrep.mode"));
        IGESControl_Controller::Init();
        for (int j = 0; j < m_displayedShapes.size(); j++)
        {
            Handle(AIS_Shape) anIS = Handle(AIS_Shape)::DownCast(m_displayedShapes.at(j));
            if (anIS.IsNull())
            {
                return;
            }
            igesWriter.AddShape(anIS->Shape());
        }

        igesWriter.ComputeModel();
        if (!igesWriter.Write(theAscii.ToCString()))
        {
            QMessageBox::critical(this, tr("错误"), tr("模型导出失败!"));
            return;
        }
    }
    else if (info.suffix() == "brep")
    {
        for (int i = 0; i < m_displayedShapes.size(); i++)
        {
            Handle(AIS_Shape) anIS = Handle(AIS_Shape)::DownCast(m_displayedShapes.at(i));
            if (anIS.IsNull())
            {
                return;
            }

            BRepTools::Write(anIS->Shape(), theAscii.ToCString());
        }
    }
}

void MainWindow::on_exportSelected()
{

}

void MainWindow::on_importRobot()
{

}


void MainWindow::on_emulateRobot()
{

}

void MainWindow::displayRobot()
{

}

void MainWindow::on_displayDelete()
{
    /* Your code here */
    // Display All
    occWidget->GetContext()->DisplayAll(Standard_True);
}

void MainWindow::on_deleteSelected()
{
    /* Your code here */
    // Erase Selected
    occWidget->GetContext()->EraseSelected(Standard_True);
}

void MainWindow::on_setItemColor()
{

}

void MainWindow::onShapeSelected()
{

}

void MainWindow::on_importPath()
{

}

void MainWindow::readPath(std::string fileName){

}
