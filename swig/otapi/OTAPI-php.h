/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.8
 * 
 * This file is not intended to be easily readable and contains a number of 
 * coding conventions designed to improve portability and efficiency. Do not make
 * changes to this file unless you know what you are doing--modify the SWIG 
 * interface file instead. 
 * ----------------------------------------------------------------------------- */

#ifndef SWIG_OTAPI_WRAP_H_
#define SWIG_OTAPI_WRAP_H_

class SwigDirector_SwigPasswordCallback : public SwigPasswordCallback, public Swig::Director {

public:
    SwigDirector_SwigPasswordCallback(zval *self TSRMLS_DC);
    virtual ~SwigDirector_SwigPasswordCallback();
    virtual bool const SwigGetPassword(OTPassword &passwordObject, std::string const &strMessage);
    virtual bool const SwigNewPassword(OTPassword &passwordObject, std::string const &strMessage);
};

#endif
