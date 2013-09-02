/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.10
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package org.opentransactions.otapi;

public class AskData extends OfferDataMarket {
  private long swigCPtr;

  protected AskData(long cPtr, boolean cMemoryOwn) {
    super(otapiJNI.AskData_SWIGUpcast(cPtr), cMemoryOwn);
    swigCPtr = cPtr;
  }

  protected static long getCPtr(AskData obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        otapiJNI.delete_AskData(swigCPtr);
      }
      swigCPtr = 0;
    }
    super.delete();
  }
/*@SWIG:swig\otapi\OTAPI.i,151,OT_CAN_BE_CONTAINED_BY@*/
	// Ensure that the GC doesn't collect any OT_CONTAINER instance set from Java
	private OfferListMarket containerRefOfferListMarket;
	// ----------------	
	protected void addReference(OfferListMarket theContainer) {  // This is Java code
		containerRefOfferListMarket = theContainer;
	}
	// ----------------
/*@SWIG@*/
	// ------------------------
  public void setGui_label(String value) {
    otapiJNI.AskData_gui_label_set(swigCPtr, this, value);
  }

  public String getGui_label() {
    return otapiJNI.AskData_gui_label_get(swigCPtr, this);
  }

  public void setTransaction_id(String value) {
    otapiJNI.AskData_transaction_id_set(swigCPtr, this, value);
  }

  public String getTransaction_id() {
    return otapiJNI.AskData_transaction_id_get(swigCPtr, this);
  }

  public void setPrice_per_scale(String value) {
    otapiJNI.AskData_price_per_scale_set(swigCPtr, this, value);
  }

  public String getPrice_per_scale() {
    return otapiJNI.AskData_price_per_scale_get(swigCPtr, this);
  }

  public void setAvailable_assets(String value) {
    otapiJNI.AskData_available_assets_set(swigCPtr, this, value);
  }

  public String getAvailable_assets() {
    return otapiJNI.AskData_available_assets_get(swigCPtr, this);
  }

  public void setMinimum_increment(String value) {
    otapiJNI.AskData_minimum_increment_set(swigCPtr, this, value);
  }

  public String getMinimum_increment() {
    return otapiJNI.AskData_minimum_increment_get(swigCPtr, this);
  }

  public static AskData ot_dynamic_cast(Storable pObject) {
    long cPtr = otapiJNI.AskData_ot_dynamic_cast(Storable.getCPtr(pObject), pObject);
    return (cPtr == 0) ? null : new AskData(cPtr, false);
  }

}
