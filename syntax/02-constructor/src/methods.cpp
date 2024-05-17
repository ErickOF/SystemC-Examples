#include <systemc>

using namespace sc_core;


/**
 * @brief Class for Module1
 */
SC_MODULE(Module1)
{
    /**
     * @brief Constructor takes by default only the name of the module
     */
    SC_CTOR(Module1)
    {
        // SC_METHOD registers a new method to SystemC simulation kernel
        SC_METHOD(method1);
    }

    /**
     * @brief Method has no parameters (inputs) and returns (outputs)
     */
    void method1()
    {
        std::cout << name() << std::endl;
    }
};

/**
 * @brief Class for Module2
 */
SC_MODULE(Module2)
{
    SC_CTOR(Module2)
    {
        SC_METHOD(method2);
    }

    /**
     * @brief Method is only declared
     * 
     */
    void method2();
};

/**
 * @brief Method is defined outside of the class definition
 * 
 */
void Module2::method2()
{
    std::cout << this->name() << std::endl;
}

/**
 * @brief Class for Module3
 */
SC_MODULE(Module3)
{
    const int i;

    SC_CTOR(Module3);
    /**
     * @brief Construct takes more arguments
     * 
     * @param name - default module name
     * @param i - additional argument
     */
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
