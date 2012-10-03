/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.8
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package org.opentransactions.jni.core;

public class RippleServer extends Server {
  private long swigCPtr;

  protected RippleServer(long cPtr, boolean cMemoryOwn) {
    super(otapiJNI.RippleServer_SWIGUpcast(cPtr), cMemoryOwn);
    swigCPtr = cPtr;
  }

  protected static long getCPtr(RippleServer obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        otapiJNI.delete_RippleServer(swigCPtr);
      }
      swigCPtr = 0;
    }
    super.delete();
  }

  public void setGui_label(String value) {
    otapiJNI.RippleServer_gui_label_set(swigCPtr, this, value);
  }

  public String getGui_label() {
    return otapiJNI.RippleServer_gui_label_get(swigCPtr, this);
  }

  public void setServer_id(String value) {
    otapiJNI.RippleServer_server_id_set(swigCPtr, this, value);
  }

  public String getServer_id() {
    return otapiJNI.RippleServer_server_id_get(swigCPtr, this);
  }

  public void setServer_type(String value) {
    otapiJNI.RippleServer_server_type_set(swigCPtr, this, value);
  }

  public String getServer_type() {
    return otapiJNI.RippleServer_server_type_get(swigCPtr, this);
  }

  public void setServer_host(String value) {
    otapiJNI.RippleServer_server_host_set(swigCPtr, this, value);
  }

  public String getServer_host() {
    return otapiJNI.RippleServer_server_host_get(swigCPtr, this);
  }

  public void setServer_port(String value) {
    otapiJNI.RippleServer_server_port_set(swigCPtr, this, value);
  }

  public String getServer_port() {
    return otapiJNI.RippleServer_server_port_get(swigCPtr, this);
  }

  public void setRipple_username(String value) {
    otapiJNI.RippleServer_ripple_username_set(swigCPtr, this, value);
  }

  public String getRipple_username() {
    return otapiJNI.RippleServer_ripple_username_get(swigCPtr, this);
  }

  public void setRipple_password(String value) {
    otapiJNI.RippleServer_ripple_password_set(swigCPtr, this, value);
  }

  public String getRipple_password() {
    return otapiJNI.RippleServer_ripple_password_get(swigCPtr, this);
  }

  public void setNamefield_id(String value) {
    otapiJNI.RippleServer_namefield_id_set(swigCPtr, this, value);
  }

  public String getNamefield_id() {
    return otapiJNI.RippleServer_namefield_id_get(swigCPtr, this);
  }

  public void setPassfield_id(String value) {
    otapiJNI.RippleServer_passfield_id_set(swigCPtr, this, value);
  }

  public String getPassfield_id() {
    return otapiJNI.RippleServer_passfield_id_get(swigCPtr, this);
  }

  public static RippleServer ot_dynamic_cast(Storable pObject) {
    long cPtr = otapiJNI.RippleServer_ot_dynamic_cast(Storable.getCPtr(pObject), pObject);
    return (cPtr == 0) ? null : new RippleServer(cPtr, false);
  }

  public static Storable ot_dynamic_cast_box(RippleServer pUnboxed) {
    long cPtr = otapiJNI.RippleServer_ot_dynamic_cast_box(RippleServer.getCPtr(pUnboxed), pUnboxed);
    return (cPtr == 0) ? null : new Storable(cPtr, false);
  }

}
