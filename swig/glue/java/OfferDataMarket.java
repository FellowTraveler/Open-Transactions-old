/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.8
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package org.opentransactions.jni.core;

public class OfferDataMarket extends Displayable {
  private long swigCPtr;

  protected OfferDataMarket(long cPtr, boolean cMemoryOwn) {
    super(otapiJNI.OfferDataMarket_SWIGUpcast(cPtr), cMemoryOwn);
    swigCPtr = cPtr;
  }

  protected static long getCPtr(OfferDataMarket obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        otapiJNI.delete_OfferDataMarket(swigCPtr);
      }
      swigCPtr = 0;
    }
    super.delete();
  }

  public void setGui_label(String value) {
    otapiJNI.OfferDataMarket_gui_label_set(swigCPtr, this, value);
  }

  public String getGui_label() {
    return otapiJNI.OfferDataMarket_gui_label_get(swigCPtr, this);
  }

  public void setTransaction_id(String value) {
    otapiJNI.OfferDataMarket_transaction_id_set(swigCPtr, this, value);
  }

  public String getTransaction_id() {
    return otapiJNI.OfferDataMarket_transaction_id_get(swigCPtr, this);
  }

  public void setPrice_per_scale(String value) {
    otapiJNI.OfferDataMarket_price_per_scale_set(swigCPtr, this, value);
  }

  public String getPrice_per_scale() {
    return otapiJNI.OfferDataMarket_price_per_scale_get(swigCPtr, this);
  }

  public void setAvailable_assets(String value) {
    otapiJNI.OfferDataMarket_available_assets_set(swigCPtr, this, value);
  }

  public String getAvailable_assets() {
    return otapiJNI.OfferDataMarket_available_assets_get(swigCPtr, this);
  }

  public void setMinimum_increment(String value) {
    otapiJNI.OfferDataMarket_minimum_increment_set(swigCPtr, this, value);
  }

  public String getMinimum_increment() {
    return otapiJNI.OfferDataMarket_minimum_increment_get(swigCPtr, this);
  }

  public static OfferDataMarket ot_dynamic_cast(Storable pObject) {
    long cPtr = otapiJNI.OfferDataMarket_ot_dynamic_cast(Storable.getCPtr(pObject), pObject);
    return (cPtr == 0) ? null : new OfferDataMarket(cPtr, false);
  }

}
