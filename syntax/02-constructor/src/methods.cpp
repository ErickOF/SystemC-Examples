#include <systemc>

using namespace sc_core;


SC_MODULE(Module1)
{
    SC_CTOR(Module1)
    {
        SC_METHOD(method1);
    }

    void method1()
    {
        std::cout << name() << std::endl;
    }
};

SC_MODULE(Module2)
{
    SC_CTOR(Module2)
    {
        SC_METHOD(method2);
    }

    void method2();
};


void Module2::method2()
{
    std::cout << this->name() << std::endl;
}

SC_MODULE(Module3)
{
    const int i;

    SC_CTOR(Module3);
    Module3(sc_module_name name, int i) : sc_module(name), i(i)
    {
        SC_METHOD(method3);
    }

    void method3()
    {
        std::cout << name() << std::endl;
    }
};


int sc_main(int, char*[])
{
    Module1 module1("module1");
    Module2 module2("module2");
    Module3 module3("module3", 3);

    sc_start();

    return 0;
}
