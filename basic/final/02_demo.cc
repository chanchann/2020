/*
struct A : Base
{
    virtual void foo() override;
};

A * obj = new A();
a->foo();

其中a->foo()先首先根据a指向的虚表找到foo的函数地址，然后再执行foo函数的调用，因此这里就有一定性能开销，即从vtable中找到foo的地址。

为什么要从vtable中找foo的地址，这里因为A有可能被其它类继承，在子类中覆盖了foo的实现，也即为了实现动态绑定。

思考一个问题，如果明确知道A不会被其它类继承的情况下，是不是可以省掉从vtable中找到foo地址的开销呢？
答案是肯定的，如果明确知道该信息，完全可以将A类型上的调用全部退化成对A上非virtual函数的调用。因此如果一个类或函数声明成final，在编译器层面可以优化掉一步vtable的查找开销，这在C++的标准中并没有规定，完全依赖于编译器的实现。

*/