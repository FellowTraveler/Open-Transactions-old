/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.10
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

namespace OpenTransactions.OTAPI {

using System;
using System.Runtime.InteropServices;

public class ContactNym : Displayable {
  private HandleRef swigCPtr;

  internal ContactNym(IntPtr cPtr, bool cMemoryOwn) : base(otapiPINVOKE.ContactNym_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new HandleRef(this, cPtr);
  }

  internal static HandleRef getCPtr(ContactNym obj) {
    return (obj == null) ? new HandleRef(null, IntPtr.Zero) : obj.swigCPtr;
  }

  ~ContactNym() {
    Dispose();
  }

  public override void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          otapiPINVOKE.delete_ContactNym(swigCPtr);
        }
        swigCPtr = new HandleRef(null, IntPtr.Zero);
      }
      GC.SuppressFinalize(this);
      base.Dispose();
    }
  }

  public string gui_label {
    set {
      otapiPINVOKE.ContactNym_gui_label_set(swigCPtr, value);
      if (otapiPINVOKE.SWIGPendingException.Pending) throw otapiPINVOKE.SWIGPendingException.Retrieve();
    } 
    get {
      string ret = otapiPINVOKE.ContactNym_gui_label_get(swigCPtr);
      if (otapiPINVOKE.SWIGPendingException.Pending) throw otapiPINVOKE.SWIGPendingException.Retrieve();
      return ret;
    } 
  }

  public string nym_type {
    set {
      otapiPINVOKE.ContactNym_nym_type_set(swigCPtr, value);
      if (otapiPINVOKE.SWIGPendingException.Pending) throw otapiPINVOKE.SWIGPendingException.Retrieve();
    } 
    get {
      string ret = otapiPINVOKE.ContactNym_nym_type_get(swigCPtr);
      if (otapiPINVOKE.SWIGPendingException.Pending) throw otapiPINVOKE.SWIGPendingException.Retrieve();
      return ret;
    } 
  }

  public string nym_id {
    set {
      otapiPINVOKE.ContactNym_nym_id_set(swigCPtr, value);
      if (otapiPINVOKE.SWIGPendingException.Pending) throw otapiPINVOKE.SWIGPendingException.Retrieve();
    } 
    get {
      string ret = otapiPINVOKE.ContactNym_nym_id_get(swigCPtr);
      if (otapiPINVOKE.SWIGPendingException.Pending) throw otapiPINVOKE.SWIGPendingException.Retrieve();
      return ret;
    } 
  }

  public string public_key {
    set {
      otapiPINVOKE.ContactNym_public_key_set(swigCPtr, value);
      if (otapiPINVOKE.SWIGPendingException.Pending) throw otapiPINVOKE.SWIGPendingException.Retrieve();
    } 
    get {
      string ret = otapiPINVOKE.ContactNym_public_key_get(swigCPtr);
      if (otapiPINVOKE.SWIGPendingException.Pending) throw otapiPINVOKE.SWIGPendingException.Retrieve();
      return ret;
    } 
  }

  public string memo {
    set {
      otapiPINVOKE.ContactNym_memo_set(swigCPtr, value);
      if (otapiPINVOKE.SWIGPendingException.Pending) throw otapiPINVOKE.SWIGPendingException.Retrieve();
    } 
    get {
      string ret = otapiPINVOKE.ContactNym_memo_get(swigCPtr);
      if (otapiPINVOKE.SWIGPendingException.Pending) throw otapiPINVOKE.SWIGPendingException.Retrieve();
      return ret;
    } 
  }

  public uint GetServerInfoCount() {
    uint ret = otapiPINVOKE.ContactNym_GetServerInfoCount(swigCPtr);
    return ret;
  }

  public ServerInfo GetServerInfo(uint nIndex) {
    IntPtr cPtr = otapiPINVOKE.ContactNym_GetServerInfo(swigCPtr, nIndex);
    ServerInfo ret = (cPtr == IntPtr.Zero) ? null : new ServerInfo(cPtr, false);
    return ret;
  }

  public bool RemoveServerInfo(uint nIndexServerInfo) {
    bool ret = otapiPINVOKE.ContactNym_RemoveServerInfo(swigCPtr, nIndexServerInfo);
    return ret;
  }

  public bool AddServerInfo(ServerInfo disownObject) {
    bool ret = otapiPINVOKE.ContactNym_AddServerInfo(swigCPtr, ServerInfo.getCPtr(disownObject));
    if (otapiPINVOKE.SWIGPendingException.Pending) throw otapiPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public new static ContactNym ot_dynamic_cast(Storable pObject) {
    IntPtr cPtr = otapiPINVOKE.ContactNym_ot_dynamic_cast(Storable.getCPtr(pObject));
    ContactNym ret = (cPtr == IntPtr.Zero) ? null : new ContactNym(cPtr, false);
    return ret;
  }

}

}
