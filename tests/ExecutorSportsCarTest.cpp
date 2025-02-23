#include <gtest/gtest.h>

#include <memory>

#include "Executor.hpp"
#include "PoseEq.hpp"
namespace adas
{
// 正常状态测试
// M测试
TEST(ExecutorSportsCarTest, should_return_x_minus_2_given_status_is_nomal_command_is_M_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}, CarsType::SportsCar));
    executor->DoCommand("M");
    const Pose target({-2, 0, 'W'});
    ASSERT_EQ(target, executor->Query());
}
// L测试
TEST(ExecutorSportsCarTest, should_return_heading_S_and_y_minus_1_given_status_is_nomal_command_is_L_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}, CarsType::SportsCar));
    executor->DoCommand("L");
    const Pose target({0, -1, 'S'});
    ASSERT_EQ(target, executor->Query());
}
// R测试
TEST(ExecutorSportsCarTest, should_return_heading_N_and_y_plus_1_given_status_is_normal_command_is_R_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}, CarsType::SportsCar));
    executor->DoCommand("R");
    const Pose target({0, 1, 'N'});
    ASSERT_EQ(target, executor->Query());
}
////////////////////////////////////////////////////////////////
// B状态下测试
// M测试
TEST(ExecutorSportsCarTest, should_return_x_plus_2_given_status_is_back_command_is_M_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}, CarsType::SportsCar));
    executor->DoCommand("BM");
    const Pose target({2, 0, 'W'});
    ASSERT_EQ(target, executor->Query());
}
// L测试
TEST(ExecutorSportsCarTest, should_return_heading_N_and_y_minus_1_given_status_is_back_command_is_L_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}, CarsType::SportsCar));
    executor->DoCommand("BL");
    const Pose target({0, -1, 'N'});
    ASSERT_EQ(target, executor->Query());
}
// R测试
TEST(ExecutorSportsCarTest,
     should_return_heading_S_and_y_plus_1_given_status_is_back_and_fast_command_is_R_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}, CarsType::SportsCar));
    executor->DoCommand("BR");
    const Pose target({0, 1, 'S'});
    ASSERT_EQ(target, executor->Query());
}
/////////////////////////////////////////////////////
// F状态下进行测试
// M测试
TEST(ExecutorSportsCarTest, should_return_x_minus_4_given_status_is_fast_command_is_M_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}, CarsType::SportsCar));
    executor->DoCommand("FM");
    const Pose target({-4, 0, 'W'});
    ASSERT_EQ(target, executor->Query());
}
// L测试
TEST(ExecutorSportsCarTest,
     should_return_heading_S_and_x_minus_1_and_y_minus_1_given_status_is_fast_command_is_L_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}, CarsType::SportsCar));
    executor->DoCommand("FL");
    const Pose target({-1, -1, 'S'});
    ASSERT_EQ(target, executor->Query());
}
// R测试
TEST(ExecutorSportsCarTest,
     should_return_heading_N_and_x_minus_1_and_y_plus_1_given_status_is_fast_command_is_R_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}, CarsType::SportsCar));
    executor->DoCommand("FR");
    const Pose target({-1, 1, 'N'});
    ASSERT_EQ(target, executor->Query());
}
///////////////////////////////////////////////////////
// BF状态下进行测试
// M测试
TEST(ExecutorSportsCarTest, should_return_x_plus_4_given_status_is_back_and_fast_command_is_M_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}, CarsType::SportsCar));
    executor->DoCommand("BFM");
    const Pose target({4, 0, 'W'});
    ASSERT_EQ(target, executor->Query());
}
// L测试
TEST(ExecutorSportsCarTest,
     should_return_heading_N_and_x_plus_1_and_y_minus_1_given_status_is_back_and_fast_command_is_L_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}, CarsType::SportsCar));
    executor->DoCommand("BFL");
    const Pose target({1, -1, 'N'});
    ASSERT_EQ(target, executor->Query());
}
// R测试
TEST(ExecutorSportsCarTest,
     should_return_heading_S_and_x_plus_1_and_y_plus_1_given_status_is_back_and_fast_command_is_R_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}, CarsType::SportsCar));
    executor->DoCommand("BFR");
    const Pose target({1, 1, 'S'});
    ASSERT_EQ(target, executor->Query());
}
}  // namespace adas