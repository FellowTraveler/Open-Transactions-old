
To build the command-line test client:   

make -f Makefile.testwallet

The output will be an executable called "testwallet.exe".
Run it from this directory like so: ./testwallet.exe 

------------------------------------------

To build the static library for the C++ high-level interface:

make -f Makefile.CPP_API

The output will be a static library called libOTAPI.a

#include "OpenTransactions.h" in whatever C++ project you want to use,

and make sure you statically link to libOTAPI.a

------------------------------------------



NOTE: THE JAVA PORTION HAS ONLY BEEN TESTING ON MAC

A Windows Makefile is not yet available, nor one for Linux.
But anyone who actually downloaded this project should have
no problems getting it working.


To build the dynamic library for the Java JNI interface:

1) First, make sure you build the C++ interface, since the JNI wraps it:
make -f Makefile.CPP_API

2) Then compile the java file:
javac OpenTransactionsJNI.java; 

3) Then build the JNI C++ wrapper class:
make -f Makefile.JNI_API

---

The output from make will be a file called libOT_JNI_API.jnilib
(This actually contains the C++ native code, but wrapped into a library
that Java can use.)

The output from javac will be a file called OpenTransactionsJNI.class
(This contains the actual built version of the Java class.)

---

To run the JNI interface from the command line, type this:
java OpenTransactionsJNI

(It contains a main function, so you can run it.)

---

Running it will load up OpenTransactionsJNI.class, which contains a main 
function. When main() runs, it will call loadLibrary("OT_JNI_API") which 
will load up the libOT_JNI_API.jnilib into memory.

From here on out, any calls to the OpenTransactionsJNI methods in the
java code will be passed through and executed by the C++ code in the
library.

The test main() in OpenTransactionsJNI.java doesn't do much. It just loads
the jnilib, then loads the wallet file, then connects to the server.

(The main function ends at this point.)

---

If you want to create a new C++ header for the JNI interface (if you have
been hacking the java class) then be sure to also do this:

javah -jni OpenTransactionsJNI

(javah is ONLY necessary if you hacked the java code to alter the interface.
This updates the OpenTransactionsJNI.h header file to match whatever changes
you have made to the java class. If you do this, you will also have to hack
OpenTransactionsJNI.cpp in order to make whatever corresponding changes are
necessary to match the header.)

