#pragma once
#include "Executor.hpp"
#include "Direction.hpp"
namespace adas
{
    class PoseHandler final{
public:
    //构造函数
    PoseHandler(const Pose& pose,CarsType carsType)noexcept;
    PoseHandler(const PoseHandler& )=delete;
    PoseHandler& operator=(const PoseHandler& )=delete;
    ~PoseHandler()noexcept=default;
public:
    //其他成员函数
    void Move(void)noexcept;
    void TurnLeft(void)noexcept;
    void TurnRight(void)noexcept;
    void Fast(void)noexcept;//设置加速
    bool IsFast(void)const noexcept;//判断是否加速
    void Reverse(void)noexcept;//设置倒车
    bool IsReverse(void)const noexcept;//判断是否倒车
    void BackMove(void)noexcept;
    Pose Query (void)const noexcept;//查询当前坐标
    CarsType GetCarsType(void)const noexcept;//获取车辆类型

private:
    Point point;
    const Direction* direction;
    bool fast{false};
    bool reverse{false};
    CarsType carsType;
    };
}