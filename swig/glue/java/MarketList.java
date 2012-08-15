/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.8
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.wrapper.core.jni;

public class MarketList extends Storable {
  private long swigCPtr;

  protected MarketList(long cPtr, boolean cMemoryOwn) {
    super(otapiJNI.MarketList_SWIGUpcast(cPtr), cMemoryOwn);
    swigCPtr = cPtr;
  }

  protected static long getCPtr(MarketList obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        otapiJNI.delete_MarketList(swigCPtr);
      }
      swigCPtr = 0;
    }
    super.delete();
  }
// ------------------------
	/*@SWIG:otapi\otapi.i,335,OT_CONTAINER_TYPE_MEMBERS@*/
	private List elementList = new ArrayList();
/*@SWIG@*/
	/*@SWIG:otapi\otapi.i,416,OT_ADD_ELEMENT@*/  // THIS BLOCK CONTAINS JAVA CODE.
private long removeRefMarketData(long lIndex) {
	// 
	// loop through the elements in the actual container, in order to find the one
	// at lIndex. Once it is found, then loop through the reference list and remove
	// the corresponding reference for that element.
	//
	MarketData refActualElement = GetMarketData(lIndex);

	if (refActualElement == null)
		return lIndex; // oh well.
	
	// Loop through the reference list and remove the corresponding reference
	// for the specified element.
	//
	for(int intIndex = 0; intIndex < elementList.size(); intIndex++)
	{
		Object theObject = elementList.get(intIndex);
		
		if ((theObject == null) || !(theObject instanceof MarketData))
			continue;

		MarketData tempRef = (MarketData)(theObject);
		
		if ((MarketData.getCPtr(tempRef) == MarketData.getCPtr(refActualElement)))
		{
			elementList.remove(tempRef);
			break;
		}
	}
	
	return lIndex;
}

private long getCPtrAddRefMarketData(MarketData element) {
	// Whenever adding a reference to the list, I remove it first (if already there.)
	// That way we never store more than one reference per actual contained object.
	//
	for(int intIndex = 0; intIndex < elementList.size(); intIndex++)
	{
		Object theObject = elementList.get(intIndex);

		if ((theObject == null) || !(theObject instanceof MarketData))
			continue;
		
		MarketData tempRef = (MarketData)(theObject);
		
		if ((MarketData.getCPtr(tempRef) == MarketData.getCPtr(element)))
		{
			elementList.remove(tempRef); // It was already there, so let's remove it before adding (below.)
			break;
		}
	}
	// Now we add it...
	//
	MarketData tempLocalRef = element;
	elementList.add(tempLocalRef);
	return MarketData.getCPtr(element);
}	// Hope I get away with overloading this for every type. Otherwise,
/*@SWIG@*/
  public long GetMarketDataCount() { return otapiJNI.MarketList_GetMarketDataCount(swigCPtr, this); }

  public MarketData GetMarketData(long nIndex) {
    long cPtr = otapiJNI.MarketList_GetMarketData(swigCPtr, this, nIndex);
    return (cPtr == 0) ? null : new MarketData(cPtr, false);
  }

  public boolean RemoveMarketData(long nIndexMarketData) {
    return otapiJNI.MarketList_RemoveMarketData(swigCPtr, this, removeRefMarketData(nIndexMarketData));
  }

  public boolean AddMarketData(MarketData disownObject) {
    return otapiJNI.MarketList_AddMarketData(swigCPtr, this, MarketData.getCPtr(disownObject), disownObject);
  }

  public static MarketList ot_dynamic_cast(Storable pObject) {
    long cPtr = otapiJNI.MarketList_ot_dynamic_cast(Storable.getCPtr(pObject), pObject);
    return (cPtr == 0) ? null : new MarketList(cPtr, false);
  }

}
