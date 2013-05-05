/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.9
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package org.opentransactions.otapi;

public class OTCallback {
  private long swigCPtr;
  protected boolean swigCMemOwn;

  protected OTCallback(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(OTCallback obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        otapiJNI.delete_OTCallback(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  protected void swigDirectorDisconnect() {
    swigCMemOwn = false;
    delete();
  }

  public void swigReleaseOwnership() {
    swigCMemOwn = false;
    otapiJNI.OTCallback_change_ownership(this, swigCPtr, false);
  }

  public void swigTakeOwnership() {
    swigCMemOwn = true;
    otapiJNI.OTCallback_change_ownership(this, swigCPtr, true);
  }

  public OTCallback() {
    this(otapiJNI.new_OTCallback(), true);
    otapiJNI.OTCallback_director_connect(this, swigCPtr, swigCMemOwn, true);
  }

  public void runOne(String szDisplay, OTPassword theOutput) {
    if (getClass() == OTCallback.class) otapiJNI.OTCallback_runOne(swigCPtr, this, szDisplay, OTPassword.getCPtr(theOutput), theOutput); else otapiJNI.OTCallback_runOneSwigExplicitOTCallback(swigCPtr, this, szDisplay, OTPassword.getCPtr(theOutput), theOutput);
  }

  public void runTwo(String szDisplay, OTPassword theOutput) {
    if (getClass() == OTCallback.class) otapiJNI.OTCallback_runTwo(swigCPtr, this, szDisplay, OTPassword.getCPtr(theOutput), theOutput); else otapiJNI.OTCallback_runTwoSwigExplicitOTCallback(swigCPtr, this, szDisplay, OTPassword.getCPtr(theOutput), theOutput);
  }

}
