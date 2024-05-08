#include "Robot.h"

#include "RobotLink.h"

Robot::Robot() : RDOF(0)
{
}

Robot::Robot(int dof) : RDOF(dof)
{
}

Robot::~Robot()
{
    for(int i=0;i<RLinks.size();++i) {
        delete RLinks[i];
    }
}

// robot forward kinematic
void Robot::PerformFK(const QVector<double> &angs)
{
    Q_ASSERT(angs.size() == RDOF);


}

void Robot::ComputeTrsfs(const int jointNum, const double dest, const int step)
{

}

gp_Trsf Robot::dhToTrsf(const DHArg &arg, double rad)
{
    gp_Trsf cvt;

    return cvt;
}
