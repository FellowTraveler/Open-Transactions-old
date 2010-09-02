
To build the test client (it runs on the command-line):   

MAC OR LINUX:  make -f Makefile.testwallet

WINDOWS: inside the Open-Transactions\testwallet\testwallet folder is an MS Visual C++ 2010
Express project that will build this project for Windows.

The output will be an executable called "testwallet.exe".
Run it from this directory like so: ./testwallet.exe 

On Windows you may have to copy it to this directory first, as it may be in a Debug
or Release folder.

------------------------------------------

TO USE THE OT API IN YOUR OWN C++ PROJECTS:

To build the static library for the C++ high-level interface:

MAC OR LINUX:  make -f Makefile.CPP_API

WINDOWS: Inside the CPP_API_Windows folder is an MS Visual C++ 2010 Express project
for building this. The output is a static library.

The output will be a static library called libOTAPI.a (or libOTAPI.lib, or
CPP_API_Windows.lib or whatever it's called on Windows after it builds.)

TO USE IT:
Just #include "OpenTransactions.h" in whatever C++ project you want to use,
and make sure you statically link to libOTAPI.a (or whatever it is on Windows.)

------------------------------------------

TO USE THE API IN YOUR OWN JAVA / JRUBY / JYTHON PROJECTS:

To build the dynamic library for the Java JNI interface:

1) First, make sure you build the C++ interface, since the JNI wraps it:

   MAC OR LINUX:  make -f Makefile.CPP_API

   WINDOWS: Inside the CPP_API_Windows folder is an MS Visual C++ 2010 Express project
   for building this. The output is a static library.

2) Then compile the java file:

TO COMPILE THE JAVA CLASS:  javac OpenTransactionsJNI.java
The output from javac will be a file called OpenTransactionsJNI.class

LINUX ONLY:  I had to install Java on Ubuntu, using these two commands:  
sudo apt-get install openjdk-6-jre; sudo apt-get install openjdk-6-jdk

3) Then build the JNI C++ wrapper class:

MAC:   make -f Makefile.JNI_API_MAC_OSX
       (The output is libOT_JNI_API.jnilib)

LINUX: make -f Makefile.JNI_API_Linux
       (The output is libOT_JNI_API.so)

WINDOWS: Inside the JNI_API_Windows folder is an MS Visual C++ 2010 Express project
for building this. The output is a DLL.

---

To run the JNI interface from the command line, type this:
java OpenTransactionsJNI

(It contains a main function, so you can run it.)

LINUX NOTE: libOT_JNI_API.so must be on the java.library.path for this to work.

---

Running "java OpenTransactionsJNI" will load up OpenTransactionsJNI.class, 
which contains a main function. When main() runs, it will call loadLibrary("OT_JNI_API") 
which will load up the libOT_JNI_API.jnilib or .so or DLL (depending on your
platform) into memory.

From here on out, any calls to the OpenTransactionsJNI methods in the
java code will be passed through and executed by the C++ code in the
dynamic library.

The test main() in OpenTransactionsJNI.java doesn't do much. It just loads
the jnilib, then loads the wallet file, then connects to the server. Then
it ends. From there, code it to do whatever you want using the JNI interface.

---

If you want to create a new C++ header for the JNI interface (if you have
been hacking the java class) then be sure to also do this:

javah -jni OpenTransactionsJNI

(javah is ONLY necessary if you hacked the java code to alter the interface.
This updates the OpenTransactionsJNI.h header file to match whatever changes
you have made to the java class. If you do this, you will also have to hack
OpenTransactionsJNI.cpp in order to make whatever corresponding changes are
necessary to match the header.)

