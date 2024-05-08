#include "RobotCreator.h"

#include <QFile>
#include <QFileInfo>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include "Robot.h"
#include "RobotLink.h"

#include <QDebug>

RobotCreator::RobotCreator(const QString& jsonPath)
    : myJsonName(jsonPath),
      myInputRobot(nullptr)
{
}

// 执行LoadJson
void RobotCreator::run()
{
    LoadJson(myJsonName);
}

// 解析JSON文件，构建机器人
void RobotCreator::LoadJson(const QString &fileName)
{

}

// 从指定路径导入STEP文件，返回一个AIS_Shape对象
Handle(AIS_Shape) RobotCreator::importSTEP(const QString& str)
{
    Handle(AIS_Shape) shape;

    return shape;
}

// 从指定路径导入IGES文件，返回一个AIS_Shape对象
Handle(AIS_Shape) RobotCreator::importIGES(const QString& str)
{
    Handle(AIS_Shape) shape;

    return shape;

}
