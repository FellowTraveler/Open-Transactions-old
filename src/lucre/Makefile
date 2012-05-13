APPS=bankdemo banktest bank-new coin-request bank-sign coin-unblind \
	bank-verify banktest2

all: depend $(APPS)

INCFLAGS=-I../../openssl/include -DBN_DEBUG -DREF_CHECK -DCRYPTO_MDEBUG -DPEDANTIC
#CFLAGS=-g $(INCFLAGS) -O2 -pedantic -Wall -Wshadow -Werror -pipe
CFLAGS=-g $(INCFLAGS) -O2 -Wall -Wshadow -Werror -pipe

LFLAGS=-L../../openssl -lcrypto

depend:
	touch .depend
	makedepend -f .depend $(INCFLAGS) -I/usr/include/g++ *.cpp

banktest: banktest.o bankimp.o
	$(CXX) $(CFLAGS) -o banktest banktest.o bankimp.o $(LFLAGS)

banktest2: banktest2.o bankimp.o
	$(CXX) $(CFLAGS) -o banktest2 banktest2.o bankimp.o $(LFLAGS)

bank-new: bank-new.o bankimp.o
	$(CXX) $(CFLAGS) -o bank-new bank-new.o bankimp.o $(LFLAGS)

coin-request: coin-request.o bankimp.o
	$(CXX) $(CFLAGS) -o coin-request coin-request.o bankimp.o $(LFLAGS)

bank-sign: bank-sign.o bankimp.o
	$(CXX) $(CFLAGS) -o bank-sign bank-sign.o bankimp.o $(LFLAGS)

coin-unblind: coin-unblind.o bankimp.o
	$(CXX) $(CFLAGS) -o coin-unblind coin-unblind.o bankimp.o $(LFLAGS)

bank-verify: bank-verify.o bankimp.o
	$(CXX) $(CFLAGS) -o bank-verify bank-verify.o bankimp.o $(LFLAGS)

bankdemo: bankdemo.o
	$(CXX) $(CFLAGS) -o bankdemo bankdemo.o $(LFLAGS)

test: test-bank test-coin

test-coin: all
	./coin-request /tmp/bank-public /tmp/coin-private /tmp/coin-request
	./bank-sign /tmp/bank-private /tmp/coin-request /tmp/coin-signature
	./coin-unblind /tmp/bank-public /tmp/coin-private /tmp/coin-signature /tmp/coin
	./bank-verify /tmp/bank-private /tmp/coin

test-bank: all
	./bank-new 288 /tmp/bank-private /tmp/bank-public

clean:
	rm -f *.o $(APPS) *~ .depend .depend.bak *.core

tar: clean
	tar cvfz /home/ben/tmp/bank.tgz .
