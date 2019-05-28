#include <stdlib.h>
#include <iostream>
#include "Vmodu.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

int main(int argc, char **argv) {
	// Initialize Verilators variables
    VerilatedVcdC* tfp = NULL;
	Verilated::commandArgs(argc, argv);

	// Create an instance of our module under test
	Vmodu *tb = new Vmodu;
    tb->eval();
    tb->eval();

    vluint64_t time = 0;

    Verilated::traceEverOn(true);
    tfp = new VerilatedVcdC;
    std::string vcdname = argv[0];
    vcdname += ".vcd";
    std::cout << vcdname << std::endl;
    tfp -> open(vcdname.c_str());

	// Tick the clock until we are done
	while(!Verilated::gotFinish()) {
		tb->clk = 1;
		tb->eval();
		tb->clk = 0;
		tb->eval();
        if(tfp != NULL)
        {
            tfp -> dump(time);
        }

        time++;
	} exit(EXIT_SUCCESS);
}
