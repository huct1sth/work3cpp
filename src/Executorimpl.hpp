#pragma once
#include "PoseHandler.hpp"
#include "Executor.hpp"
#include <functional>//提供函数对象类
//提供Execute和Query的具体实现
namespace adas
{

class Executorimpl final : public Executor//final表示该类不能被其他类继承
{
public:
    explicit Executorimpl(const Pose& pose,CarsType type,int length) noexcept;
    Executorimpl(const Executorimpl&)=delete;
    Executorimpl& operator=(const Executorimpl&)=delete;
    ~Executorimpl() noexcept  = default;
    void DoCommand(const std::string& command)noexcept ;
    Pose Query()const noexcept;
    int GetCarsLength(void)const noexcept ;
private:
    PoseHandler poseHandler;
    CarsType carsType;
    int carsLength;
};
}
