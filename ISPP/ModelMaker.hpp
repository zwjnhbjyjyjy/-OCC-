#ifndef MODELMAKER_H
#define MODELMAKER_H

#include <BRepPrimAPI_MakeBox.hxx>
#include <BRepPrimAPI_MakeSphere.hxx>
#include <BRepPrimAPI_MakeCylinder.hxx>
#include <BRepPrimAPI_MakeTorus.hxx>
#include <BRepPrimAPI_MakeCone.hxx>
#include <BRepBuilderAPI_MakeEdge.hxx>
#include <BRepBuilderAPI_MakeFace.hxx>
#include <BRepBuilderAPI_MakeWire.hxx>
#include <BRepBuilderAPI_MakeVertex.hxx>
#include <BRep_Builder.hxx>
#include <GeomAPI_Interpolate.hxx>
#include <Geom_BSplineCurve.hxx>
#include <Geom_Circle.hxx>
#include <Geom_Ellipse.hxx>
#include <GeomAPI_PointsToBSpline.hxx>
#include <GC_MakeCircle.hxx>
#include <GC_MakeEllipse.hxx>
#include <GC_MakeSegment.hxx>
#include <gp_Circ.hxx>
#include <gp_Elips.hxx>
#include <AIS_Shape.hxx>
#include <Quantity_Color.hxx>
#include <AIS_Point.hxx>

#include <stdio.h>
#include <QVector>

class ModelMaker
{
// 学号：2021302835
public:
    /*****************************************************x
     * static Handle(AIS_Shape) make_point(gp_Pnt point)
     * 输入：解析几何点 point
     * 输出：一个可交互顶点，类型为 AIS_Shape
     *
     * TODO: 调用OCC类和方法，实现画点
     * ***************************************************/
    static Handle(AIS_Shape) make_point(gp_Pnt point) {

        // 使用解析几何点的坐标创建一个 OCC 顶点对象
        // BRepBuilderAPI_MakeVertex(point) 基于 gp 类下的一个三维点(3D point)创建一个新的顶点(vertex)
        // TopoDS_Vertex::TopoDS_Vertex()
        TopoDS_Vertex vertex = BRepBuilderAPI_MakeVertex(point);

        // 创建一个 AIS_Shape 对象，将 OCC 顶点对象作为参数传入
        Handle(AIS_Shape) anAisPoint = new AIS_Shape(vertex);

        return anAisPoint;
    }

    /*****************************************************x
     * static Handle(AIS_Shape) make_line(gp_Pnt Pnt1, gp_Pnt Pnt2)
     * 输入：端点 Pnt1
     *      端点 Pnt2
     * 输出：一个可交互线段，类型为 AIS_Shape
     *
     * TODO: 调用OCC类和方法，实现画线段
     * 1.取学号倒数第三位数字生成圆颜色：假设学号倒数第三位数字为3，则颜色为
     *   Quantity_Color(0.3, 0.3, 0.3, Quantity_TOC_RGB)
     * ***************************************************/
    static Handle(AIS_Shape) make_line(gp_Pnt Pnt1, gp_Pnt Pnt2) {

        Handle(AIS_Shape) anAisLine;
        // 使用 Pnt1 和 Pnt2 创建 OCC 边对象
        // BRepBuilderAPI_MakeEdge::BRepBuilderAPI_MakeEdge(const gp_Pnt &P1,const gp_Pnt &P2)
        // BRepBuilderAPI_MakeEdge(Pnt1, Pnt2),基于 gp 类下的两个点(3D point)创建一条边(vertex)
        TopoDS_Edge edge = BRepBuilderAPI_MakeEdge(Pnt1, Pnt2);

        // 获取学号倒数第三位数字
        int studentID = 2021302835;
        int digit = (studentID / 100) % 10;

        // 根据学号倒数第三位数字生成颜色
        Standard_Real r = digit / 10.0;
        Standard_Real g = digit / 10.0;
        Standard_Real b = digit / 10.0;
        // Quantity_Color::Quantity_Color(const Standard_Real theC1,const Standard_Real theC2,const Standard_Real theC3,const Quantity_TypeOfColor theType )
        Quantity_Color color(r, g, b, Quantity_TOC_RGB);

        // 创建一个 AIS_Shape 对象，将 OCC 边对象和颜色作为参数传入
        anAisLine = new AIS_Shape(edge);
        anAisLine->SetColor(color);

        return anAisLine;
    }

    /*****************************************************x
     * static Handle(AIS_Shape) make_circle(gp_Pnt p, Standard_Real r)
     * 输入：圆心点 p
     *      圆半径 r
     * 输出：一个可交互圆，类型为 AIS_Shape
     *
     * TODO: 调用OCC类和方法，实现画圆
     * 1.2D绘图以z轴方向作为法向D，3D绘图取学号末尾三位数字作为坐标实体创建法向D，以点p和法向D创建坐标系，
     *   在此坐标系中创建圆，例：假设学号以123结尾，则坐标为（2, 1, 3）
     * 2.取学号倒数第二位数字生成圆颜色：假设学号倒数第二位数字为2，则颜色为
     *   Quantity_Color(0.2, 0.2, 0.2, Quantity_TOC_RGB)
     * ***************************************************/
    static Handle(AIS_Shape) make_circle(gp_Pnt p, Standard_Real r, Standard_Boolean is3D) {

        Handle(AIS_Shape) anAisCircle;

        // 取学号末尾三位数字作为坐标实体创建法向D
        int studentID = 2021302835;  // 我的学号
        int lastThreeDigits = studentID % 1000;
        gp_Dir dir;
        if (is3D) {
            // 3D绘图，使用学号末尾三位数字作为坐标实体创建法向D
            Standard_Real x = (lastThreeDigits / 10) % 10;
            Standard_Real y = (lastThreeDigits / 100) % 10;
            Standard_Real z = lastThreeDigits % 10;
            // gp_Dir::gp_Dir(const Standard_Real theXv,const Standard_Real theYv,const Standard_Real theZv)
            // gp_Dir(x, y, z) 创建具有3个笛卡尔坐标的方向
            dir = gp_Dir(x, y, z);
        } else {
            // 2D绘图，使用z轴方向作为法向D
            dir = gp_Dir(0, 0, 1);
        }

        // 在点p和法向D创建坐标系
        // gp_Ax2::gp_Ax2(const gp_Pnt &P,const gp_Dir &V )
        // ax2(p, dir) 创建具有原点p的坐标系，其中dir给出主方向
        gp_Ax2 ax2(p, dir);

        // 创建圆
        // gp_Circ::gp_Circ	(const gp_Ax2 &theA2,const Standard_Real theRadius )
        gp_Circ circle(ax2, r);

        // 使用 OCC 的 BRepBuilderAPI_MakeEdge 类来创建圆
        BRepBuilderAPI_MakeEdge edgeBuilder(circle);

        // 获取创建的圆弧边
        TopoDS_Edge edge = edgeBuilder.Edge();

        // 使用 OCC 的 BRepBuilderAPI_MakeWire 类来创建线圈
        BRepBuilderAPI_MakeWire wireBuilder(edge);

        // 获取创建的线圈
        //  TopoDS_Wire::TopoDS_Wire()
        TopoDS_Wire wire = wireBuilder.Wire();

        // 使用 OCC 的 BRepBuilderAPI_MakeFace 类来创建面
        // BRepBuilderAPI_MakeFace faceBuilder(wire);

        // 获取创建的面
        // TopoDS_Face face = faceBuilder.Face();

        // 创建一个 AIS_Shape 对象来表示圆
        anAisCircle = new AIS_Shape(wire);

        // 取学号倒数第二位数字生成圆颜色
        int digit = (studentID / 10) % 10;
        Standard_Real red = digit / 10.0;
        Standard_Real green = digit / 10.0;
        Standard_Real blue = digit / 10.0;
        Quantity_Color color(red, green, blue, Quantity_TOC_RGB);
        anAisCircle->SetColor(color);

        return anAisCircle;
    }

    /*****************************************************x
     * static Handle(AIS_Shape) make_elips(gp_Pnt p, Standard_Real r1)
     * 输入：椭圆中心点 p
     *      椭圆长半径 r1
     * 输出：一个可交互椭圆，类型为 AIS_Shape
     *
     * TODO: 调用OCC类和方法，实现画椭圆
     * 1.取学号末位数字a计算椭圆短体半径 r2 = r1 / (a / 5 + 1.5)
     * 2.2D绘图以z轴方向作为法向D，3D绘图取学号末尾三位数字作为坐标实体从而创建法向D，以点p和法向D创建坐标系，
     *   在此坐标系中创建椭圆，例：假设学号以123结尾，则坐标为（2, 3, 1）358
     * 3.取学号末尾位数字生成椭圆颜色：假设学号末尾位数字为3，则颜色为
     *   Quantity_Color(0.3, 0.3, 0.3, Quantity_TOC_RGB)
     * ***************************************************/
    static Handle(AIS_Shape) make_elips(gp_Pnt p, Standard_Real r1, Standard_Boolean is3D) {

        Handle(AIS_Shape) anAisEllips;

        // 取学号末位数字a计算椭圆短体半径
        int studentID = 2021302835;  // 我的学号
        int lastDigit = studentID % 10;
        Standard_Real r2 = r1 / (lastDigit / 5 + 1.5);

        // 取学号末尾三位数字作为坐标实体创建法向D
        int lastThreeDigits = studentID % 1000;
        gp_Dir dir;
        if (is3D) {
            // 3D绘图，使用学号末尾三位数字作为坐标实体创建法向D
            Standard_Real x = (lastThreeDigits / 10) % 10 ;
            Standard_Real y = lastThreeDigits % 10;
            Standard_Real z = (lastThreeDigits / 100) % 10;
            dir = gp_Dir(x, y, z);
        } else {
            // 2D绘图，使用z轴方向作为法向D
            dir = gp_Dir(0, 0, 1);
        }

        // 在点p和法向D创建坐标系
        gp_Ax2 ax2(p, dir);

        // 创建椭圆
        // gp_Elips::gp_Elips(const gp_Ax2 &theA2,const Standard_Real theMajorRadius,const Standard_Real theMinorRadius)
        // 椭圆的大半径在“X轴”上，小半径在椭圆的“Y轴”上。“X轴”由A2的“X方向”定义，“Y轴”由a2的“Y方向”定义
        gp_Elips elips(ax2, r1, r2);

        // 使用 OCC 的 BRepBuilderAPI_MakeEdge 类来创建椭圆弧
        BRepBuilderAPI_MakeEdge edgeBuilder(elips);

        // 获取创建的椭圆弧边
        TopoDS_Edge edge = edgeBuilder.Edge();

        // 使用 OCC 的 BRepBuilderAPI_MakeWire 类来创建线圈
        BRepBuilderAPI_MakeWire wireBuilder(edge);

        // 获取创建的线圈
        TopoDS_Wire wire = wireBuilder.Wire();

        // 使用 OCC 的 BRepBuilderAPI_MakeFace 类来创建面
         BRepBuilderAPI_MakeFace faceBuilder(wire);

        // 获取创建的面
         TopoDS_Face face = faceBuilder.Face();

        // 创建一个 AIS_Shape 对象来表示椭圆
        anAisEllips = new AIS_Shape(edge);

        // 取学号末尾位数字生成椭圆颜色
        int digit = studentID % 10;
        float colorValue = digit / 10.0;
        Quantity_Color color(colorValue, colorValue, colorValue, Quantity_TOC_RGB);
        anAisEllips->SetColor(color);

        return anAisEllips;
    }

    /*****************************************************x
     * static Handle(AIS_Shape) make_BSpline(Handle(TColgp_HArray1OfPnt) aPoints)
     * 输入：控制点数组 Handle(TColgp_HArray1OfPnt) aPoints
     * 输出：一个可交互B样条，类型为 AIS_Shape
     *
     * TODO: 调用OCC类和方法，实现画B样条曲线
     * 1.取学号末尾三位数字生成B样条颜色：假设学号以123结尾，则颜色为
     *   Quantity_Color(0.2, 0.1, 0.3, Quantity_TOC_RGB)
     * ***************************************************/
    static Handle(AIS_Shape) make_BSpline(QVector<gp_Pnt> aPoints) {

        Handle(AIS_Shape) anAisSpline;

        // 获取学号末尾三位数字，并生成B样条曲线的颜色
        int studentID = 2021302835;
        int lastThreeDigits = studentID % 1000;  // 学号末尾三位数字
        double r = ((lastThreeDigits / 10) % 10) / 10.0;
        double g = ((lastThreeDigits / 100) % 10) / 10.0;
        double b = (lastThreeDigits % 10) / 10.0 ;
        Quantity_Color color(r, g, b, Quantity_TOC_RGB);

        // 创建控制点数组
        // TColgp_HArray1OfPnt::TColgp_HArray1OfPnt(const Standard_Integer Low,const Standard_Integer Up)
        Handle(TColgp_HArray1OfPnt) controlPoints = new TColgp_HArray1OfPnt(1, aPoints.size());
        for (int i = 0; i < aPoints.size(); i++) {
            controlPoints->SetValue(i + 1, aPoints[i]);
        }

        // 使用控制点数组创建B样条曲线
        // GeomAPI_Interpolate::GeomAPI_Interpolate	(const Handle<TColgp_HArray1OfPnt> &Points,const Standard_Boolean PeriodicFlag,const Standard_Real Tolerance)
        // 使用函数Load指定切向矢量。如果PeriodicFlag为true，则受约束的B样条曲线将是周期性的且闭合的。在这种情况下，连接点是“点”表的第一个点
        GeomAPI_Interpolate interpolator(controlPoints, Standard_False, 1e-6);
        interpolator.Perform();
        Handle(Geom_BSplineCurve) bsplineCurve = interpolator.Curve();

        // 创建AIS_Shape对象并设置B样条曲线的颜色
        TopoDS_Shape shape = BRepBuilderAPI_MakeEdge(bsplineCurve);
        anAisSpline = new AIS_Shape(shape);
        anAisSpline->SetColor(color);
        return anAisSpline;
    }

    /*****************************************************x
     * static Handle(AIS_Shape) make_box(gp_Pnt Pnt1, gp_Pnt Pnt2)
     * 输入：长方体顶点 Pnt1
     *      Pnt1 对角顶点 Pnt2
     * 输出：一个可交互长方体，类型为 AIS_Shape
     *
     * TODO: 调用OCC类和方法，实现画长方体
     * 1.取学号末尾三位数字生成长方体颜色：假设学号以123结尾，则颜色为
     *   Quantity_Color(0.2, 0.3, 0.1, Quantity_TOC_RGB)358
     * ***************************************************/
    static Handle(AIS_Shape) make_box(gp_Pnt Pnt1, gp_Pnt Pnt2){

        Handle(AIS_Shape) anAisBox;

        // 获取学号末尾三位数字，并生成长方体的颜色
        int studentID = 2021302835;
        int lastThreeDigits = studentID % 1000;  // 学号末尾三位数字
        double r = ((lastThreeDigits / 10) % 10) / 10.0;
        double g = (lastThreeDigits % 10) / 10.0;
        double b =  ((lastThreeDigits / 100) % 10) / 10.0;
        Quantity_Color color(r, g, b, Quantity_TOC_RGB);

        // 创建长方体
        // BRepPrimAPI_MakeBox::BRepPrimAPI_MakeBox(const gp_Pnt &P1,const gp_Pnt &P2 )
        // 通过两点Pnt1和Pnt2创建长方体
        BRepPrimAPI_MakeBox boxMaker(Pnt1, Pnt2);
        TopoDS_Shape boxShape = boxMaker.Shape();

        // 创建 AIS_Shape 对象并设置长方体颜色
        anAisBox = new AIS_Shape(boxShape);
        anAisBox->SetColor(color);

        return anAisBox;
    }

    /*****************************************************x
     * static Handle(AIS_Shape) make_cylinder(gp_Pnt p, Standard_Real H)
     * 输入：圆柱体地面中心点 p
     *      圆柱体高 H
     * 输出：一个可交互圆柱体，类型为 AIS_Shape
     *
     * TODO: 调用OCC类和方法，实现画圆柱体
     * 1.取学号末位数字a计算圆柱体地面半径 R = H / (a + 1)
     * 2.取学号末尾三位数字作为坐标实体从而创建方向D，以点p和方向D创建坐标系，
     *   在此坐标系中创建圆柱体，例：假设学号以123结尾，则坐标为（3, 2, 1）
     * 3.取学号末尾三位数字生成圆柱体颜色：假设学号以123结尾，则颜色为538
     *   Quantity_Color(0.3, 0.2, 0.1, Quantity_TOC_RGB)
     * ***************************************************/
    static Handle(AIS_Shape) make_cylinder(gp_Pnt p, Standard_Real H) {

        Handle(AIS_Shape) anAisCylinder;

        int studentID = 2021302835;

        // 获取学号末位数字a并计算圆柱体地面半径R
        int a = studentID % 10;
        Standard_Real R = H / (a + 1);

        // 获取学号末尾三位数字，并生成长方体的颜色
        int lastThreeDigits = studentID % 1000;
        double r = (lastThreeDigits % 10) / 10.0;
        double g = ((lastThreeDigits / 10) % 10) / 10.0;
        double b = ((lastThreeDigits / 100) % 10) / 10.0;
        Quantity_Color color(r, g, b, Quantity_TOC_RGB);

        // 获取学号末尾三位数字作为坐标实体的值，并创建方向D
        int x = studentID % 10;
        int y = (studentID / 10) % 10;
        int z = (studentID / 100) % 10;
        // gp_Dir::gp_Dir(const Standard_Real theXv,const Standard_Real theYv,const Standard_Real theZv)
        // gp_Dir(x, y, z) 创建具有3个笛卡尔坐标的方向
        gp_Dir D(x, y, z);

        // 使用点p和方向D创建坐标系，并在该坐标系中创建圆柱体
        // gp_Ax2::gp_Ax2(const gp_Pnt &P,const gp_Dir &V )
        // ax2(p, dir) 创建具有原点p的坐标系，其中dir给出主方向
        gp_Ax2 axis(p, D);
        // BRepPrimAPI_MakeCylinder::BRepPrimAPI_MakeCylinder(const gp_Ax2 &Axes,const Standard_Real R,const Standard_Real	H)
        // 绘制一个半径为R、长度为H的圆柱体
        BRepPrimAPI_MakeCylinder cylinderMaker(axis, R, H);
        TopoDS_Shape shape = cylinderMaker.Shape();

        // 创建AIS_Shape对象并设置圆柱体的颜色
        anAisCylinder = new AIS_Shape(shape);
        anAisCylinder->SetColor(color);

        return anAisCylinder;
    }

    /*****************************************************x
     * static Handle(AIS_Shape) make_cone(gp_Pnt p, Standard_Real R)
     * 输入：圆锥体地面中心点 p
     *      圆锥体地面半径 R
     * 输出：一个可交互圆锥体，类型为 AIS_Shape
     *
     * TODO: 调用OCC类和方法，实现画圆锥体
     * 1.取学号末位数字a计算圆锥体高度 H = R1 / (a + 1)
     * 2.取学号末尾三位数字作为坐标实体从而创建方向D，以点p和方向D创建坐标系，
     *   在此坐标系中创建圆锥体，例：假设学号以123结尾，则坐标为（3, 1, 2）
     * 3.取学号末尾三位数字生成圆锥体颜色，例：假设学号以123结尾，则颜色为
     *   Quantity_Color(0.3, 0.1, 0.2, Quantity_TOC_RGB)583
     * ***************************************************/
    static Handle(AIS_Shape) make_cone(gp_Pnt p, Standard_Real R) {

        Handle(AIS_Shape) anAisCone;

        int studentID = 2021302835;

        // 获取学号末位数字a并计算圆锥体地高度H
        int a = studentID % 10;
        Standard_Real H = R / (a + 1);

        // 获取学号末尾三位数字，并生成圆锥体的颜色
        int lastThreeDigits = studentID % 1000;
        double r = (lastThreeDigits % 10) / 10.0;
        double g = ((lastThreeDigits / 100) % 10) / 10.0;
        double b = ((lastThreeDigits / 10) % 10) / 10.0;
        Quantity_Color color(r, g, b, Quantity_TOC_RGB);

        // 获取学号末尾三位数字作为坐标实体的值，并创建方向D
        int x = studentID % 10;
        int y = (studentID / 100) % 10;
        int z = (studentID / 10) % 10;
        // gp_Dir::gp_Dir(const Standard_Real theXv,const Standard_Real theYv,const Standard_Real theZv)
        // gp_Dir(x, y, z) 创建具有3个笛卡尔坐标的方向
        gp_Dir D(x, y, z);

        // 使用点p和方向D创建坐标系，并在该坐标系中创建圆柱体
        // gp_Ax2::gp_Ax2(const gp_Pnt &P,const gp_Dir &V )
        // ax2(p, dir) 创建具有原点p的坐标系，其中dir给出主方向
        gp_Ax2 axis(p, D);
        // RepPrimAPI_MakeCone::BRepPrimAPI_MakeCone(const gp_Ax2 &Axes,const Standard_Real R1,const Standard_Real R2,const Standard_Real H)
        // 参数：axes 圆锥体的构造坐标系； R1 锥底半径，可以为零（z=0）； R2 锥顶半径，可以为零（z=H）； H 锥高度
        BRepPrimAPI_MakeCone coneMaker(axis, R, 0, H);
        TopoDS_Shape shape = coneMaker.Shape();

        // 创建AIS_Shape对象并设置圆锥体的颜色
        anAisCone = new AIS_Shape(shape);
        anAisCone->SetColor(color);

        return anAisCone;
    }

    /*****************************************************x
     * static Handle(AIS_Shape) make_sphere(gp_Pnt center, Standard_Real R)
     * 输入：球体中心点 center
     *      球体半径 R
     * 输出：一个可交互球体，类型为 AIS_Shape
     *
     * TODO: 调用OCC类和方法，实现画球体
     * 1.取学号末尾三位数字生成球体颜色：假设学号以123结尾，则颜色为
     *   Quantity_Color(0.1, 0.3, 0.2, Quantity_TOC_RGB)853
     * ***************************************************/
    static Handle(AIS_Shape) make_sphere(gp_Pnt center, Standard_Real R) {

        Handle(AIS_Shape) anAisSphere;

        int studentID = 2021302835;

        // 获取学号末尾三位数字，并生成球体的颜色
        int lastThreeDigits = studentID % 1000;
        double r = (lastThreeDigits / 100 % 10) / 10.0;
        double g = ((lastThreeDigits) % 10) / 10.0;
        double b = ((lastThreeDigits / 10) % 10) / 10.0;
        Quantity_Color color(r, g, b, Quantity_TOC_RGB);

        // 创建球体形状
        // BRepPrimAPI_MakeSphere::BRepPrimAPI_MakeSphere(const gp_Pnt &Center,const Standard_Real R)
        // parameters: Center [in] sphere center coordinates, R	[in] sphere radius
        BRepPrimAPI_MakeSphere sphereMaker(center, R);
        TopoDS_Shape sphereShape = sphereMaker.Shape();

        // 创建AIS_Shape对象并设置球体的颜色
        anAisSphere = new AIS_Shape(sphereShape);

        // 设置球体颜色
        anAisSphere->SetColor(color);

        return anAisSphere;
    }

    /*****************************************************x
     * static Handle(AIS_Shape) make_torus(gp_Pnt center, Standard_Real R1)
     * 输入：圆环体中心点 center
     *      圆环体中心环半径 R1
     * 输出：一个可交互圆环体，类型为 AIS_Shape
     *
     * TODO: 调用OCC类和方法，实现画圆环体
     * 1.取学号末位数字a计算圆环体截面半径 R2 = R1 / (a + 1)
     * 2.取学号末尾三位数字作为坐标实体从而创建方向D，以点p和方向D创建坐标系，
     *   在此坐标系中创建圆环体，例：假设学号以123结尾，则坐标为（1, 2, 3）
     * 3.取学号末尾三位数字生成圆环体颜色：假设学号以123结尾，则颜色为
     *   Quantity_Color(0.1, 0.2, 0.3, Quantity_TOC_RGB) 835
     * ***************************************************/
    static Handle(AIS_Shape) make_torus(gp_Pnt center, Standard_Real R1) {

        Handle(AIS_Shape) anAisTorus;

        int studentID = 2021302835;

        // 获取学号末位数字a并计算圆环体截面半径
        int a = studentID % 10;
        Standard_Real R2 = R1 / (a + 1);

        // 获取学号末尾三位数字，并生成圆环体的颜色
        int lastThreeDigits = studentID % 1000;
        double r = ((lastThreeDigits / 100) % 10) / 10.0;
        double g = ((lastThreeDigits / 10) % 10) / 10.0;
        double b = (lastThreeDigits % 10) / 10.0;
        Quantity_Color color(r, g, b, Quantity_TOC_RGB);

        // 获取学号末尾三位数字作为坐标实体的值，并创建方向D
        int x = (studentID / 100) % 10;
        int y = (studentID / 10) % 10;
        int z = studentID % 10;
        // gp_Dir::gp_Dir(const Standard_Real theXv,const Standard_Real theYv,const Standard_Real theZv)
        // gp_Dir(x, y, z) 创建具有3个笛卡尔坐标的方向
        gp_Dir D(x, y, z);
        gp_Ax2 axis(center, D);

        // 创建圆环体形状
        // BRepPrimAPI_MakeTorus::BRepPrimAPI_MakeTorus(const gp_Ax2 &Axes,const Standard_Real R1,const Standard_Real R2)
        // parameters: Axes	[in] coordinate system for the construction of the sphere; R1 [in] distance from the center of the pipe to the center of the torus; R2 [in] radius of the pipe
        BRepPrimAPI_MakeTorus torusMaker(axis, R1, R2);
        TopoDS_Shape torusShape = torusMaker.Shape();

        // 创建AIS_Shape对象并设置圆环体的颜色
        anAisTorus = new AIS_Shape(torusShape);
        anAisTorus->SetColor(color);

        return anAisTorus;
    }
};

#endif // MODELMAKER_H
