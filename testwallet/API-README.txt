These instructions cover: BUILDING the API.

You can now build the API from the top folder. 
From where you are now, just do this:

>  cd ..
>  make clean

Then choose a language:
>  make php5
>  make perl5
>  make ruby
>  make c
>  make java

If you don't see your favorite language, fear not: it may still be
supported, just further down in this document! (I.e. not available
as a top-level build option.)

OTHERWISE, YOU'RE DONE!!!

(See below for more details.)

---------------------------------------------------------


How to USE the API:
https://github.com/FellowTraveler/Open-Transactions/wiki/API
https://github.com/FellowTraveler/Open-Transactions/wiki/Use-Cases



------------------------------------------

===> BUILD THE TEST CLIENT - (Makefile)
(command line utility)

You probably prefer to build in XmlRpc/HTTP mode:

               make TRANSPORT=XmlRpc
               gmake TRANSPORT=XmlRpc

Otherwise there is the old TCP/SSL (not recommended):

MAC OR LINUX:  make
FREEBSD:       gmake

-----------------------------------------

WINDOWS ONLY: inside the Open-Transactions\testwallet\testwallet folder
is an MS Visual C++ 2010 Express project that will build this project
for Windows.

The output will be an executable called "testwallet.exe".
Run it from this directory like so: ./testwallet.exe 

On Windows you may have to copy it to this directory first, as it may
be in a Debug or Release folder.

**********************************************


===>  BUILD THE API - (Makefile.API)

Open Transactions now supports native interfaces to the
following languages:

C, Obj-C, C++, C#, Java, Ruby, Python, Perl, Php, Tcl, Lisp

(Instructions for each language are below.)

** You likely wish to add TRANSPORT=XmlRpc to the below commands, as well.
And: MAKE SURE you do a make clean when switching languages, since they
can interfere with each other. 

----------------
LINUX WARNING: On Linux, you must rebuild OTLib with the proper flags,
before you can build the OTAPI, or you'll get errors. If you are using
linux, do this now:

cd ../OTLib; make clean; make DYNAMIC_OTLIB=1; cd ../testwallet

Now you may continue with the rest of these instructions...
----------------


THE 'C++' HIGH-LEVEL CLASS

make -f Makefile.API [TRANSPORT=XmlRpc] LANGUAGE=c

-- link to libOTAPI.a

-- include OpenTransactions.h in your code.

--------------------------------


THE 'Straight C' API

(To be used in C, Obj-C, and C++ projects)

make -f Makefile.API [TRANSPORT=XmlRpc] LANGUAGE=c

-- link to libOTAPI.a

-- include OTAPI.h in your code
-- You'll also need a copy of OTAPI_funcdef.h
   (but DON'T #include it--just make sure that it's there.)

--------------------------------

C#

make -f Makefile.API [TRANSPORT=XmlRpc] LANGUAGE=csharp

This builds the shared lib: 
libotapi.so

-- Use otapi.cs in your C-Sharp project.

--------------------------------

Java

make -f Makefile.API [TRANSPORT=XmlRpc] LANGUAGE=java

This builds the shared lib:
libotapi.jnilib

-- Use otapi.java in your Java project.

For Linux, MAKE SURE that the "JAVA_HOME" environment variable is set properly,
since the Makefile depends on it! The value is usually something like /usr/lib/jvm/default-java
or /usr/lib/jvm/java-6-openjdk.

Instructions to set it in linux:

-- For your current user,
Open up a shell / terminal window
vi ~/.profile (replace vi with your favourite text editor)
Add export JAVA_HOME=/path/to/java/home/dir on its own line at the end of the file
Add export PATH=$JAVA_HOME/bin:$PATH on its own line immediately after
Save, and restart your shell
Running java -version should give you the desired results

-- For all users in the system,
Open up a shell / terminal window
vi /etc/profile (replace vi with your favourite text editor)
Add export JAVA_HOME=/path/to/java/home/dir on its own line at the end of the file
Add export PATH=$JAVA_HOME/bin:$PATH on its own line immediately after
Save, and restart your shell
Running java -version should give you the desired results


---------
Note: the current OT GUI ("Moneychanger", in java) requires a slight modification 
to one file: OTAPI_java.c

Basically search for this string: Java_otapiJNI
And replace it with this string:  Java_com_wrapper_core_jni_otapiJNI
Replace all, it appears over a hundred times. (It's probably already done for you.)

Then go to the Open-Transactions folder and type: make clean && make java

Then the OT Java GUI will work; just put the jar in the testwallet folder
(and run it from there as well.)

--------------------------------

Ruby

make -f Makefile.API [TRANSPORT=XmlRpc] LANGUAGE=ruby

This builds otapi.bundle on Mac, and otapi.so on Linux, which you can use
in your Ruby project like any other native library.

On Linux I installed Ruby and Ruby-Dev:
apt-get install ruby
apt-get install ruby-dev


NOTE: The Ruby API now features a top-level build target! Especially on Linux,
this is the easiest way to build the Ruby API. To build for ruby, do it from
the MAIN folder:

	cd Open-Transactions; make clean; make ruby;


To test the Ruby API, follow these tests from there:

1)	cd testwallet; ruby

2) After you hit enter, paste the below ruby code, followed by a Ctrl-D as
depicted below:

require 'otapi'

Otapi.OT_API_Init "/absolute-path-goes-here/.ot/client_data"

Otapi.OT_API_LoadWallet "wallet.xml"

^D

NOTE: Use an actual Ctrl-D, and do not simply paste the one that appears above.
ADDITIONAL NOTE: Make sure you use the correct path, above where it says "full-
path-goes-here" you should substitute that for the appropriate path on your own
system. (On the command line, use the pwd command to see what the path is on your 
own system.)

If everything is successful, you will see the wallet loaded on the screen!


--------------------------------


Python

make -f Makefile.API [TRANSPORT=XmlRpc] LANGUAGE=python

This builds _otapi.so, a shared library that you can call from your Python
project using the otapi.py file.

To do this on linux, I had to install Python-dev:
apt-get install python-dev

From the testwallet folder, you can verify the Python API like this:

$
$
$
$ python
>>> import otapi
>>> otapi.OT_API_Init("/full-path-goes-here/Open-Transactions/testwallet/data_folder")
>>> otapi.OT_API_LoadWallet("wallet.xml")


Let me know if it works for you!

--------------------------------

Perl5

make -f Makefile.API [TRANSPORT=XmlRpc] LANGUAGE=perl5

This builds otapi.bundle, which you can use in your Perl project via
 the file otapi.pm

Problems BUILDING?  Check the version of Perl being included / linked
in the Makefile, and make sure it matches the location on your system.
You might have 5.10.1 instead of 5.10.0

Problems RUNNING?  One user reported a segmentation fault on his MAC OS X.
It was later determined that the user was building with perl 5.10.1,
but running perl version 5.8.8, which was segfaulting. So, try EXPLICITLY
running the correct version of perl at the command line, by typing 
perl5.10.0 or perl5.10.1, instead of just typing perl, when you run the
software. (This fixed the problem for me on my Mac.)
Example:
$ 
$ perl -e "use otapi;"
Segmentation fault
$ 
$ 
$ perl5.10.0 -e "use otapi;"
$ 
$ 
$  


Notice: no segfault when I do it the second way -- because I am
running the correct version of perl that time. Try it both ways
to test on your own computer which one is right.


PERL NOTE!!! There is now a TOP LEVEL option for building perl5!
Since some platforms require XmlRpc and OTLib to be rebuilt with
certain flags, I made it easy by adding a top-level target, since
we have a client developer who is actively targeting perl.

TO USE IT:

	cd Open-Transactions; make clean; make perl5;


It's that easy! To test it on the command line:

$ cd testwallet
$
$ perl5.10.0
use otapi;
otapi::OT_API_Init("/full-path-goes-here/Open-Transactions/testwallet/data_folder");
otapi::OT_API_LoadWallet("wallet.xml");

^D

Loading wallet: Fellow Traveler's test wallet, version: 1.0

(Etc. The entire wallet loaded.)

--------------------------------

PHP

make -f Makefile.API [TRANSPORT=XmlRpc] LANGUAGE=php5

This builds otapi.so, which you can use in your PHP project via the file otapi.php

On linux, make sure you have done this first:
apt-get install php5-dev

--------------------------------

Tcl

make -f Makefile.API [TRANSPORT=XmlRpc] LANGUAGE=tcl

This builds otapi.so, which you can use in your Tcl project like so:
load ./otapi.so otapi

On Linux, I had to install Tcl and Tcl-Dev:
apt-get install tcl
apt-get install tcl-dev

--------------------------------

LISP

make -f Makefile.API [TRANSPORT=XmlRpc] LANGUAGE=lisp

This builds otapi.so, which you can use in your LISP project via otapi.lisp


