all:
	cd libs/jsoncpp;python amalgamate.py;cd ../..
	make -f 'DataVisGL/Debug/makefile'
	make -f 'EMWCalc/Debug/makefile'
	mkdir -p 'run'
	cp 'DataVisGL/Debug/DataVisGL' run/
	cp EMWCalc/Debug/EMWCalc run/
	
