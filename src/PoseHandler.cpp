#include "PoseHandler.hpp"
namespace adas
{
PoseHandler::PoseHandler(const Pose& pose,CarsType type)noexcept:point(pose.x,pose.y),direction(&Direction::GetDirection(pose.heading)),carsType(type)
{
    
}
void PoseHandler::BackMove(void)noexcept
{
    point-=direction->Move();
}
void PoseHandler::Move() noexcept
{
    point+=direction->Move();
}
void PoseHandler::TurnLeft() noexcept
{
    direction=&(direction->DirectionLeft());
}
void PoseHandler::TurnRight() noexcept
{
    direction=&(direction->DirectionRight());
}
Pose PoseHandler::Query()const noexcept
{
    return Pose{point.GetX(),point.GetY(),direction->GetHeading()};
}
void PoseHandler::Fast()noexcept
{
    fast=!fast;
}
bool PoseHandler::IsFast()const noexcept
{
    return fast;
}
void PoseHandler::Reverse()noexcept//设置倒车
{
    reverse=!reverse;
}
bool PoseHandler::IsReverse()const noexcept//判断是否倒车
{
    return reverse;
}
CarsType PoseHandler::GetCarsType()const noexcept
{
    return carsType;
}
}