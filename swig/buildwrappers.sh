#!/bin/bash


# Check for swig
if ! swig -version > /dev/null; then 
    echo Cannot find swig...
    exit 1
fi


for x in csharp java perl5 php python ruby tcl
do
    echo Generating for $x ...

    rm -r glue/$x
    mkdir glue/$x

    # Remove existing temporary wrapper files
    for ext in cxx cpp h; do
	if [ -f otapi/OTAPI_wrap.$ext ]; then rm otapi/OTAPI_wrap.$ext; fi
    done


    if [ "$x" != "java" ]; then
	echo swig -c++ -$x -outdir glue/$x otapi/otapi.i
	swig -c++ -$x -outdir glue/$x otapi/otapi.i   
    fi

    if [ "$x" == "java" ]; then
	echo swig -c++ -$x -package org.ot.wrapper.jni -outdir glue/$x otapi/otapi.i
	swig -c++ -$x -package org.ot.wrapper.jni -outdir glue/$x otapi/otapi.i
    fi


    # Move and clean up wrapper files
    for ext in cxx cpp h; do
	if [ -f otapi/OTAPI-$x.$ext ]; then rm otapi/OTAPI-$x.$ext; fi
	if [ -f otapi/OTAPI_wrap.$ext ]; then mv otapi/OTAPI_wrap.$ext otapi/OTAPI-$x.$ext; fi
    done

done

echo Done!
