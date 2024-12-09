#include "Executorimpl.hpp"
#include <memory>
namespace adas{
    const char directions[] = {'N', 'E', 'S', 'W'};
    int GetDirectionIndex(char heading) noexcept
    {
    for (int i = 0; i < 4; ++i) {
        if (heading == directions[i]) {
            return i;
        }
    }
    return -1;  // 如果没有找到，返回 -1，尽管这不应该发生
    }
    Executor* Executor::NewExecutor(const Pose& pose) noexcept
    {
        //返回一个Executorimpl类型的指针
        //std::nothrow确保在内存分配失败时返回nullptr而不是抛出异常
        return new (std::nothrow) Executorimpl(pose);
    }
    // Executorlmpl 构造函数实现
    Executorimpl::Executorimpl(const Pose& pose) noexcept : pose(pose)
    {
        // 任何额外的初始化代码可以放在这里（如果有需要）
    }

    // Executorlmpld的构造函数
    void Executorimpl::Execute(const std::string& commands) noexcept
    {
        // 定义一个方向数组来表示 'N', 'E', 'S', 'W'

        for (const auto cmd:commands)//遍历commands 
        {
            std::unique_ptr<ICommand> cmder;
            if (cmd == 'M')// 前进 
            { 
                cmder = std::make_unique<MoveCommand>();
            } else if (cmd == 'L') {  // 左转
                cmder = std::make_unique<TurnLeftCommand>();

            } else if (cmd == 'R') {  // 右转
                cmder = std::make_unique<TurnRightCommand>();
            }
            else if (cmd=='F')
            {
                cmder=std::make_unique<FastCommand>();
            }
            
            if (cmder) {
                cmder->DoOperate(*this);
            }
        }
    }


    Pose Executorimpl::Query()const noexcept
    {
        return pose;
    }

    void Executorimpl::Move() noexcept{
        if (pose.heading == 'E') {
            ++pose.x;
    }
    else if(pose.heading=='W'){
        --pose.x;
    }
    else if(pose.heading=='N'){
        ++pose.y;
    }
    else if(pose.heading=='S'){
        --pose.y;
    }
    }
    void Executorimpl::Fast()noexcept
    {
        fast=!fast;
    }
    bool Executorimpl::IsFast()const noexcept
    {
        return fast;
    }
    void Executorimpl::TurnLeft() noexcept{
        int current_heading = GetDirectionIndex(pose.heading);
        current_heading = (current_heading - 1 + 4) % 4;
        pose.heading = directions[current_heading];
    }
    void Executorimpl::TurnRight() noexcept{
        int current_heading = GetDirectionIndex(pose.heading);
        current_heading = (current_heading + 1) % 4;
        pose.heading = directions[current_heading];
    }
}
