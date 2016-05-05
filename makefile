.PHONY: run

all:
	make -C DataVisGL/Debug all
	make -C EMWCalc/Debug all
	mkdir -p 'run'
	cp 'DataVisGL/Debug/DataVisGL' run/
	cp EMWCalc/Debug/EMWCalc run/

run:
	@cd run; ./DataVisGL &
	@cd run; ./EMWCalc
	
