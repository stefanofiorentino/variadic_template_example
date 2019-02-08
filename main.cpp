#include <iostream>

// https://eli.thegreenplace.net/2014/variadic-templates-in-c/

template<typename T>
T adder(T v)
{
    std::puts(__PRETTY_FUNCTION__);
    return v;
}

template<typename T, typename... Args>
auto adder(T first, Args... args) -> decltype(first + adder(args...))
{
    std::puts(__PRETTY_FUNCTION__);
    return first + adder(args...);
}

// mod starts here
template<typename T, typename T2>
auto adder(T first, T2 second) -> decltype(first+second)
{
    std::puts(__PRETTY_FUNCTION__);
    return first + second;
}

template<typename T, typename T2, typename... Args>
auto adder(T first, T2 second, Args... args) -> decltype(first+second)
{
    std::puts(__PRETTY_FUNCTION__);
    return first + second + adder(args...);
}

int main()
{
    auto sum = adder(1, 2.f, 3, 8, 7);

    std::string s1 = "x", s2 = "aa", s3 = "bb", s4 = "yy";
    auto ssum = adder("aa", s2, s3, s4, "zz");
    adder(s1, s2, s3, s4);
    std::cout << std::to_string(sum) << ", " << ssum << std::endl;
    return 0;
}