/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.8
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package org.opentransactions.jni.core;

public class OTCaller {
  private long swigCPtr;
  protected boolean swigCMemOwn;

  protected OTCaller(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(OTCaller obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        otapiJNI.delete_OTCaller(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public OTCaller() {
    this(otapiJNI.new_OTCaller(), true);
  }

  public boolean GetPassword(OTPassword theOutput) {
    return otapiJNI.OTCaller_GetPassword(swigCPtr, this, OTPassword.getCPtr(theOutput), theOutput);
  }

  public void ZeroOutPassword() {
    otapiJNI.OTCaller_ZeroOutPassword(swigCPtr, this);
  }

  public String GetDisplay() {
    return otapiJNI.OTCaller_GetDisplay(swigCPtr, this);
  }

  public void SetDisplay(String szDisplay, int nLength) {
    otapiJNI.OTCaller_SetDisplay(swigCPtr, this, szDisplay, nLength);
  }

  public void delCallback() {
    otapiJNI.OTCaller_delCallback(swigCPtr, this);
  }

  public void setCallback(OTCallback cb) {
    otapiJNI.OTCaller_setCallback(swigCPtr, this, OTCallback.getCPtr(cb), cb);
  }

  public boolean isCallbackSet() {
    return otapiJNI.OTCaller_isCallbackSet(swigCPtr, this);
  }

  public void callOne() {
    otapiJNI.OTCaller_callOne(swigCPtr, this);
  }

  public void callTwo() {
    otapiJNI.OTCaller_callTwo(swigCPtr, this);
  }

}
