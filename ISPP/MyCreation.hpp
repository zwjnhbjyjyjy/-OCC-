#ifndef MYCREATION_H
#define MYCREATION_H

#include "OccWidget.h"
#include "ModelMaker.hpp"
#include "AdvanceModeling.hpp"
#include "BasicModeling.hpp"
#include "ModelMaker.hpp"
#include <Geom_BezierCurve.hxx>
#include <GeomAPI_ExtremaCurveCurve.hxx>
#include <GeomAPI_ProjectPointOnCurve.hxx>
#include <Geom_Plane.hxx>
#include <Geom_CylindricalSurface.hxx>
#include <Geom2d_Ellipse.hxx>
#include <Geom2d_TrimmedCurve.hxx>
#include <GCE2d_MakeSegment.hxx>
#include <GC_MakeArcOfCircle.hxx>
#include <BRepBuilderAPI_MakeWire.hxx>
#include <BRepBuilderAPI_MakeFace.hxx>
#include <BRepPrimAPI_MakePrism.hxx>
#include <BRepAlgoAPI_Common.hxx>
#include <BRepAlgoAPI_Fuse.hxx>
#include <BRepAlgoAPI_Cut.hxx>
#include <BRepFilletAPI_MakeFillet.hxx>
#include <BRepFilletAPI_MakeChamfer.hxx>
#include <BRepBuilderAPI_Transform.hxx>
#include <BRepOffset_MakeOffset.hxx>
#include <BRepOffsetAPI_MakeThickSolid.hxx>
#include <BRepOffsetAPI_ThruSections.hxx>
#include <BRepOffsetAPI_MakePipe.hxx>
#include <BRepLib.hxx>
#include <TopExp_Explorer.hxx>
#include <TopoDS.hxx>
#include <math.h>

// 姓名：赵文婕
// 学号：2021302835

class MyCreation
{
public:
    static TopoDS_Shape MyDesign()
    {
        // TODO: 设计你的图形

        TopoDS_Shape aRes;

        // 定义插线板长方体的尺寸
        Standard_Real powerStripHeight = 20.0;
        Standard_Real powerStripWidth = 80.0;
        Standard_Real powerStripLength = 200.0;
        gp_Pnt powerStripCorner1(0, 0, 0);
        gp_Pnt powerStripCorner2(powerStripLength, powerStripWidth, powerStripHeight); // 长200mm，宽80mm，高20mm
        Handle(AIS_Shape) powerStripBox = ModelMaker::make_box(powerStripCorner1, powerStripCorner2);
        TopoDS_Shape powerStripShape = powerStripBox->Shape();

        // 对长方体进行圆角处理
        // 初始化圆角计算
        BRepFilletAPI_MakeFillet filletMaker(powerStripShape);

        // 使用TopExp_Explorer遍历边
        // 由于AdvanceModeling中的圆角只能计算第一条边，这里不调用该模块中的函数
        TopExp_Explorer explorer(powerStripShape, TopAbs_EDGE);
        int edgeCount = 0;
        while (explorer.More()) {
            edgeCount++;
            if (edgeCount == 1 || edgeCount == 3 || edgeCount == 5 || edgeCount == 7) { // 当遍历到为高的边时
                TopoDS_Edge edge = TopoDS::Edge(explorer.Current());
                // 圆角半径
                double filletRadius = 10.0;
                // 对这条边进行圆角处理
                // void BRepFilletAPI_MakeFillet::Add(const Standard_Real Radius,const TopoDS_Edge &E)
                filletMaker.Add(filletRadius, edge);
            }
            if (edgeCount == 8){
                break;
            }
            explorer.Next();
        }
        // 计算圆角
        filletMaker.Build();
        powerStripShape = filletMaker.Shape();


        // 第一排插孔
        // 定义插孔的参数
        const Standard_Real socketRadius = 2.5; // 插孔半径为2.5mm
        const Standard_Real socketDepth = 8;  // 插孔深度为8mm，稍大于插线板高度以确保完全穿透
        gp_Ax2 socketAxis1, socketAxis2;
        TopoDS_Shape socketShape1, socketShape2;
        // 减去四个双头插座的的半圆部分
        for (int i = 1; i <= 4; ++i)
        {
            socketAxis1 = gp_Ax2(gp_Pnt(14+40*(i-1), 15, 0), gp_Dir(0, 0, 1)); // 每个插孔的间距为40mm
            BRepPrimAPI_MakeCylinder socketMaker1(socketAxis1, socketRadius, socketDepth, M_PI);

            socketAxis2 = gp_Ax2(gp_Pnt(31+40*(i-1), 15, 0), gp_Dir(0, 0, 1)); // 每个插孔的间距为40mm
            BRepPrimAPI_MakeCylinder socketMaker2(socketAxis2, socketRadius, socketDepth, M_PI);

            socketShape1 = socketMaker1.Shape();
            socketShape2 = socketMaker2.Shape();

            // 调整半圆柱的长方形面部分朝向
            gp_Ax1 rotationAxis1(gp_Pnt(12+40*(i-1), 15, 0), gp_Dir(0, 0, 1));
            gp_Trsf rotationTransform1;
            rotationTransform1.SetRotation(rotationAxis1, 90 * M_PI / 180.0);
            BRepBuilderAPI_Transform shapeTransform1(socketShape1, rotationTransform1);
            socketShape1 = shapeTransform1.Shape();

            gp_Ax1 rotationAxis2(gp_Pnt(31+40*(i-1), 15, 0), gp_Dir(0, 0, 1));
            gp_Trsf rotationTransform2;
            rotationTransform2.SetRotation(rotationAxis2, -90 * M_PI / 180.0);
            BRepBuilderAPI_Transform shapeTransform2(socketShape2, rotationTransform2);
            socketShape2 = shapeTransform2.Shape();

            gp_Vec translationVector(0.0, 2.0, 0.0);
            // 创建平移变换
            gp_Trsf translationTransform;
            translationTransform.SetTranslation(translationVector);
            BRepBuilderAPI_Transform shapeTransform(socketShape2, translationTransform);
            // 获取平移变换结果
            socketShape2 = shapeTransform.Shape();

            powerStripShape = BRepAlgoAPI_Cut(powerStripShape, socketShape1).Shape();
            powerStripShape = BRepAlgoAPI_Cut(powerStripShape, socketShape2).Shape();
        }
        // 减去四个双头插座的的长方体不部分
        for (int i = 1; i <= 4; ++i)
        {
            // 定义双头插座的的长方体部分的尺寸
            gp_Pnt box1_1(12+40*(i-1), 14, 0);
            gp_Pnt box2_1(12+40*(i-1)+1, 20, 8);
            Handle(AIS_Shape) socketBox1 = ModelMaker::make_box(box1_1, box2_1);
            TopoDS_Shape socketBoxShape1 = socketBox1->Shape();

            // 定义双头插座的的长方体的尺寸
            gp_Pnt box1_2(31+40*(i-1), 14, 0);
            gp_Pnt box2_2(31+40*(i-1)+1, 20, 8);
            Handle(AIS_Shape) socketBox2 = ModelMaker::make_box(box1_2, box2_2);
            TopoDS_Shape socketBoxShape2 = socketBox2->Shape();

            powerStripShape = BRepAlgoAPI_Cut(powerStripShape, socketBoxShape1).Shape();
            powerStripShape = BRepAlgoAPI_Cut(powerStripShape, socketBoxShape2).Shape();
        }


        // 第二排插孔
        const Standard_Real socketRadius_2 = 2.5; // 插孔半径为2.5mm
        const Standard_Real socketDepth_2 = 8;  // 插孔深度为8mm，稍大于插线板高度以确保完全穿透
        gp_Ax2 socketAxis1_2, socketAxis2_2;
        TopoDS_Shape socketShape1_2, socketShape2_2;
        // 减去四个双头插座的的半圆部分
        for (int i = 1; i <= 4; ++i)
        {
            socketAxis1_2 = gp_Ax2(gp_Pnt(14+40*(i-1), 40, 0), gp_Dir(0, 0, 1)); // 每个插孔的间距为40mm
            BRepPrimAPI_MakeCylinder socketMaker1_2(socketAxis1_2, socketRadius_2, socketDepth_2, M_PI);

            socketAxis2_2 = gp_Ax2(gp_Pnt(31+40*(i-1), 40, 0), gp_Dir(0, 0, 1)); // 每个插孔的间距为40mm
            BRepPrimAPI_MakeCylinder socketMaker2_2(socketAxis2_2, socketRadius_2, socketDepth_2, M_PI);

            socketShape1 = socketMaker1_2.Shape();
            socketShape2 = socketMaker2_2.Shape();

            gp_Ax1 rotationAxis1_2(gp_Pnt(12+40*(i-1), 40, 0), gp_Dir(0, 0, 1));
            gp_Trsf rotationTransform1_2;
            rotationTransform1_2.SetRotation(rotationAxis1_2, 90 * M_PI / 180.0);
            BRepBuilderAPI_Transform shapeTransform1_2(socketShape1, rotationTransform1_2);
            socketShape1_2 = shapeTransform1_2.Shape();

            gp_Ax1 rotationAxis2_2(gp_Pnt(31+40*(i-1), 40, 0), gp_Dir(0, 0, 1));
            gp_Trsf rotationTransform2_2;
            rotationTransform2_2.SetRotation(rotationAxis2_2, -90 * M_PI / 180.0);
            BRepBuilderAPI_Transform shapeTransform2_2(socketShape2, rotationTransform2_2);
            socketShape2 = shapeTransform2_2.Shape();
            gp_Vec translationVector_2(0.0, 2.0, 0.0);
            // 创建平移变换
            gp_Trsf translationTransform_2;
            translationTransform_2.SetTranslation(translationVector_2);
            BRepBuilderAPI_Transform shapeTransform(socketShape2, translationTransform_2);
            // 获取平移变换结果
            socketShape2_2 = shapeTransform.Shape();

            powerStripShape = BRepAlgoAPI_Cut(powerStripShape, socketShape1_2).Shape();
            powerStripShape = BRepAlgoAPI_Cut(powerStripShape, socketShape2_2).Shape();
        }
        // 减去四个双头插座的的长方体
        for (int i = 1; i <= 4; ++i)
        {
            // 定义双头插座的的长方体的尺寸
            gp_Pnt box1_1_2(12+40*(i-1), 39, 0);
            gp_Pnt box2_1_2(12+40*(i-1)+1, 45, 8);
            Handle(AIS_Shape) socketBox1_2 = ModelMaker::make_box(box1_1_2, box2_1_2);
            TopoDS_Shape socketBoxShape1_2 = socketBox1_2->Shape();

            // 定义双头插座的的长方体的尺寸
            gp_Pnt box1_2_2(31+40*(i-1), 39, 0);
            gp_Pnt box2_2_2(31+40*(i-1)+1, 45, 8);
            Handle(AIS_Shape) socketBox2_2 = ModelMaker::make_box(box1_2_2, box2_2_2);
            TopoDS_Shape socketBoxShape2_2 = socketBox2_2->Shape();

            powerStripShape = BRepAlgoAPI_Cut(powerStripShape, socketBoxShape1_2).Shape();
            powerStripShape = BRepAlgoAPI_Cut(powerStripShape, socketBoxShape2_2).Shape();
        }


        // 三头插座
        // 减去三头插座的最上方的长方体
        for (int i = 1; i <= 4; ++i)
        {
            // 定义三头插座的最上方的长方体的尺寸
            gp_Pnt box3_1(21.5+40*(i-1), 39, 0);
            gp_Pnt box3_2(22.5+40*(i-1)+1, 45, 8);
            Handle(AIS_Shape) socketBox3 = ModelMaker::make_box(box3_1, box3_2);
            TopoDS_Shape socketBoxShape3 = socketBox3->Shape();

            powerStripShape = BRepAlgoAPI_Cut(powerStripShape, socketBoxShape3).Shape();
        }
        // 减去三头插座下方两个长方体
        for (int i = 1; i <= 4; ++i)
        {
            // 定义三头插座的最上方的长方体的尺寸
            gp_Pnt box3_1_1(12.5+40*(i-1), 58, 0);
            gp_Pnt box3_2_1(13.5+40*(i-1)+1, 64, 8);
            Handle(AIS_Shape) socketBox3_1 = ModelMaker::make_box(box3_1_1, box3_2_1);
            TopoDS_Shape socketBoxShape3_1 = socketBox3_1->Shape();

            // 调整长方体角度
            gp_Ax1 rotationAxis1(gp_Pnt(13.5+40*(i-1), 58, 0), gp_Dir(0, 0, 1));
            gp_Trsf rotationTransform1;
            rotationTransform1.SetRotation(rotationAxis1, -40 * M_PI / 180.0);
            BRepBuilderAPI_Transform shapeTransform1(socketBoxShape3_1, rotationTransform1);
            socketBoxShape3_1 = shapeTransform1.Shape();

            // 定义三头插座的最上方的长方体的尺寸
            gp_Pnt box3_1_2(30.5+40*(i-1), 58, 0);
            gp_Pnt box3_2_2(31.5+40*(i-1)+1, 64, 8);
            Handle(AIS_Shape) socketBox3_2 = ModelMaker::make_box(box3_1_2, box3_2_2);
            TopoDS_Shape socketBoxShape3_2 = socketBox3_2->Shape();

            // 调整长方体角度
            gp_Ax1 rotationAxis2(gp_Pnt(30.5+40*(i-1), 58, 0), gp_Dir(0, 0, 1));
            gp_Trsf rotationTransform2;
            rotationTransform2.SetRotation(rotationAxis2, 40 * M_PI / 180.0);
            BRepBuilderAPI_Transform shapeTransform2(socketBoxShape3_2, rotationTransform2);
            socketBoxShape3_2 = shapeTransform2.Shape();


            powerStripShape = BRepAlgoAPI_Cut(powerStripShape, socketBoxShape3_1).Shape();
            powerStripShape = BRepAlgoAPI_Cut(powerStripShape, socketBoxShape3_2).Shape();

        }


        // 绘制按钮
        // 创建按钮位置空间
        gp_Pnt buttonCorner1(173, 30, -2);
        gp_Pnt buttonCorner2(187, 50, 5);
        BRepPrimAPI_MakeBox buttonBox(buttonCorner1, buttonCorner2);
        TopoDS_Shape buttonShape = buttonBox.Shape();

        // 可以选择为按钮添加倒角
        BRepFilletAPI_MakeChamfer buttonChamferMaker(buttonShape);
        TopExp_Explorer buttonExplorer(buttonShape, TopAbs_EDGE);
        while (buttonExplorer.More()) {
            TopoDS_Edge buttonEdge = TopoDS::Edge(buttonExplorer.Current());
            // 假设所有边缘的倒角长度为1.5mm
            buttonChamferMaker.Add(1.50, buttonEdge);
            buttonExplorer.Next();
        }
        buttonChamferMaker.Build();
        buttonShape = buttonChamferMaker.Shape();

        // 在插线板上得到按钮空间
        powerStripShape = BRepAlgoAPI_Cut(powerStripShape, buttonShape).Shape();

        // 添加按钮
        gp_Pnt buttonCorner3(173.5, 30.5, -1);
        gp_Pnt buttonCorner4(186.5, 49.5, 5);
        BRepPrimAPI_MakeBox buttonBox2(buttonCorner3, buttonCorner4);
        TopoDS_Shape buttonShape2 = buttonBox2.Shape();

        // 可以选择为按钮添加圆角
        BRepFilletAPI_MakeFillet buttonFilletMaker2(buttonShape2);
        TopExp_Explorer buttonExplorer2(buttonShape2, TopAbs_EDGE);
        while (buttonExplorer2.More()) {
            TopoDS_Edge buttonEdge2 = TopoDS::Edge(buttonExplorer2.Current());
            // 假设所有边缘的圆角半径为1mm
            buttonFilletMaker2.Add(1.50, buttonEdge2);
            buttonExplorer2.Next();
        }
        buttonFilletMaker2.Build();
        buttonShape2 = buttonFilletMaker2.Shape();

        // 在插线板上添加按钮
        powerStripShape = BRepAlgoAPI_Fuse(powerStripShape, buttonShape).Shape();

        // 添加开关标志
        gp_Pnt center(180, 40, -2);
        const Standard_Real R1 = 2.5;
        const Standard_Real R2 = 0.5;
        gp_Dir D(0, 0, 1);
        gp_Ax2 axis(center, D);

        // 创建圆环体形状，由于ModelMaker模块中指定了圆环体的截面半径、圆环半径，这里不调用模块中的函数
        // BRepPrimAPI_MakeTorus::BRepPrimAPI_MakeTorus(const gp_Ax2 &Axes,const Standard_Real R1,const Standard_Real R2)
        // parameters: Axes	[in] coordinate system for the construction of the sphere; R1 [in] distance from the center of the pipe to the center of the torus; R2 [in] radius of the pipe
        BRepPrimAPI_MakeTorus torusMaker(axis, R1, R2);
        TopoDS_Shape torusShape = torusMaker.Shape();
        powerStripShape = BRepAlgoAPI_Cut(powerStripShape, torusShape).Shape();

        // 创建长方体形状
        gp_Pnt rectangle1(175.5, 39.75, -2);
        gp_Pnt rectangle2(179, 40.25, -1.5);
        BRepPrimAPI_MakeBox rectangleBox2(rectangle1, rectangle2);
        TopoDS_Shape rectangleShape2 = rectangleBox2.Shape();
        powerStripShape = BRepAlgoAPI_Cut(powerStripShape, rectangleBox2).Shape();


        // 绘制插线板接线柱部分
        // 定义接线柱的尺寸和位置参数
        const Standard_Real terminalRadius = 5.0; // 接线柱的半径为5mm
        const Standard_Real terminalHeight = 10.0; // 接线柱的高度为10mm
        const Standard_Real terminalPositionX = 200.0; // 接线柱距离插线板一端的位置（X坐标）
        const Standard_Real terminalPositionY = 40.0; // 接线柱位于插线板宽度中央（Y坐标）
        const Standard_Real terminalPositionZ = 10.0; // 接线柱位于插线板高度中央（Y坐标）

        // 创建接线柱的形状
        gp_Ax2 terminalAxis(gp_Pnt(terminalPositionX, terminalPositionY, terminalPositionZ), gp_Dir(1, 0, 0)); // 接线柱的中心线在插线板表面之上
        BRepPrimAPI_MakeCylinder terminalMaker(terminalAxis, terminalRadius, terminalHeight);
        TopoDS_Shape terminalShape = terminalMaker.Shape();

        // 将接线柱形状添加到插线板上
        powerStripShape = BRepAlgoAPI_Fuse(powerStripShape, terminalShape).Shape();

        // 螺纹：创建表面
        Handle(Geom_CylindricalSurface) aCyl1 = new Geom_CylindricalSurface(terminalAxis, terminalRadius * 0.99);
        Handle(Geom_CylindricalSurface) aCyl2 = new Geom_CylindricalSurface(terminalAxis, terminalRadius * 1.05);
        // 螺纹：定义二维曲线
        gp_Pnt2d aPnt(2. * M_PI, terminalHeight / 2.);
        gp_Dir2d aDir(2. * M_PI, terminalHeight / 4.);
        gp_Ax2d anAx2d(aPnt, aDir);
        Standard_Real aMajor = 2. * M_PI;
        Standard_Real aMinor = terminalHeight / 10;
        Handle(Geom2d_Ellipse) anEllipse1 = new Geom2d_Ellipse(anAx2d, aMajor, aMinor);
        Handle(Geom2d_Ellipse) anEllipse2 = new Geom2d_Ellipse(anAx2d, aMajor, aMinor / 4);
        Handle(Geom2d_TrimmedCurve) anArc1 = new Geom2d_TrimmedCurve(anEllipse1, 0, M_PI);
        Handle(Geom2d_TrimmedCurve) anArc2 = new Geom2d_TrimmedCurve(anEllipse2, 0, M_PI);
        gp_Pnt2d anEllipsePnt1 = anEllipse1->Value(0);
        gp_Pnt2d anEllipsePnt2 = anEllipse1->Value(M_PI);
        Handle(Geom2d_TrimmedCurve) aSegment = GCE2d_MakeSegment(anEllipsePnt1, anEllipsePnt2);
        // 螺纹：创建边和线
        TopoDS_Edge anEdge1OnSurf1 = BRepBuilderAPI_MakeEdge(anArc1, aCyl1);
        TopoDS_Edge anEdge2OnSurf1 = BRepBuilderAPI_MakeEdge(aSegment, aCyl1);
        TopoDS_Edge anEdge1OnSurf2 = BRepBuilderAPI_MakeEdge(anArc2, aCyl2);
        TopoDS_Edge anEdge2OnSurf2 = BRepBuilderAPI_MakeEdge(aSegment, aCyl2);
        TopoDS_Wire threadingWire1 = BRepBuilderAPI_MakeWire(anEdge1OnSurf1, anEdge2OnSurf1);
        TopoDS_Wire threadingWire2 = BRepBuilderAPI_MakeWire(anEdge1OnSurf2, anEdge2OnSurf2);
        BRepLib::BuildCurves3d(threadingWire1);
        BRepLib::BuildCurves3d(threadingWire2);
        // 构建螺纹
        BRepOffsetAPI_ThruSections aTool(Standard_True);
        aTool.AddWire(threadingWire1);
        aTool.AddWire(threadingWire2);
        aTool.CheckCompatibility(Standard_False);
        TopoDS_Shape myThreading = aTool.Shape();
        powerStripShape = BRepAlgoAPI_Fuse(powerStripShape, myThreading).Shape();


//        // 本来想利用样条曲线绘制插线板的接线部分，但由于控制点和样条曲线的关系没整明白，暂时放弃
//        // 定义电线路径的控制点
//        QVector<gp_Pnt> aPoints;
//        aPoints.append(gp_Pnt(terminalPositionX+terminalHeight, terminalPositionY, terminalPositionZ));
//        aPoints.append(gp_Pnt(211, 41, 10));
//        aPoints.append(gp_Pnt(212, 42, 10));
//        aPoints.append(gp_Pnt(213, 43, 10));

//        // 创建B曲线作为电线路径
//        Handle(TColgp_HArray1OfPnt) controlPoints = new TColgp_HArray1OfPnt(1, aPoints.size());
//        for (int i = 0; i < aPoints.size(); i++) {
//            controlPoints->SetValue(i + 1, aPoints[i]);
//        }
//        GeomAPI_Interpolate interpolator(controlPoints, Standard_False, 1e-6);
//        interpolator.Perform();
//        Handle(Geom_BSplineCurve) bsplineCurve = interpolator.Curve();

//        TopoDS_Edge bsplineEdge = BRepBuilderAPI_MakeEdge(bsplineCurve);
//        TopoDS_Wire bsplineWire = BRepBuilderAPI_MakeWire(bsplineEdge).Wire();

//        // 定义电线的圆形截面
//        const Standard_Real wireRadius = 1.0; // 电线半径为1mm
//        Handle(Geom_Circle) wireSection = new Geom_Circle(gp_Ax2(gp::Origin(), gp::DZ()), wireRadius);
//        TopoDS_Edge wireEdge = BRepBuilderAPI_MakeEdge(wireSection);
//        TopoDS_Wire wire = BRepBuilderAPI_MakeWire(wireEdge).Wire();
//        TopoDS_Shape shape = BRepBuilderAPI_MakeFace(wire).Shape();

//        // 沿着路径扫描截面以创建电线
//        BRepOffsetAPI_MakePipe wireMaker(bsplineWire, shape);
//        wireMaker.Build();
//        TopoDS_Shape wireShape = wireMaker.Shape();

//        // 将电线形状添加到插线板模型上
//        powerStripShape = BRepAlgoAPI_Fuse(powerStripShape, wireShape).Shape();



        // 插头设计
        gp_Pnt plugCorner1(9, -15, -10); // 紧挨着插线板一侧
        gp_Pnt plugCorner2(35, 25, -45); // 插头长26mm，宽35mm，高25mm
        BRepPrimAPI_MakeBox plugBox(plugCorner1, plugCorner2);
        TopoDS_Shape plugShape = plugBox.Shape();
        // 对长方体进行圆角处理
        // 初始化圆角计算
        BRepFilletAPI_MakeFillet filletMakerPlug(plugShape);

        // 使用TopExp_Explorer遍历边
        // 由于AdvanceModeling中的圆角只能计算第一条边，这里不调用该模块中的函数
        TopExp_Explorer explorerPlug(plugShape, TopAbs_EDGE);
        int edgeCountPlug = 0;
        while (explorerPlug.More()) {
            edgeCountPlug++;
            if (edgeCountPlug == 1 || edgeCountPlug == 3 || edgeCountPlug == 5 || edgeCountPlug == 7) { // 当遍历到为高的边时
                TopoDS_Edge edgePlug = TopoDS::Edge(explorerPlug.Current());
                // 圆角半径
                double filletRadiusPlug = 5.0;
                // 对这条边进行圆角处理
                // void BRepFilletAPI_MakeFillet::Add(const Standard_Real Radius,const TopoDS_Edge &E)
                filletMakerPlug.Add(filletRadiusPlug, edgePlug);
            }
            if (edgeCountPlug == 8){
                break;
            }
            explorerPlug.Next();
        }
        // 计算圆角
        filletMakerPlug.Build();
        plugShape = filletMakerPlug.Shape();

        // 创建两个长方体作为插头的接触点
        // 定义双头插座的的长方体的尺寸
        gp_Pnt plugpnt1_1(12, 14.5, -10);
        gp_Pnt plugpnt2_1(12+1, 19.5,0);
        BRepPrimAPI_MakeBox plugBox1(plugpnt1_1, plugpnt2_1);
        TopoDS_Shape plugBoxShape1 = plugBox1.Shape();

        // 定义双头插座的的长方体的尺寸
        gp_Pnt plugpnt1_2(31, 14.5, -10);
        gp_Pnt plugpnt2_2(31+1, 19.5, 0);
        BRepPrimAPI_MakeBox plugBox2(plugpnt1_2, plugpnt2_2);
        TopoDS_Shape plugBoxShape2 = plugBox2.Shape();

        // 将接触点添加到插头
        plugShape = BRepAlgoAPI_Fuse(plugShape, plugBoxShape1).Shape();
        plugShape = BRepAlgoAPI_Fuse(plugShape, plugBoxShape2).Shape();

        // 最后，将插头融合到插线板
        powerStripShape = BRepAlgoAPI_Fuse(powerStripShape, plugShape).Shape();


        // 返回最终结果
        aRes = powerStripShape;
        return aRes;
    }
};

#endif // MYCREATION_H
