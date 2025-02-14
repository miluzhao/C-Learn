// testcocooc.cpp : Implementation of CtestcocoocApp and DLL registration.

#include "stdafx.h"
#include "testcocooc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CtestcocoocApp theApp;

const GUID CDECL _tlid = { 0x911DA389, 0x4054, 0x414D, { 0x8C, 0x64, 0x37, 0x23, 0xEB, 0x7A, 0x8D, 0x9F } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CtestcocoocApp::InitInstance - DLL initialization

BOOL CtestcocoocApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO: Add your own module initialization code here.
	}

	return bInit;
}



// CtestcocoocApp::ExitInstance - DLL termination

int CtestcocoocApp::ExitInstance()
{
	// TODO: Add your own module termination code here.

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - Adds entries to the system registry

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - Removes entries from the system registry

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
