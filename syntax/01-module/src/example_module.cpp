#include <systemc.h>

using namespace sc_core;


/**
 * @brief Construct a new SystemC module
 * Uses SystemC provided SC_MODULE macro
 */
SC_MODULE(ExampleModule)
{
    /**
     * @brief Default constructor using SC_CTOR macro
     * 
     */
    SC_CTOR(ExampleModule)
    {
        // name() returns the object name, provided during instanciation
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
    // Instantiate ExampleModule
    ExampleModule example_module("example_module");

    sc_start();

    return 0;
}
