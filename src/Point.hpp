#pragma once
namespace adas
{
    class Point final{
    public:
    //构造函数
    Point()noexcept=default;//默认构造函数
    Point(const int x,const int y)noexcept;
    Point(const Point&point)noexcept;//拷贝构造函数
    Point& operator=(const Point&point)noexcept;//赋值运算符重载
    Point& operator+=(const Point&point)noexcept;//+=运算符重载
    Point& operator-=(const Point&point)noexcept;//-=运算符重载
    ~Point()noexcept=default;//默认析构函数
    public:
    int GetX(void)const noexcept;//获取x坐标
    int GetY(void)const noexcept;//获取y坐标
    private:
    int x;//x坐标
    int y;//y坐标
    };
}