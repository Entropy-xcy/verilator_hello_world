all: verilog exe
	./obj_dir/Vmodu

verilog:
	verilator -Wall -cc modu.sv -exe tb.cpp --trace

exe:
	make -C ./obj_dir -j8 -f Vmodu.mk

clean:
	rm -r ./obj_dir
