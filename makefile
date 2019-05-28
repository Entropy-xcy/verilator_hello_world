verilog:
	verilator -Wall -cc modu.sv -exe tb.cpp --trace

exe:
	make -C ./obj_dir -j -f Vmodu.mk

clean:
	rm -r ./obj_dir