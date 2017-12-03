
// ManagedDebugger.cpp : Defines the entry point for the console application.
//kernel32.lib;user32.lib;gdi32.lib;winspool.lib;comdlg32.lib;advapi32.lib;shell32.lib;ole32.lib;oleaut32.lib;uuid.lib;odbc32.lib;odbccp32.lib;mscoree.lib;CorGuids.lib;%(AdditionalDependencies)
//For reference project
//https://github.com/SymbolSource/Microsoft.Samples.Debugging/blob/master/src/debugger/corapi/Debugger.cs
#include "stdafx.h"
#include "MangedCallback.h"

#pragma comment(lib, "mscoree.lib") 
using namespace std;

int main()
{	
	DWORD pid = 6080;
	HRESULT hr;
	HANDLE hProcess;

	ICLRMetaHost  *pMetaHost = NULL;
	IEnumUnknown *ppEnumerator = NULL;
	ICLRRuntimeInfo  *CLRRuntimeInfo = NULL;
	ULONG    pFetched = 0;
	DWORD versionLength;


	hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);

	if (hProcess == NULL) {
		printf("process unable to open");
		return 0;
	}

	hr = CLRCreateInstance(CLSID_CLRMetaHost, IID_ICLRMetaHost, (LPVOID*)&pMetaHost);
	pMetaHost->EnumerateLoadedRuntimes(hProcess, &ppEnumerator);

	if (ppEnumerator == 0) {
		return 0;
	}

	hr = ppEnumerator->Next(1, (IUnknown **)&CLRRuntimeInfo, &pFetched);

	if (hr == S_OK && pFetched > 0)
	{
		wchar_t version[20];
		DWORD versionStringSize = 20;
		CLRRuntimeInfo->GetVersionString(version, &versionLength);
		wcout << version;
	}

	if (CLRRuntimeInfo == 0) {
		cout << "CLRRuntimeInfo null pointer";
		return 0;
	}
	ICorDebug *codebugger = NULL;

	hr = CLRRuntimeInfo->GetInterface(CLSID_CLRDebuggingLegacy, IID_ICorDebug, (LPVOID*)&codebugger);

	if (codebugger == 0) {
		cout << "codebugger null pointer";
		return 0;
	}

	hr = codebugger->Initialize();

	ICorDebugProcess *coproc = NULL;

	ICorDebugManagedCallback *pHandler = new ManagedCallback();	

	hr = codebugger->SetManagedHandler(pHandler);

	hr = codebugger->DebugActiveProcess(pid, FALSE, &coproc);

	CloseHandle(hProcess);
	return 0;
}

