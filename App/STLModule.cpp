#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <chrono>
#include "STLModule.h"

using namespace std;
using namespace chrono;

STLModule::STLModule(/* args */)
{
}

STLModule::~STLModule()
{
}

void STLModule::InlineAdd() {
        const int N = 100000000;

    // 测试普通函数
    auto start = high_resolution_clock::now();
    int result1 = 0;
    for (int i = 0; i < N; i++) {
        result1 = add(i, i);
    }
    auto end = high_resolution_clock::now();
    cout << "Normal function time: "
         << duration_cast<milliseconds>(end - start).count() << " ms" << endl;

    // 测试内联函数
    start = high_resolution_clock::now();
    int result2 = 0;
    for (int i = 0; i < N; i++) {
        result2 = addInline(i, i);
    }
    end = high_resolution_clock::now();
    cout << "Inline function time: "
         << duration_cast<milliseconds>(end - start).count() << " ms" << endl;
}
