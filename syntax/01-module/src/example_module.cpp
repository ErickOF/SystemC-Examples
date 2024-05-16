#include <systemc.h>

using namespace sc_core;


/**
 * @brief Construct a new SystemC module with provided macros
 * Method1: Uses SystemC provided SC_MODULE macro
 */
SC_MODULE(ExampleModule1)
{
    /**
     * @brief Default constructor using SC_CTOR macro
     * 
     */
    SC_CTOR(ExampleModule1)
    {
        // name() returns the object name, provided during instanciation
        std::cout << name() << " constructor" << std::endl;
    }
};

/**
 * @brief Construct a new SystemC module as a struct
 * Method2: Uses a struct to create the module in the C++ style
 */
struct ExampleModule2 : public sc_module
{
    /**
     * @brief Default constructor using SC_CTOR macro
     * 
     */
    SC_CTOR(ExampleModule2)
    {
        std::cout << name() << " constructor" << std::endl;
    }
};

/**
 * @brief Construct a new SystemC module as a C++ class
 * Method3: Uses a normal C++ class
 */
class ExampleModule3 : public sc_module
{
public:
    /**
     * @brief Default constructor using SC_CTOR macro
     * 
     */
    SC_CTOR(ExampleModule3)
    {
        std::cout << name() << " constructor" << std::endl;
    }
};


/**
 * @brief SystemC entry point
 * 
 * @param args - number of arguments from CMD
 * @param argv - arguments from CMD
 * @return int - status
 */
int sc_main(int, char*[])
{
    // Instantiate ExampleModule1
    ExampleModule1 example_module1("example_module1");
    // Instantiate ExampleModule2
    ExampleModule2 example_module2("example_module2");
    // Instantiate ExampleModule3
    ExampleModule3 example_module3("example_module3");

    sc_start();

    return 0;
}
