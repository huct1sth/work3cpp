#pragma once
#include "Executor.hpp"
//提供Execute和Query的具体实现
namespace adas
{

class Executorimpl final : public Executor//final表示该类不能被其他类继承
{
public:
    //构造函数 初始化Pose
    explicit Executorimpl(const Pose& pose) noexcept;//explicit表示只能用显式构造函数
    
    ~Executorimpl() noexcept = default;//默认析构函数

    // 禁用拷贝构造函数和拷贝赋值操作符
    Executorimpl(const Executorimpl&) = delete;
    Executorimpl& operator=(const Executorimpl&) = delete;

public:
    void Execute(const std::string& command) noexcept override;//重写且不抛出异常
    Pose Query(void) const noexcept override;

private:
    Pose pose;
    void Move(void) noexcept;
    void TurnLeft(void) noexcept;
    void TurnRight(void) noexcept;
    void Fast(void)noexcept;
    bool IsFast(void) const noexcept;
    bool fast{false};
    class ICommand
    {
        public:
        virtual ~ICommand() =default;
        virtual void DoOperate(Executorimpl& executor) const noexcept =0;
    };
    class FastCommand final:public ICommand{
        public:
        void DoOperate(Executorimpl& executor) const noexcept override{
            executor.Fast();
        }
    };
    class MoveCommand final:public ICommand{
        public:
        void DoOperate(Executorimpl& executor) const noexcept override{
            if(executor.IsFast()){
                executor.Move();
                }
            executor.Move();
    }
    };
    class TurnLeftCommand final:public ICommand{
        public:
        void DoOperate(Executorimpl& executor) const noexcept override{
            if(executor.IsFast()){
                executor.Move();
            }
            executor.TurnLeft();
        }
    };
    class TurnRightCommand final:public ICommand
    {
    public:
        void DoOperate(Executorimpl& executor) const noexcept override
        {
            if(executor.IsFast()){
                executor.Move();
            }
            executor.TurnRight();
        }
    };
};

}  
