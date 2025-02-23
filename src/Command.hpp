#pragma once 
#include "Executorimpl.hpp"
#include "PoseHandler.hpp"
#include <functional>
namespace adas
{

    class MoveCommand final 
    {
        public:
        void operator()(PoseHandler& poseHandler) const noexcept
        {
            //正常车辆
            if(poseHandler.GetCarsType() == CarsType::Car)
            {//加速状态
            if(poseHandler.IsFast())
            {
                if(poseHandler.IsReverse())
                {
                    poseHandler.BackMove();
                }
                else
                {
                    poseHandler.Move();
                }
            }
            //非加速状态
            if(poseHandler.IsReverse())
            {
                poseHandler.BackMove();
            }
            else{
                poseHandler.Move();
            }
        }
        else if(poseHandler.GetCarsType() == CarsType::SportsCar)
        {
            
                if (!poseHandler.IsReverse() && !poseHandler.IsFast()) {
                    poseHandler.Move();
                    poseHandler.Move();
                } else if (poseHandler.IsReverse() && !poseHandler.IsFast()) {
                    poseHandler.BackMove();
                    poseHandler.BackMove();
                } else if (!poseHandler.IsReverse() && poseHandler.IsFast()) {
                    poseHandler.Move();
                    poseHandler.Move();
                    poseHandler.Move();
                    poseHandler.Move();
                } else if (poseHandler.IsReverse() && poseHandler.IsFast()) {
                    poseHandler.BackMove();
                    poseHandler.BackMove();
                    poseHandler.BackMove();
                    poseHandler.BackMove();
            }
        }
        else
        {
            if (!poseHandler.IsReverse() && !poseHandler.IsFast()) {
                poseHandler.Move();
            } else if (poseHandler.IsReverse() && !poseHandler.IsFast()) {
                poseHandler.BackMove();
            } else if (!poseHandler.IsReverse() && poseHandler.IsFast()) {
                poseHandler.Move();
                poseHandler.Move();
            } else if (poseHandler.IsReverse() && poseHandler.IsFast()) {
                poseHandler.BackMove();
                poseHandler.BackMove();
            }
        }
        }

    };
    class TurnLeftCommand final
    {
    public:
        void operator()(PoseHandler& poseHandler) const noexcept
        {
            if (poseHandler.GetCarsType() == CarsType::SportsCar) {
                if (!poseHandler.IsReverse() && !poseHandler.IsFast()) {
                    poseHandler.TurnLeft();
                    poseHandler.Move();
                } else if (poseHandler.IsReverse() && !poseHandler.IsFast()) {
                    poseHandler.TurnRight();
                    poseHandler.BackMove();
                } else if (!poseHandler.IsReverse() && poseHandler.IsFast()) {
                    poseHandler.Move();
                    poseHandler.TurnLeft();
                    poseHandler.Move();
                } else if (poseHandler.IsReverse() && poseHandler.IsFast()) {
                    poseHandler.BackMove();
                    poseHandler.TurnRight();
                    poseHandler.BackMove();
                }
            } else if (poseHandler.GetCarsType() == CarsType::Bus) {
                if (!poseHandler.IsReverse() && !poseHandler.IsFast()) {
                    poseHandler.Move();
                    poseHandler.TurnLeft();
                } else if (poseHandler.IsReverse() && !poseHandler.IsFast()) {
                    poseHandler.BackMove();
                    poseHandler.TurnRight();
                } else if (!poseHandler.IsReverse() && poseHandler.IsFast()) {
                    poseHandler.Move();
                    poseHandler.Move();
                    poseHandler.TurnLeft();
                } else if (poseHandler.IsReverse() && poseHandler.IsFast()) {
                    poseHandler.BackMove();
                    poseHandler.BackMove();
                    poseHandler.TurnRight();
                }
            }
            // 正常车辆
            else {
                if (poseHandler.IsFast()) {
                    if (poseHandler.IsReverse()) {
                        poseHandler.BackMove();
                    } else {
                        poseHandler.Move();
                    }

                }  // 如果处于加速状态，就再走一格
                if (poseHandler.IsReverse()) {
                    poseHandler.TurnRight();
                } else {
                    poseHandler.TurnLeft();
                }
            }
        };
    };
    class TurnRightCommand final
    {
    public:
        void operator()(PoseHandler& poseHandler) const noexcept
        {
            if (poseHandler.GetCarsType() == CarsType::SportsCar) {
                if (!poseHandler.IsReverse() && !poseHandler.IsFast()) {
                    poseHandler.TurnRight();
                    poseHandler.Move();
                } else if (poseHandler.IsReverse() && !poseHandler.IsFast()) {
                    poseHandler.TurnLeft();
                    poseHandler.BackMove();
                } else if (!poseHandler.IsReverse() && poseHandler.IsFast()) {
                    poseHandler.Move();
                    poseHandler.TurnRight();
                    poseHandler.Move();
                } else if (poseHandler.IsReverse() && poseHandler.IsFast()) {
                    poseHandler.BackMove();
                    poseHandler.TurnLeft();
                    poseHandler.BackMove();
                }
            } else if (poseHandler.GetCarsType() == CarsType::Bus) {
                if (!poseHandler.IsReverse() && !poseHandler.IsFast()) {
                    poseHandler.Move();
                    poseHandler.TurnRight();
                } else if (poseHandler.IsReverse() && !poseHandler.IsFast()) {
                    poseHandler.BackMove();
                    poseHandler.TurnLeft();
                } else if (!poseHandler.IsReverse() && poseHandler.IsFast()) {
                    poseHandler.Move();
                    poseHandler.Move();
                    poseHandler.TurnRight();
                } else if (poseHandler.IsReverse() && poseHandler.IsFast()) {
                    poseHandler.BackMove();
                    poseHandler.BackMove();
                    poseHandler.TurnLeft();
                }
            } else {
                if (poseHandler.IsFast()) {
                    if (poseHandler.IsReverse()) {
                        poseHandler.BackMove();
                    } else {
                        poseHandler.Move();
                    }
                }  // 如果处于加速状态，就再走一格
                if (poseHandler.IsReverse()) {
                    poseHandler.TurnLeft();
                } else {
                    poseHandler.TurnRight();
                }
            }
        };
    };
    class FastCommand final
    {
    public:
        void operator()(PoseHandler& poseHandler) const noexcept
        {
            poseHandler.Fast();
        };
    };
    class ReverseCommand final
    {
    public:
        void operator()(PoseHandler& poseHandler) const noexcept
        {
            poseHandler.Reverse();
        };
    };
}

