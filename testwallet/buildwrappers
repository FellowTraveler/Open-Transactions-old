touch otapi.d; rm otapi.d;
touch otapi.cs; rm otapi.cs;
touch otapi.java; rm otapi.java;
touch otapi.php; rm otapi.php;
touch otapi.pm; rm otapi.pm;
touch otapi.py; rm otapi.py;
touch OTAPI.pyc; rm OTAPI.pyc;
touch otapiJNI.java; rm otapiJNI.java;
touch otapiPINVOKE.cs; rm otapiPINVOKE.cs;
touch OTAPI_d.cpp; rm OTAPI_d.cpp;
touch OTAPI_csharp.cpp; rm OTAPI_csharp.cpp;
touch OTAPI_java.cpp; rm OTAPI_java.cpp;
touch OTAPI_perl5.cpp; rm OTAPI_perl5.cpp;
touch OTAPI_php.cpp; rm OTAPI_php.cpp;
touch OTAPI_python.cpp; rm OTAPI_python.cpp;
touch OTAPI_ruby.cpp; rm OTAPI_ruby.cpp;
touch OTAPI_tcl.cpp; rm OTAPI_tcl.cpp;
touch php_otapi.h; rm php_otapi.h;
touch OTAPI_wrap.h; rm OTAPI_wrap.h;

#Commenting out LISP since it doesn't seem to have std_string.i
#touch otapi.lisp; rm otapi.lisp;
#touch OTAPI_cffi.c; rm OTAPI_cffi.c;
#touch OTAPI_wrap.c; rm OTAPI_wrap.c; /usr/bin/swig -c++ -cffi OTAPI.i; touch OTAPI_wrap.c; mv OTAPI_wrap.c OTAPI_cffi.c

# Commenting out the D-language for now, since swig-d doesn't seem to be available on macports right now.
#touch OTAPI_wrap.cxx; rm OTAPI_wrap.cxx; /usr/bin/swig -c++ -d -d2 OTAPI.i; touch OTAPI_wrap.cxx; mv OTAPI_wrap.cxx OTAPI_d.cpp; touch OTAPI_wrap.h; mv OTAPI_wrap.h OTAPI_d.h

touch OTAPI_wrap.cxx; rm OTAPI_wrap.cxx; swig -c++ -tcl OTAPI.i; touch OTAPI_wrap.cxx; mv OTAPI_wrap.cxx OTAPI_tcl.cpp; touch OTAPI_wrap.h; mv OTAPI_wrap.h OTAPI_tcl.h
touch OTAPI_wrap.cxx; rm OTAPI_wrap.cxx; swig -c++ -ruby OTAPI.i; touch OTAPI_wrap.cxx; mv OTAPI_wrap.cxx OTAPI_ruby.cpp; touch OTAPI_wrap.h; mv OTAPI_wrap.h OTAPI_ruby.h
touch OTAPI_wrap.cxx; rm OTAPI_wrap.cxx; swig -c++ -python OTAPI.i; touch OTAPI_wrap.cxx; mv OTAPI_wrap.cxx OTAPI_python.cpp; touch OTAPI_wrap.h; mv OTAPI_wrap.h OTAPI_python.h
touch OTAPI_wrap.cpp; rm OTAPI_wrap.cpp; swig -c++ -php OTAPI.i; touch OTAPI_wrap.cpp; mv OTAPI_wrap.cpp OTAPI_php.cpp; touch OTAPI_wrap.h; mv OTAPI_wrap.h OTAPI_php.h
touch OTAPI_wrap.cxx; rm OTAPI_wrap.cxx; swig -c++ -perl5 OTAPI.i; touch OTAPI_wrap.cxx; mv OTAPI_wrap.cxx OTAPI_perl5.cpp; touch OTAPI_wrap.h; mv OTAPI_wrap.h OTAPI_perl5.h
touch OTAPI_wrap.cxx; rm OTAPI_wrap.cxx; swig -c++ -csharp OTAPI.i; touch OTAPI_wrap.cxx; mv OTAPI_wrap.cxx OTAPI_csharp.cpp; touch OTAPI_wrap.h; mv OTAPI_wrap.h OTAPI_csharp.h

#I'm putting the Moneychanger package in here so I don't have to search/replace anymore.
#touch OTAPI_wrap.cxx; rm OTAPI_wrap.cxx; /usr/bin/swig -c++ -java OTAPI.i; touch OTAPI_wrap.cxx; mv OTAPI_wrap.cxx OTAPI_java.cpp; touch OTAPI_wrap.h; mv OTAPI_wrap.h OTAPI_java.h

#PACKAGE VERSION (com.wrapper.core.jni)
touch OTAPI_wrap.cxx; rm OTAPI_wrap.cxx; swig -c++ -java -package com.wrapper.core.jni OTAPI.i; touch OTAPI_wrap.cxx; mv OTAPI_wrap.cxx OTAPI_java.cpp; touch OTAPI_wrap.h; mv OTAPI_wrap.h OTAPI_java.h

#NO-PACKAGE VERSION
#touch OTAPI_wrap.cxx; rm OTAPI_wrap.cxx; swig -c++ -java OTAPI.i; touch OTAPI_wrap.cxx; mv OTAPI_wrap.cxx OTAPI_java.cpp; touch OTAPI_wrap.h; mv OTAPI_wrap.h OTAPI_java.h



