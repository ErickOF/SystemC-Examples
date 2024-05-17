#ifndef SYSTEMC_EXAMPLES_COUNTER_HPP
#define SYSTEMC_EXAMPLES_COUNTER_HPP

#include <systemc.h>

using namespace sc_core;


/**
 * @brief Construct a new Counter module object.
 * 
 * Count is only during positive edges of the clock.
 * Reset is only during 1'b0. After reset asserts, it goes out of reset.
 * Enable must be asserted to start the count, otherwise the output will hold
 * latest value.
 * 
 * @tparam N - number of counter bits.
 */
template <int N>
SC_MODULE(Counter)
{
    //------------------------------Module Inputs------------------------------
    // Input clock
    sc_in_clk clk;
    // Reset bar (reset when 1'b0)
    sc_in<bool> rstb;
    // Starts the counter
    sc_in<bool> enable;
    // N-bit output of the counter
    sc_out<sc_uint<N > > count_out;

    //-----------------------------Local Variables-----------------------------
    sc_uint<4> count_int;

public:
    /**
     * @brief Default constructor for Counter.
     */
    SC_CTOR(Counter)
    {
        SC_METHOD(count);
        // Sensitive to the clk posedge to carry out the count
        sensitive << clk.pos();
        // Sensitive to any state change to go in or out of reset
        sensitive << rstb;
    }

    //---------------------------------Methods---------------------------------
    /**
     * @brief Methods that counts in every posedge of the clock, unless rstb is
     * equal to 0, then the output will be always 0. Enable needs to be
     * asserted, otherwise it will show latest value of the counter.
     */
    void count();
};

template <int N>
void Counter<N>::count()
{
    // When in reset state, set counter to 0.
    if (this->rstb.read() == 0)
    {
        this->count_int = 0;
        this->count_out.write(count_int);
    }
    // Count when module is enable
    else if (this->enable.read() == 1)
    {
        this->count_int += 1;
        this->count_out.write(count_int);
    }
}

#endif // SYSTEMC_EXAMPLES_COUNTER_HPP
