#include <iostream>
#include <vector>

class STLModule
{
private:
    /* data */
public:
    STLModule(/* args */);
    ~STLModule();
    void InlineAdd();
    // 普通函数
int add(int a, int b) {
    return a + b;
}

// 内联函数
inline int addInline(int a, int b) {
    return a + b;
}

};


