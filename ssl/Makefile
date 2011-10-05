
RM = /bin/rm
CAT = /bin/cat
OPENSSL = /usr/bin/openssl


CERTS = root.pem serverCA.pem server.pem client.pem

DHPARAMS = dh512.pem dh1024.pem

all: $(CERTS) $(DHPARAMS) 

$(CERTS): $(CERTS:.pem=.cnf)
	$(OPENSSL) req -newkey rsa:1024 -days 3650 -sha1 -keyout rootkey.pem -out rootreq.pem -config root.cnf
	$(OPENSSL) x509 -req -in rootreq.pem -days 3650 -sha1 -extfile root.cnf -extensions certificate_extensions -signkey rootkey.pem -out rootcert.pem
	$(CAT) rootcert.pem rootkey.pem > root.pem
	$(OPENSSL) req -newkey rsa:1024 -days 3650 -sha1 -keyout serverCAkey.pem -out serverCAreq.pem -config serverCA.cnf
	$(OPENSSL) x509 -req -in serverCAreq.pem -days 3650 -sha1 -extfile serverCA.cnf -extensions certificate_extensions -CA root.pem -CAkey root.pem -CAcreateserial -out serverCAcert.pem
	$(CAT) serverCAcert.pem serverCAkey.pem rootcert.pem > serverCA.pem
	$(OPENSSL) req -newkey rsa:1024 -days 3650 -sha1 -keyout serverkey.pem -out serverreq.pem -config server.cnf -reqexts req_extensions
	$(OPENSSL) x509 -req -in serverreq.pem -days 3650 -sha1 -extfile server.cnf -extensions certificate_extensions -CA serverCA.pem -CAkey serverCA.pem -CAcreateserial -out servercert.pem
	$(CAT) servercert.pem serverkey.pem serverCAcert.pem rootcert.pem > server.pem
	$(OPENSSL) req -newkey rsa:1024 -days 3650 -sha1 -keyout clientkey.pem -out clientreq.pem -config client.cnf -reqexts req_extensions
	$(OPENSSL) x509 -req -in clientreq.pem -days 3650 -sha1 -extfile client.cnf -extensions certificate_extensions -CA root.pem -CAkey root.pem -CAcreateserial -out clientcert.pem
	$(CAT) clientcert.pem clientkey.pem rootcert.pem > client.pem

certclean:
	$(RM) -f rootkey.pem rootreq.pem rootcert.pem root.pem root.srl
	$(RM) -f serverCAkey.pem serverCAreq.pem serverCAcert.pem serverCA.pem serverCA.srl
	$(RM) -f serverkey.pem serverreq.pem servercert.pem server.pem
	$(RM) -f clientkey.pem clientreq.pem clientcert.pem client.pem

dh512.pem:
	$(OPENSSL) dhparam -check -text -5 512 -out dh512.pem

dh1024.pem:
	$(OPENSSL) dhparam -check -text -5 1024 -out dh1024.pem

dhparamclean:
	$(RM) -f $(DHPARAMS)


