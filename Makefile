all:
	cd OTLib && make
	cd transaction && make
	cd testwallet && make -f Makefile.testwallet

clean:
	cd OTLib && make clean
	cd transaction && make clean
	cd testwallet && make -f Makefile.testwallet clean
