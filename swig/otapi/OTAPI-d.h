/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.8
 * 
 * This file is not intended to be easily readable and contains a number of 
 * coding conventions designed to improve portability and efficiency. Do not make
 * changes to this file unless you know what you are doing--modify the SWIG 
 * interface file instead. 
 * ----------------------------------------------------------------------------- */

#ifndef SWIG_otapi_WRAP_H_
#define SWIG_otapi_WRAP_H_

class SwigDirector_SwigPasswordCallback : public SwigPasswordCallback, public Swig::Director {

public:
    SwigDirector_SwigPasswordCallback();
    virtual ~SwigDirector_SwigPasswordCallback();
    virtual bool const SwigGetPassword(OTPassword &passwordObject, std::string const &strMessage);
    virtual bool const SwigNewPassword(OTPassword &passwordObject, std::string const &strMessage);

    typedef unsigned int (* SWIG_Callback0_t)(void *dobj, void *, char *);
    typedef unsigned int (* SWIG_Callback1_t)(void *dobj, void *, char *);
    void swig_connect_director(void* dobj, SWIG_Callback0_t callbackSwigGetPassword, SWIG_Callback1_t callbackSwigNewPassword);

private:
    void swig_init_callbacks();
    void *d_object;
    SWIG_Callback0_t swig_callback_SwigGetPassword;
    SWIG_Callback1_t swig_callback_SwigNewPassword;
};


#endif
