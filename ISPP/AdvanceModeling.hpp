#ifndef ADVANCEMODELING_H
#define ADVANCEMODELING_H

#include "ModelMaker.hpp"
#include <BRepAlgoAPI_Common.hxx>
#include <BRepAlgoAPI_Fuse.hxx>
#include <BRepAlgoAPI_Cut.hxx>
#include <BRepFilletAPI_MakeFillet.hxx>
#include <BRepFilletAPI_MakeChamfer.hxx>
#include <BRepBuilderAPI_Transform.hxx>
#include <BRepOffset_MakeOffset.hxx>
#include <TopExp_Explorer.hxx>
#include <TopoDS.hxx>
#include <QInputDialog>


class AdvanceModeling
{
public:
    /*****************************************************
     * static Handle(AIS_Shape) bool_operation(int boolType, TopoDS_Shape shape1, TopoDS_Shape shape2)
     * 输入：int boolType 布尔算法类别
     *      TopoDS_Shape shape1 拓扑体
     *      TopoDS_Shape shape2 拓扑体
     *
     * TODO: 对两个拓扑体进行布尔运算。
     * 判断布尔运算类型，根据不同类型选用Fuse、Common、Cut布尔算法。0并, 1交, 2差
     * ***************************************************/
    static Handle(AIS_Shape) bool_operation(int boolType, TopoDS_Shape shape1, TopoDS_Shape shape2) {

        Handle(AIS_Shape) anAisBoolShape;

        // 构造变量指向一个布尔运算
        BRepAlgoAPI_BooleanOperation* boolOp;
        // 根据传入的boolType来判断使用哪种布尔运算
        switch (boolType) {
            case 0: // Fuse操作
                // 输入两个TopoDS_Shape
                // 输出BRepAlgoAPI_BooleanOperation
                boolOp = new BRepAlgoAPI_Fuse(shape1, shape2);
                break;
            case 1: // Common操作
                boolOp = new BRepAlgoAPI_Common(shape1, shape2);
                break;
            case 2: // Cut操作
                boolOp = new BRepAlgoAPI_Cut(shape1, shape2);
                break;
            default:
                // 如果boolType不匹配，则返回一个空的Handle(AIS_Shape)
                return anAisBoolShape;
        }

        // 执行布尔运算
        boolOp->Build();
        if (boolOp->IsDone()) {
            // 获取布尔运算的结果
            // 返回布尔运算得到的TopoDS_Shape
            TopoDS_Shape resultShape = boolOp->Shape();

            // 创建AIS_Shape对象以便可以在图形界面中显示结果
            anAisBoolShape = new AIS_Shape(resultShape);
        }

        // 清理创建的布尔运算对象
        delete boolOp;

        return anAisBoolShape;
    }

    /*****************************************************
     * static Handle(AIS_Shape) chamfer(TopoDS_Shape shape)
     * 输入：TopoDS_Shape shape 拓扑体
     *
     * TODO: 对拓扑体进行倒角。
     * 搜索拓扑体的第三条边，并对其进行倒角处理。
     * ***************************************************/
    static Handle(AIS_Shape) chamfer(TopoDS_Shape shape) {

        Handle(AIS_Shape) anAisChamferShape;

        // 创建倒角对象
        // 初始化用于计算shape上的倒角的算法，输入TopoDS_Shape，输出BRepFilletAPI_MakeChamfer
        BRepFilletAPI_MakeChamfer chamferMaker(shape);

        // 使用TopExp_Explorer遍历边
        TopExp_Explorer explorer(shape, TopAbs_EDGE);
        int edgeCount = 0;
        while (explorer.More()) {
            edgeCount++;
            if (edgeCount == 3) { // 当遍历到第三条边时
                TopoDS_Edge edge = TopoDS::Edge(explorer.Current());
                // 弹出对话框获取用户输入的倒角长度
                bool ok;
                double chamferLength = QInputDialog::getDouble(nullptr, "输入倒角长度", "请输入倒角长度：", 0.0, 0.0, 100.0, 2, &ok);
                if (!ok) {
                    // 用户取消了输入，返回空的AIS_Shape
                    return anAisChamferShape;
                }
                // 对这条边进行倒角处理
                // void BRepFilletAPI_MakeChamfer::Add(const Standard_Real Dis,const TopoDS_Edge &E)
                // Adds edge E to the table of edges used by this algorithm to build chamfers, where the parameters of the chamfer are given by the distance Dis (symmetric chamfer).
                chamferMaker.Add(chamferLength, edge);
                break;
            }
            // 继续查找
            explorer.Next();
        }

            // 检查是否找到第三条边
            if (edgeCount < 3) {
                // 如果拓扑体中的边少于3条，则返回空的AIS_Shape
                return anAisChamferShape;
            }

            // 计算倒角
            chamferMaker.Build();

            if (!chamferMaker.IsDone()) {
                // 如果倒角计算失败，则返回空的AIS_Shape
                return anAisChamferShape;
            }

            // 获取倒角计算后的形状
            TopoDS_Shape chamferedShape = chamferMaker.Shape();

            anAisChamferShape = new AIS_Shape(chamferedShape);

            return anAisChamferShape;
    }

    /*****************************************************
     * static Handle(AIS_Shape) fillet(TopoDS_Shape shape)
     * 输入：TopoDS_Shape shape 拓扑体
     *
     * TODO: 对拓扑体进行圆角。
     * 搜索拓扑体的第一条边，并对其进行圆角处理。
     * ***************************************************/
    static Handle(AIS_Shape) fillet(TopoDS_Shape shape) {

        Handle(AIS_Shape) anAisFilletShape;

        // 初始化圆角计算
        BRepFilletAPI_MakeFillet filletMaker(shape);

        // 使用TopExp_Explorer遍历边
        TopExp_Explorer explorer(shape, TopAbs_EDGE);
        int edgeCount = 0;
        while (explorer.More()) {
            edgeCount++;
            if (edgeCount == 1) { // 当遍历到第一条边时
                TopoDS_Edge edge = TopoDS::Edge(explorer.Current());
                // 弹出对话框获取用户输入的圆角半径
                bool ok;
                double filletRadius = QInputDialog::getDouble(nullptr, "输入圆角半径", "请输入圆角半径：", 0.0, 0.0, 100.0, 2, &ok);
                if (!ok) {
                    // 用户取消了输入，返回空的AIS_Shape
                    return anAisFilletShape;
                }

                // 对这条边进行圆角处理
                // void BRepFilletAPI_MakeFillet::Add(const Standard_Real Radius,const TopoDS_Edge &E)
                filletMaker.Add(filletRadius, edge);
                break;
            }
            explorer.Next();
        }

        // 检查是否找到第一条边
        if (edgeCount < 1) {
            // 如果拓扑体中的边为空，则返回空的AIS_Shape
            return anAisFilletShape;
        }

        // 计算圆角
        filletMaker.Build();

        if (!filletMaker.IsDone()) {
            // 如果圆角计算失败，则返回空的AIS_Shape
            return anAisFilletShape;
        }

        // 获取圆角计算后的形状
        TopoDS_Shape filletedShape = filletMaker.Shape();

        anAisFilletShape = new AIS_Shape(filletedShape);

        return anAisFilletShape;
    }

    /*****************************************************
     * static Handle(AIS_Shape) translate(TopoDS_Shape shape)
     * 输入：TopoDS_Shape shape 任意拓扑图形
     *
     * TODO: 对所选图形进行移动。
     * 取学号后三位作为x坐标创建向量。
     * 用该向量设置平移变换
     * ***************************************************/
    static Handle(AIS_Shape) translate(TopoDS_Shape shape) {

        Handle(AIS_Shape) anAisTranslateShape;

        // 获取学号后三位作为x坐标
        std::string studentID = "2021302835";
        std::string xCoord = studentID.substr(studentID.length() - 3);

        // 将x坐标转换为数值
        double translationDistance = std::stod(xCoord);

        // 创建平移向量
        // gp_Vec::gp_Vec(const Standard_Real theXv,const Standard_Real theYv,const Standard_Real theZv)
        // 输入向量x，y，z三个方向的坐标值
        // 返回 gp_Vec
        gp_Vec translationVector(translationDistance, 0.0, 0.0);

        // 创建平移变换
        gp_Trsf translationTransform;
        // void gp_Trsf::SetTranslation	(const gp_Vec & theV)
        // Replaces the translation vector with the vector theV.
        translationTransform.SetTranslation(translationVector);

        // 对拓扑体进行平移变换
        // BRepBuilderAPI_Transform::BRepBuilderAPI_Transform(const TopoDS_Shape &theShape,const gp_Trsf &theTrsf,const Standard_Boolean theCopyGeom = Standard_False,const Standard_Boolean theCopyMesh = Standard_False)
        // 输入进行平移变换的对象shape和具体平移变换gp_Trsf
        BRepBuilderAPI_Transform shapeTransform(shape, translationTransform);
        // 获取平移变换结果
        TopoDS_Shape translatedShape = shapeTransform.Shape();

        // 创建AIS_Shape对象以便在图形界面中展示平移结果
        anAisTranslateShape = new AIS_Shape(translatedShape);

        return anAisTranslateShape;
    }

    /*****************************************************
     * static Handle(AIS_Shape) rotate(TopoDS_Shape shape)
     * 输入：TopoDS_Shape shape 任意拓扑图形
     *
     * TODO: 对图形进行旋转。
     * 取学号末尾三位数字作为坐标实体从而创建方向D，例：假设学号以123结尾，则坐标实体为（1, 2, 3）。
     * 以全局坐标系原点和方向D创建一个坐标轴，作为旋转时的中心轴。
     * 用该中心轴和任意旋转角度设置旋转变换
     * ***************************************************/
    static Handle(AIS_Shape) rotate(TopoDS_Shape shape) {

        Handle(AIS_Shape) anAisRotateShape;

        // 获取学号末尾三位数字作为坐标实体
        std::string studentID = "2021302835";
        std::string xCoord = studentID.substr(studentID.length() - 3, 1);
        std::string yCoord = studentID.substr(studentID.length() - 2, 1);
        std::string zCoord = studentID.substr(studentID.length() - 1);

        // 将坐标实体转换为数值
        double x = std::stod(xCoord);
        double y = std::stod(yCoord);
        double z = std::stod(zCoord);

        // 创建旋转中心轴
        // gp_Ax1::gp_Ax1(const gp_Pnt &theP,const gp_Dir &theV)
        // 输入出发点gp_Pnt，输入方向gp_Dir
        // 返回gp_Ax1
        gp_Ax1 rotationAxis(gp_Pnt(0.0, 0.0, 0.0), gp_Dir(x, y, z));

        // 弹出对话框获取用户输入的旋转角度
        bool ok;
        double rotationAngle = QInputDialog::getDouble(nullptr, "输入旋转角度", "请输入旋转角度（度）：", 0.0, -360.0, 360.0, 1, &ok);
        if (!ok) {
            // 用户取消了输入，返回空的AIS_Shape
            return anAisRotateShape;
        }

        // 创建旋转变换
        // void gp_Trsf::SetRotation(const gp_Ax1 &theA1,const Standard_Real theAng)
        // Changes the transformation into a rotation. theA1 is the rotation axis and theAng is the angular value of the rotation in radians.
        gp_Trsf rotationTransform;
        rotationTransform.SetRotation(rotationAxis, rotationAngle * M_PI / 180.0);

        // 对拓扑体进行旋转变换
        // 输入：进行旋转变换的对象shape，具体的旋转变换
        // 输出：BRepBuilderAPI_Transform
        BRepBuilderAPI_Transform shapeTransform(shape, rotationTransform);
        TopoDS_Shape rotatedShape = shapeTransform.Shape();

        anAisRotateShape = new AIS_Shape(rotatedShape);

        return anAisRotateShape;
    }

    /*****************************************************
     * static Handle(AIS_Shape) scale(TopoDS_Shape shape)
     * 输入：TopoDS_Shape shape 任意拓扑图形
     *
     * TODO: 对图形进行缩放。
     * 取学号末尾三位数字为坐标创建中心点，例：假设学号以123结尾，则点坐标为（3, 2, 1）。
     * 以该中心点对图形进行缩放，缩放比例用学号末尾三位数字计算，例如：假设学号以abc结尾，则点坐标为(a+b+c)/10.
     * ***************************************************/
    static Handle(AIS_Shape) scale(TopoDS_Shape shape) {

        Handle(AIS_Shape) anAisScaleShape;

        // 获取学号末尾三位数字作为坐标实体
        std::string studentID = "2021302835";
        std::string xCoord = studentID.substr(studentID.length() - 3, 1);
        std::string yCoord = studentID.substr(studentID.length() - 2, 1);
        std::string zCoord = studentID.substr(studentID.length() - 1);

        // 将坐标实体转换为数值
        double x = std::stod(xCoord);
        double y = std::stod(yCoord);
        double z = std::stod(zCoord);

        // 创建缩放中心点
        gp_Pnt centerPoint(x, y, z);

        // 计算缩放比例
        double scaleRatio = (x + y + z) / 10.0;

        // 创建缩放变换
        // void gp_Trsf::SetScale(const gp_Pnt &theP,const Standard_Real theS)
        // Changes the transformation into a scale. theP is the center of the scale and theS is the scaling value. Raises ConstructionError If <theS> is null.
        gp_Trsf scaleTransform;
        scaleTransform.SetScale(centerPoint, scaleRatio);

        // 对拓扑体进行缩放变换
        // 输入：进行缩放变换的对象shape，具体的缩放变换
        // 输出：BRepBuilderAPI_Transform
        BRepBuilderAPI_Transform shapeTransform(shape, scaleTransform);
        TopoDS_Shape scaledShape = shapeTransform.Shape();


        anAisScaleShape = new AIS_Shape(scaledShape);

        return anAisScaleShape;
    }

    /*****************************************************
     * static Handle(AIS_Shape) mirror(TopoDS_Shape shape)
     * 输入：TopoDS_Shape shape 任意拓扑图形
     *
     * TODO: 对图形进行镜像。
     * 取学号末尾三位数字作为坐标实体从而创建方向D，例：假设学号以123结尾，则坐标实体为（2, 1, 3）。
     * 以全局坐标系原点和方向D创建一个坐标轴，作为镜像的对称轴。
     * ***************************************************/
    static Handle(AIS_Shape) mirror(TopoDS_Shape shape) {

        Handle(AIS_Shape) anAisMirrorShape;

        // 获取学号末尾三位数字作为坐标实体
        std::string studentID = "2021302835";
        std::string xCoord = studentID.substr(studentID.length() - 3, 1);
        std::string yCoord = studentID.substr(studentID.length() - 2, 1);
        std::string zCoord = studentID.substr(studentID.length() - 1);

        // 将坐标实体转换为数值
        double x = std::stod(xCoord);
        double y = std::stod(yCoord);
        double z = std::stod(zCoord);

        // 创建方向向量D
        gp_Dir direction(x, y, z);

        // 创建对称轴
        gp_Ax1 mirrorAxis(gp_Pnt(0, 0, 0), direction);

        // 创建镜像变换
        // void gp_Trsf::SetMirror(const gp_Ax1 &theA1)
        // Makes the transformation into a symmetrical transformation. theA1 is the center of the axial symmetry.
        gp_Trsf mirrorTransform;
        mirrorTransform.SetMirror(mirrorAxis);

        // 对拓扑体进行镜像变换
        // 输入：进行镜像变换的对象shape，具体的镜像变换
        // 输出：BRepBuilderAPI_Transform
        BRepBuilderAPI_Transform shapeTransform(shape, mirrorTransform);
        TopoDS_Shape mirroredShape = shapeTransform.Shape();

        // 创建AIS_Shape对象以便在图形界面中展示镜像结果
        anAisMirrorShape = new AIS_Shape(mirroredShape);

        return anAisMirrorShape;
    }

    /*****************************************************
     * static Handle(AIS_Shape) offset(TopoDS_Shape shape)
     * 输入：TopoDS_Shape shape 任意拓扑图形
     *
     * TODO: 对图形进行偏置。
     * 以学号最后两位数字作为偏移量，对图像进行偏移。例：假设学号以23结尾，则偏移量为23。
     * ***************************************************/
    static Handle(AIS_Shape) offset(TopoDS_Shape shape) {

        Handle(AIS_Shape) anAisOffsetShape;

        // 获取学号最后两位数字作为偏移量
        std::string studentID = "2021302835";
        std::string offsetStr = studentID.substr(studentID.length() - 2);

        // 将偏移量转换为数值
        double offset = std::stod(offsetStr);

        // 创建偏移变换
        // void gp_Trsf::SetTranslation(const gp_Vec &theV)
        // Changes the transformation into a translation. theV is the vector of the translation.
        gp_Trsf offsetTransform;
        offsetTransform.SetTranslation(gp_Vec(0, 0, offset));

        // 对拓扑体进行偏移变换
        // 输入：进行偏移变换的对象shape，具体的偏移变换
        // 输出：BRepBuilderAPI_Transform
        BRepBuilderAPI_Transform shapeTransform(shape, offsetTransform);
        TopoDS_Shape offsetShape = shapeTransform.Shape();

        anAisOffsetShape = new AIS_Shape(offsetShape);

        return anAisOffsetShape;
    }
};

#endif // ADVANCEMODELING_H
