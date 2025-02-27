#pragma once
#include <string>
#include<iostream>
#include<unordered_map>
namespace adas
{
struct Pose {
    int x;
    int y;
    char heading;

    };
    // 汽车类型
    enum class CarsType { Car, SportsCar, Bus };
    extern int CarsLength[3];
    class Executor
    {
    public:
        static Executor* NewExecutor(const Pose& pose = {0, 0, 'N'}, CarsType type = CarsType::Car, int length = CarsLength[0]) noexcept;  // 静态成员函数，用于创建Executor对象

    public:
        Executor(void) = default;                       // 默认构造函数
        virtual ~Executor(void) = default;              // 默认析构函数
        Executor(const Executor&) = delete;             // 禁用拷贝构造函数
        Executor& operator=(const Executor&) = delete;  // 禁用拷贝赋值操作符

    public:
        // virtual void Execute(const std::string& command) noexcept = 0;  // 执行命令
        virtual void DoCommand(const std::string& command) noexcept = 0;
        virtual Pose Query(void) const noexcept = 0;  // 查询当前位置
        virtual int GetCarsLength(void) const noexcept = 0;
};
}  // namespace adas
