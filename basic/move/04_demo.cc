/*
从性能上讲，左右值引用没有区别，传参使用左右值引用都可以避免拷贝。
右值引用可以直接指向右值，也可以通过std::move指向左值；而左值引用只能指向左值(const左值引用也能指向右值)。
作为函数形参时，右值引用更灵活。虽然const左值引用也可以做到左右值都接受，但它无法修改，有一定局限性
*/

// void f(const int& n) {
//     n += 1; // 编译失败，const左值引用不能修改指向变量
// }

void f2(int && n) {
    n += 1; // ok
}

int main() {
    // f(5);
    f2(5);
}