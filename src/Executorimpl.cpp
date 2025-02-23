#include "Executorimpl.hpp"
#include <memory>
#include <unordered_map>
#include "Command.hpp"
namespace adas
{
int CarsLength[3] = {1, 1, 2};  // 车的长度

Executor* Executor::NewExecutor(const Pose& pose, CarsType type, int length) noexcept
{
    if (type == CarsType::Car)
        length = CarsLength[0];
    if (type == CarsType::SportsCar)
        length = CarsLength[1];
    if (type == CarsType::Bus)
        length = CarsLength[2];
    // 返回一个Executorimpl类型的指针
    // std::nothrow确保在内存分配失败时返回nullptr而不是抛出异常
    return new (std::nothrow) Executorimpl(pose,type,length);  // 不会抛异常的new操作符
}
// Executorlmpl 构造函数实现
Executorimpl::Executorimpl(const Pose& pose,CarsType type,int length) noexcept : poseHandler(pose,type),carsType(type),carsLength(length)
{
    // 任何额外的初始化代码可以放在这里（如果有需要）
}

// Executorlmpld的构造函数
void Executorimpl::DoCommand(const std::string& commands) noexcept
{
    const std::unordered_map<char, std::function<void(PoseHandler & poseHandler)>> commandMap{
        {'M', MoveCommand()},       // 将命令'M'和对应的命令对象MoveCommand插入到unordered_map中
        {'L', TurnLeftCommand()},   // 将命令'L'和对应的命令对象TurnLeftCommand插入到unordered_map中
        {'R', TurnRightCommand()},  // 将命令'R'和对应的命令对象TurnRightCommand插入到unordered_map中
        {'F', FastCommand()},       // 将命令'F'和对应的命令对象FastCommand插入到unordered_map中
        {'B', ReverseCommand()}      // 将命令'B'和对应的命令对象ReverseCommand插入到unordered_map中
    };
    // 定义一个方向数组来表示 'N', 'E', 'S', 'W'
    for (const auto cmd : commands)  // 遍历commands
    {
        const auto it = commandMap.find(cmd);
        if (it != commandMap.end()) {
            it->second(poseHandler);
        }
    }
}

Pose Executorimpl::Query(void) const noexcept
{
    return poseHandler.Query();
}
int Executorimpl::GetCarsLength(void)const noexcept
{
    return carsLength;
}
}  // namespace adas
