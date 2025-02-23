#include <gtest/gtest.h>

#include <memory>

#include "Executor.hpp"
#include "PoseEq.hpp"
namespace adas
{
// 正常状态测试
// M测试
TEST(ExecutorBusTest, should_return_x_minus_1_given_status_is_nomal_command_is_M_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}, CarsType::Bus));
    executor->DoCommand("M");
    const Pose target({-1, 0, 'W'});
    ASSERT_EQ(target, executor->Query());
}
// L测试
TEST(ExecutorBusTest, should_return_heading_S_and_x_minus_1_given_status_is_nomal_command_is_L_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}, CarsType::Bus));
    executor->DoCommand("L");
    const Pose target({-1, 0, 'S'});
    ASSERT_EQ(target, executor->Query());
}
// R测试
TEST(ExecutorBusTest, should_return_heading_N_and_x_minus_1_given_status_is_normal_command_is_R_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}, CarsType::Bus));
    executor->DoCommand("R");
    const Pose target({-1, 0, 'N'});
    ASSERT_EQ(target, executor->Query());
}
////////////////////////////////////////////////////////////////
// B状态下测试
// M测试
TEST(ExecutorBusTest, should_return_x_plus_1_given_status_is_back_command_is_M_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}, CarsType::Bus));
    executor->DoCommand("BM");
    const Pose target({1, 0, 'W'});
    ASSERT_EQ(target, executor->Query());
}
// L测试
TEST(ExecutorBusTest, should_return_heading_N_and_x_plus_1_given_status_is_back_command_is_L_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}, CarsType::Bus));
    executor->DoCommand("BL");
    const Pose target({1, 0, 'N'});
    ASSERT_EQ(target, executor->Query());
}
// R测试
TEST(ExecutorBusTest, should_return_heading_S_and_x_plus_1_given_status_is_back_and_fast_command_is_R_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}, CarsType::Bus));
    executor->DoCommand("BR");
    const Pose target({1, 0, 'S'});
    ASSERT_EQ(target, executor->Query());
}
/////////////////////////////////////////////////////
// F状态下进行测试
// M测试
TEST(ExecutorBusTest, should_return_x_minus_2_given_status_is_fast_command_is_M_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}, CarsType::Bus));
    executor->DoCommand("FM");
    const Pose target({-2, 0, 'W'});
    ASSERT_EQ(target, executor->Query());
}
// L测试
TEST(ExecutorBusTest, should_return_heading_S_and_x_minus_2_given_status_is_fast_command_is_L_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}, CarsType::Bus));
    executor->DoCommand("FL");
    const Pose target({-2, 0, 'S'});
    ASSERT_EQ(target, executor->Query());
}
// R测试
TEST(ExecutorBusTest, should_return_heading_N_and_x_minus_2_given_status_is_fast_command_is_R_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}, CarsType::Bus));
    executor->DoCommand("FR");
    const Pose target({-2, 0, 'N'});
    ASSERT_EQ(target, executor->Query());
}
///////////////////////////////////////////////////////
// BF状态下进行测试
// M测试
TEST(ExecutorBusTest, should_return_x_plus_2_given_status_is_back_and_fast_command_is_M_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}, CarsType::Bus));
    executor->DoCommand("BFM");
    const Pose target({2, 0, 'W'});
    ASSERT_EQ(target, executor->Query());
}
// L测试
TEST(ExecutorBusTest, should_return_heading_N_and_x_plus_2_given_status_is_back_and_fast_command_is_L_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}, CarsType::Bus));
    executor->DoCommand("BFL");
    const Pose target({2, 0, 'N'});
    ASSERT_EQ(target, executor->Query());
}
// R测试
TEST(ExecutorBusTest, should_return_heading_S_and_x_plus_2_given_status_is_back_and_fast_command_is_R_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}, CarsType::Bus));
    executor->DoCommand("BFR");
    const Pose target({2, 0, 'S'});
    ASSERT_EQ(target, executor->Query());
}
}  // namespace adas