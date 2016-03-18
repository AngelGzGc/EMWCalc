
DIRLIBS = all/
 

.PHONY: dirs clean jsoncpp

all: dirs jsoncpp

clean:
	rm -rf $(DIRLIBS)/sources/*
	rm -rf $(DIRLIBS)/includes/*
	
dirs:
	@mkdir -p $(DIRLIBS)
	@mkdir -p $(DIRLIBS)/includes
	@mkdir -p $(DIRLIBS)/sources

jsoncpp: $(shell find jsoncpp -type f)
	@mkdir -p $(DIRLIBS)/includes/json
	cd jsoncpp; python amalgamate.py; cd ..
	cp jsoncpp/dist/json/*.h $(DIRLIBS)/includes/json/
	cp jsoncpp/dist/jsoncpp.cpp $(DIRLIBS)/sources


	
