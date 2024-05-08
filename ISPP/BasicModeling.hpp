#ifndef BASICMODELING_H
#define BASICMODELING_H

#include "ModelMaker.hpp"
#include <TopoDS_Shape.hxx>
#include "TopoDS_Edge.hxx"
#include <TopoDS.hxx>
#include <GeomAPI_ExtremaCurveCurve.hxx>
#include <GeomAPI_ProjectPointOnCurve.hxx>
#include <GeomAPI_ProjectPointOnSurf.hxx>
#include <GeomAPI_IntCS.hxx>
#include <AIS_InteractiveContext.hxx>
#include <BRepExtrema_DistShapeShape.hxx>
#include <QVector>

class BasicModeling
{
public:
    /*****************************************************x
     * QVector <gp_Pnt> disperse(TopoDS_Shape shape)
     * 输入：TopoDS_Shape shape 由曲线构成的拓扑边
     * 输出：QVector <gp_Pnt> 一组解析几何点
     *
     * TODO: 对曲线构成的拓扑边进行离散化。
     * 判断拓扑形状是否为边，并在拓扑边上均匀选取A个点，A为学号末两位数。
     * 通过参数化曲线获取边参数取值范围。根据所需取点个数A计算步长。
     * 依照步长依次获取曲线上的点并放入数组中。
     * ***************************************************/
    static QVector <gp_Pnt> disperse(TopoDS_Shape shape) {
        QVector <gp_Pnt> points;

        // 检查形状是否为边
        if (!shape.IsNull() && shape.ShapeType() == TopAbs_EDGE) {
            // 将形状转换为边
            TopoDS_Edge edge = TopoDS::Edge(shape);

            double first, last;
            // BRep_Tool::Curve(const TopoDS_Edge &E, Standard_Real &First, Standard_Real &Last)
            // 输入TopoDS_Edge
            // 输出Geom_Curve，并将curve的起始值和结束值传入到first和last
            Handle(Geom_Curve) curve = BRep_Tool::Curve(edge, first, last);
            // 使用BRep_Tool::Curve函数获取边的参数曲线，同时获取参数范围

            // 根据学号的最后两位数确定需要采样的点数
            const int A = 35;

            if (!curve.IsNull()) {
                // 计算步长
                double step = (last - first) / (A - 1);
                // 步长为参数范围除以点数减一

                for (int i = 0; i < A; ++i) {
                    // 计算曲线上的点的参数值
                    double param = first + i * step;
                    // 确保参数在曲线的定义域内
                    param = std::max(param, first);
                    param = std::min(param, last);

                    // 获取曲线上参数对应的点
                    gp_Pnt pnt = curve->Value(param);
                    // 在尾部插入
                    points.push_back(pnt);
                }
            }
        }

        return points;
    }

    /*****************************************************x
     * QVector <gp_Pnt> get_extrema(TopoDS_Shape shape1, TopoDS_Shape shape2)
     * 输入：TopoDS_Shape shape1 由曲线构成的拓扑边
     *      TopoDS_Shape shape2 由曲线构成的拓扑边
     * 输出：QVector <gp_Pnt> 一组解析几何点
     *
     * TODO: 计算两条拓扑边的最大极值点和最小极值点。
     * 判断两个拓扑形状的类型是否为边，并通过求极值算法计算所有极值点。
     * 从所有极值点找出最大极值点和最小极值点，分别放入数组中。
     * 数组0和1位存放最大极值点，数组2和3位放最小极值点。
     * ***************************************************/
    static QVector <gp_Pnt> get_extrema(TopoDS_Shape shape1, TopoDS_Shape shape2) {

        // 存储两个最大极值点和最小极值点
        QVector<gp_Pnt> points;

        // 验证形状是否为边
        if (shape1.ShapeType() == TopAbs_EDGE && shape2.ShapeType() == TopAbs_EDGE) {
            // 将形状转换为边
            TopoDS_Edge edge1 = TopoDS::Edge(shape1);
            TopoDS_Edge edge2 = TopoDS::Edge(shape2);

            // 获取与边关联的曲线
            // BRep_Tool::Curve(const TopoDS_Edge &E, Standard_Real &First, Standard_Real &Last)
            // 输入TopoDS_Edge
            // 输出Geom_Curve，并将curve的起始值和结束值传入到first和last
            Standard_Real first1, first2, last1, last2;
            Handle(Geom_Curve) curve1 = BRep_Tool::Curve(edge1, first1, last1);
            Handle(Geom_Curve) curve2 = BRep_Tool::Curve(edge2, first2, last2);

            // 使用 GeomAPI_ExtremaCurveCurve 计算两条曲线之间的极值点
            // GeomAPI_ExtremaCurveCurve::GeomAPI_ExtremaCurveCurve(const Handle< Geom_Curve > &C1,const Handle< Geom_Curve > &C2 )
            // 输入两个Geom_Curve
            // 输出GeomAPI_ExtremaCurveCurve
            GeomAPI_ExtremaCurveCurve extrema(curve1, curve2);

            // 用于跟踪极值距离和点的变量
            gp_Pnt maxPoint1, maxPoint2, minPoint1, minPoint2;

            // 本来尝试使用GeomAPI_ExtremaCurveCurve，但发现算出来最大距离和最小距离始终相等（除了直线和圆或椭圆之间）
            // 查阅资料后发现，它计算两条曲线共有的垂直线的起点和终点（交点不是极值，除非两条曲线在此点相切），debug时发现只产生了一对点，导致最大距离和最小距离只与那一对点相关
            // GeomAPI_ExtremaCurveCurve相关的函数也均和求最小距离相关
            // 循环遍历每个极值点，找到最大和最小距离
//            for (Standard_Integer i = 2; i <= numExtrema; i++) {
//                Standard_Real dist = extrema.Distance(i);

//                if (dist > maxDist) {
//                    maxDist = dist;
//                    maxIndex = i;
//                }
//            }

            // 求最大极值点
            // 根据上面的分析，这里使用暴力计算来获取两曲线间的最远距离
            // 但是自己觉得不对劲的地方是好像和极值点失去了关系，但是目前没有想到更合适的解决方法
            // 设置步长
            Standard_Real step = 1;

            // 计算两条曲线的极值点
            for (Standard_Real u1 = first1; u1 <= last1; u1 += step) {
                // 遍历两条曲线上的点比较两点之间的距离获得最大距离
                gp_Pnt point1 = curve1->Value(u1);
                Standard_Real maxDistance = 0;

                for (Standard_Real u2 = first2; u2 <= last2; u2 += step) {
                    gp_Pnt point2 = curve2->Value(u2);
                    Standard_Real distance = point1.Distance(point2);

                    if (distance > maxDistance) {
                        maxDistance = distance;
                        maxPoint1 = point1;
                        maxPoint2 = point2;
                    }
                }
            }


            // 获取极值点
            extrema.TotalNearestPoints(minPoint1, minPoint2);
//            extrema.Points(maxIndex, maxPoint1, maxPoint2);

            // 将极值点赋给 QVector
            points.append(maxPoint1);
            points.append(maxPoint2);
            points.append(minPoint1);
            points.append(minPoint2);
        }

        return points;
    }

    /*****************************************************x
     * QVector <gp_Pnt> project2_curve(TopoDS_Shape shape1, TopoDS_Shape shape2)
     * 输入：TopoDS_Shape shape1 拓扑点/边
     *      TopoDS_Shape shape2 拓扑边/点
     * 输出：QVector <gp_Pnt> 一组解析几何点
     *
     * TODO: 计算拓扑点到拓扑边的投影。
     * 注意：shape1和shape2不一定是拓扑点或拓扑边，需要进行判断。
     * ***************************************************/
    static QVector <gp_Pnt> project2_curve(TopoDS_Shape shape1, TopoDS_Shape shape2) {
        QVector<gp_Pnt> points;

        // 确定边和顶点的形状
        TopoDS_Edge edge;
        gp_Pnt point;

        if (shape1.ShapeType() == TopAbs_EDGE && shape2.ShapeType() == TopAbs_VERTEX) {
            // 将形状转换为边
            // 输入TopoDS_Shape，输出TopoDS_Edge
            edge = TopoDS::Edge(shape1);
            // 将Vertex转换为point
            // static gp_Pnt BRep_Tool::Pnt(const TopoDS_Vertex & V)
            // 输入TopoDS_Vertex， 输出一个3Dpoint
            point = BRep_Tool::Pnt(TopoDS::Vertex(shape2));
        } else if (shape1.ShapeType() == TopAbs_VERTEX && shape2.ShapeType() == TopAbs_EDGE) {
            edge = TopoDS::Edge(shape2);
            point = BRep_Tool::Pnt(TopoDS::Vertex(shape1));
        } else {
            // 处理错误：其中一个形状既不是顶点也不是边
            return points; // 返回一个空向量
        }
        points.append(point);

        // 从边获取曲线
        Standard_Real first, last;
        // BRep_Tool::Curve(const TopoDS_Edge &E, Standard_Real &First, Standard_Real &Last)
        // 输入TopoDS_Edge
        // 输出Geom_Curve，并将curve的起始值和结束值传入到first和last
        Handle(Geom_Curve) curve = BRep_Tool::Curve(edge, first, last);

        // 在曲线上投影点
        // GeomAPI_ProjectPointOnCurve::GeomAPI_ProjectPointOnCurve(const gp_Pnt &P,const Handle< Geom_Curve > &Curve)
        // 输入点和曲线，输出GeomAPI_ProjectPointOnCurve
        GeomAPI_ProjectPointOnCurve projector(point, curve, first, last);

        if (projector.NbPoints() < 0) {
            // 处理错误：投影未成功
            return points; // 返回一个空向量
        } else if (projector.NbPoints() > 0) {
            // 获取投影点并添加到points中
            // gp_Pnt GeomAPI_ProjectPointOnCurve::NearestPoint()
            // 返回在点曲线上最近的正交投影点(Returns the nearest orthogonal projection of the point on the curve)
            const gp_Pnt& projectedPoint = projector.NearestPoint();
            points.append(projectedPoint);
        }

        return points;
    }

    /*****************************************************x
     * QVector <gp_Pnt> project2_face(TopoDS_Shape shape1, TopoDS_Shape shape2)
     * 输入：TopoDS_Shape shape1 拓扑点/面
     *      TopoDS_Shape shape2 拓扑面/点
     * 输出：QVector <gp_Pnt> 一组解析几何点
     *
     * TODO: 计算拓扑点到拓扑面的投影。
     * 注意：shape1和shape2不一定是拓扑点和拓扑面，需要进行判断。
     * ***************************************************/
    static QVector <gp_Pnt> project2_face(TopoDS_Shape shape1, TopoDS_Shape shape2) {
        QVector<gp_Pnt> points;

        // 判断shape1和shape2的类型
        if (shape1.ShapeType() == TopAbs_VERTEX && shape2.ShapeType() == TopAbs_FACE) {
            // shape1是拓扑点，shape2是拓扑面
            TopoDS_Vertex vertex = TopoDS::Vertex(shape1);
            TopoDS_Face face = TopoDS::Face(shape2);

            // 获取拓扑点的坐标
            gp_Pnt point = BRep_Tool::Pnt(vertex);
            points.append(point);

            // 获取拓扑面的几何曲面
            Handle(Geom_Surface) surface = BRep_Tool::Surface(face);

            Extrema_ExtAlgo Algo = Extrema_ExtAlgo_Tree;

            // 创建点到面的投影计算器
            // GeomAPI_ProjectPointOnSurf::GeomAPI_ProjectPointOnSurf(const gp_Pnt &P,const Handle< Geom_Surface > &Surface,const Extrema_ExtAlgo Algo = Extrema_ExtAlgo_Grad)
            // 输入点、表面和Extrema_ExtAlgo
            // 输出GeomAPI_ProjectPointOnSurf
            GeomAPI_ProjectPointOnSurf projector(point, surface, Algo);

            // Standard_Integer GeomAPI_ProjectPointOnSurf::NbPoints()
            // 返回投影点的数目。如果投影失败，返回0。
            if (projector.NbPoints() > 0) {
                for (Standard_Integer i = 1; i <= projector.NbPoints(); i += 1) {
                    // 获取投影点并添加到points中
                    // gp_Pnt GeomAPI_ProjectPointOnSurf::NearestPoint()
                    // 返回距离点最近的投影点
                    const gp_Pnt& projectedPoint = projector.NearestPoint();
                    points.append(projectedPoint);
                }
            }
        } else if (shape1.ShapeType() == TopAbs_FACE && shape2.ShapeType() == TopAbs_VERTEX) {
            // shape1是拓扑面，shape2是拓扑点
            TopoDS_Face face = TopoDS::Face(shape1);
            TopoDS_Vertex vertex = TopoDS::Vertex(shape2);

            // 获取拓扑点的坐标
            gp_Pnt point = BRep_Tool::Pnt(vertex);
            points.append(point);


            // 获取拓扑面的几何曲面
            Handle(Geom_Surface) surface = BRep_Tool::Surface(face);

            Extrema_ExtAlgo Algo = Extrema_ExtAlgo_Tree;

            // 创建点到面的投影计算器
            GeomAPI_ProjectPointOnSurf projector(point, surface, Algo);

            if (projector.NbPoints() > 0) {
                for (Standard_Integer i = 1; i <= projector.NbPoints(); i += 1) {
                    // 获取投影点并添加到points中
                    const gp_Pnt& projectedPoint = projector.NearestPoint();
                    points.append(projectedPoint);
                }

            }
        }

        return points;
    }

    /*****************************************************x
     * void selection_activate(int selectionType, Handle(AIS_InteractiveContext) context)
     * 输入：int selectionType 模型选择类别
     *      Handle(AIS_InteractiveContext) context 一个AIS_InteractiveContext
     *
     * TODO: 针对所有可见模型切换选择模式。
     * 禁用所有已激活选择模式，根据输入的模型选择类别激活选择模式。
     * 模型选择类别数值参考MainWindow.cpp中重置选择、选择点、选择边、选择面、选择实体按钮代码。
     * ***************************************************/
    static void selection_activate(int selectionType, Handle(AIS_InteractiveContext) context) {
        context->Deactivate();

        //        switch (selectionType) {
        //                case 0: // 重置选择
        //                    context->Activate(selectionType, TopAbs_SHAPE);
        //                    break;
        //                case 1: // 选择点
        //                    context->Activate(selectionType, TopAbs_VERTEX);
        //                    break;
        //                case 2: // 选择边
        //                    context->Activate(selectionType, TopAbs_EDGE);
        //                    break;
        //                case 4: // 选择面
        //                    context->Activate(selectionType, TopAbs_FACE);
        //                    break;
        //                case 6: // 选择实体
        //                    context->Activate(selectionType, TopAbs_SOLID);
        //                    break;
        //                default:
        //                    break;
        //        }
        // 激活所有显示对象的给定选择模式
        // void AIS_InteractiveContext::Activate(const Standard_Integer theMode,const Standard_Boolean theIsForce = Standard_False )
        context->Activate(selectionType, Standard_True);

    }

};

#endif // BASICMODELING_H
