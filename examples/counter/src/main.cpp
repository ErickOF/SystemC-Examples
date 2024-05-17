#include <systemc.h>

#include "counter.hpp"

using namespace sc_core;

#define N_SIZE 4
#define CLK_PERIOD SC_NS


int sc_main(int, char*[])
{
    // Signal to drive DUT inputs and get outputs
    sc_signal<bool> clk;
    sc_signal<bool> rstb;
    sc_signal<bool> enable;
    sc_signal<sc_uint<N_SIZE> > count_out;

    // Connect the DUT
    Counter<N_SIZE> counter("counter");
    counter.clk(clk);
    counter.rstb(rstb);
    counter.enable(enable);
    counter.count_out(count_out);

    sc_start(0.5, CLK_PERIOD);

    // Open VCD file
    sc_trace_file *wf = sc_create_vcd_trace_file("counter");

    // Dump the desired signals
    sc_trace(wf, clk, "clk");
    sc_trace(wf, rstb, "rstb");
    sc_trace(wf, enable, "enable");
    sc_trace(wf, count_out, "count");

    // Initialize all variables
    clk = 0;
    rstb = 0;
    enable = 0;

    // Test if it is not couting since it is in reset
    for (size_t i = 0; i < 10; ++i)
    {
        clk = !clk;
        sc_start(0.5, CLK_PERIOD);
    }

    // Going out of reset
    rstb = 1;

    // Test if it is not couting since it is not enabled
    for (size_t i = 0; i < 10; ++i)
    {
        clk = !clk;
        sc_start(0.5, CLK_PERIOD);
    }

    // Enable module
    enable = 1;

    // Test if it is couting
    for (size_t i = 0; i < 10; ++i)
    {
        clk = !clk;
        sc_start(0.5, CLK_PERIOD);
    }

    return 0;
}

