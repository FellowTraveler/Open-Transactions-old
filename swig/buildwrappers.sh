#!/bin/bash


# Check for swig
if ! swig -version > /dev/null; then 
    echo Cannot find swig...
    exit 1
fi


for x in csharp java perl5 php python ruby tcl d
do
    echo Generating for $x ...

    rm -r glue/$x
    mkdir glue/$x

    # Remove existing temporary wrapper files
    for ext in cxx cpp h; do
	if [ -f otapi/OTAPI_wrap.$ext ]; then rm otapi/OTAPI_wrap.$ext; fi
    done


    if [ "$x" != "java" ]; then
	echo swig -c++ -$x -outdir glue/$x otapi/OTAPI.i
	swig -c++ -$x -outdir glue/$x otapi/OTAPI.i
    fi

    if [ "$x" == "java" ]; then
	echo swig -c++ -$x -package org.opentransactions.jni.core -outdir glue/$x otapi/OTAPI.i
	swig -c++ -$x -package org.opentransactions.jni.core -outdir glue/$x otapi/OTAPI.i
    fi


    # Move and clean up wrapper files
    for ext in cxx cpp h; do
	if [ -f otapi/OTAPI-$x.$ext ]; then rm otapi/OTAPI-$x.$ext; fi
	if [ -f otapi/OTAPI_wrap.$ext ]; then mv otapi/OTAPI_wrap.$ext otapi/OTAPI-$x.$ext; fi
    done

    for ext in cxx cpp; do
	if [ -f otapi/OTAPI-$x.$ext ]; then printf '%s\n' "g/OTAPI_wrap\.h/s//OTAPI-$x.h/g" w | ed -s "otapi/OTAPI-$x.$ext"; fi
    done

done

echo Done!
