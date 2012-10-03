/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.8
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package org.opentransactions.jni.core;

public class OfferListMarket extends Storable {
  private long swigCPtr;

  protected OfferListMarket(long cPtr, boolean cMemoryOwn) {
    super(otapiJNI.OfferListMarket_SWIGUpcast(cPtr), cMemoryOwn);
    swigCPtr = cPtr;
  }

  protected static long getCPtr(OfferListMarket obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        otapiJNI.delete_OfferListMarket(swigCPtr);
      }
      swigCPtr = 0;
    }
    super.delete();
  }

  public long GetBidDataCount() {
    return otapiJNI.OfferListMarket_GetBidDataCount(swigCPtr, this);
  }

  public BidData GetBidData(long nIndex) {
    long cPtr = otapiJNI.OfferListMarket_GetBidData(swigCPtr, this, nIndex);
    return (cPtr == 0) ? null : new BidData(cPtr, false);
  }

  public boolean RemoveBidData(long nIndexBidData) {
    return otapiJNI.OfferListMarket_RemoveBidData(swigCPtr, this, nIndexBidData);
  }

  public boolean AddBidData(BidData disownObject) {
    return otapiJNI.OfferListMarket_AddBidData(swigCPtr, this, BidData.getCPtr(disownObject), disownObject);
  }

  public long GetAskDataCount() {
    return otapiJNI.OfferListMarket_GetAskDataCount(swigCPtr, this);
  }

  public AskData GetAskData(long nIndex) {
    long cPtr = otapiJNI.OfferListMarket_GetAskData(swigCPtr, this, nIndex);
    return (cPtr == 0) ? null : new AskData(cPtr, false);
  }

  public boolean RemoveAskData(long nIndexAskData) {
    return otapiJNI.OfferListMarket_RemoveAskData(swigCPtr, this, nIndexAskData);
  }

  public boolean AddAskData(AskData disownObject) {
    return otapiJNI.OfferListMarket_AddAskData(swigCPtr, this, AskData.getCPtr(disownObject), disownObject);
  }

  public static OfferListMarket ot_dynamic_cast(Storable pObject) {
    long cPtr = otapiJNI.OfferListMarket_ot_dynamic_cast(Storable.getCPtr(pObject), pObject);
    return (cPtr == 0) ? null : new OfferListMarket(cPtr, false);
  }

  public static Storable ot_dynamic_cast_box(OfferListMarket pUnboxed) {
    long cPtr = otapiJNI.OfferListMarket_ot_dynamic_cast_box(OfferListMarket.getCPtr(pUnboxed), pUnboxed);
    return (cPtr == 0) ? null : new Storable(cPtr, false);
  }

}
