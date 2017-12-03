#include "stdafx.h"
#include "MangedCallback.h"

#define COM_METHOD  HRESULT STDMETHODCALLTYPE
ULONG m_ref = 1;

HRESULT ManagedCallback::QueryInterface(REFIID iid, void **ppv)
{
	if (iid == IID_IUnknown || iid == IID_ICorDebugManagedCallback)
	{
		*ppv = static_cast<ICorDebugManagedCallback*>(this); // original implementation
	}
	else if (iid == IID_ICorDebugManagedCallback2)
	{
		*ppv = static_cast<ICorDebugManagedCallback2*>(this);
	}
	else
	{
		*ppv = NULL;
		return E_NOINTERFACE;
	}

	reinterpret_cast<IUnknown*>(*ppv)->AddRef();

	return S_OK;

}



ULONG ManagedCallback::AddRef(void)
{
	InterlockedIncrement(&m_ref);
	return m_ref;
}

ULONG ManagedCallback::Release(void)
{
	ULONG ulRefCount = InterlockedDecrement(&m_ref);

	if (0 == m_ref)
	{
		delete this;
	}

	return ulRefCount;
}

HRESULT ManagedCallback::Exception(ICorDebugAppDomain * pAppDomain, ICorDebugThread * pThread, BOOL unhandled)
{
	return S_OK;
}

HRESULT ManagedCallback::Exception(ICorDebugAppDomain * pAppDomain, ICorDebugThread * pThread, ICorDebugFrame * pFrame, ULONG32 nOffset, CorDebugExceptionCallbackType dwEventType, DWORD dwFlags)
{
	return E_NOTIMPL;
}

HRESULT ManagedCallback::ExceptionUnwind(ICorDebugAppDomain * pAppDomain, ICorDebugThread * pThread, CorDebugExceptionUnwindCallbackType dwEventType, DWORD dwFlags)
{
	return E_NOTIMPL;
}

HRESULT ManagedCallback::Breakpoint(ICorDebugAppDomain * pAppDomain, ICorDebugThread * pThread, ICorDebugBreakpoint * pBreakpoint)
{
	return E_NOTIMPL;
}

HRESULT ManagedCallback::StepComplete(ICorDebugAppDomain * pAppDomain, ICorDebugThread * pThread, ICorDebugStepper * pStepper, CorDebugStepReason reason)
{
	return E_NOTIMPL;
}

HRESULT ManagedCallback::Break(ICorDebugAppDomain * pAppDomain, ICorDebugThread * thread)
{
	return E_NOTIMPL;
}

HRESULT ManagedCallback::EvalComplete(ICorDebugAppDomain * pAppDomain, ICorDebugThread * pThread, ICorDebugEval * pEval)
{
	return E_NOTIMPL;
}

HRESULT ManagedCallback::EvalException(ICorDebugAppDomain * pAppDomain, ICorDebugThread * pThread, ICorDebugEval * pEval)
{
	return E_NOTIMPL;
}

HRESULT ManagedCallback::CreateProcess(ICorDebugProcess * pProcess)
{
	return E_NOTIMPL;
}

HRESULT ManagedCallback::ExitProcess(ICorDebugProcess * pProcess)
{
	return E_NOTIMPL;
}

HRESULT ManagedCallback::CreateThread(ICorDebugAppDomain * pAppDomain, ICorDebugThread * thread)
{
	return E_NOTIMPL;
}

HRESULT ManagedCallback::ExitThread(ICorDebugAppDomain * pAppDomain, ICorDebugThread * thread)
{
	return E_NOTIMPL;
}

HRESULT ManagedCallback::LoadModule(ICorDebugAppDomain * pAppDomain, ICorDebugModule * pModule)
{
	return E_NOTIMPL;
}

HRESULT ManagedCallback::UnloadModule(ICorDebugAppDomain * pAppDomain, ICorDebugModule * pModule)
{
	return E_NOTIMPL;
}

HRESULT ManagedCallback::LoadClass(ICorDebugAppDomain * pAppDomain, ICorDebugClass * c)
{
	return E_NOTIMPL;
}

HRESULT ManagedCallback::UnloadClass(ICorDebugAppDomain * pAppDomain, ICorDebugClass * c)
{
	return E_NOTIMPL;
}

HRESULT ManagedCallback::DebuggerError(ICorDebugProcess * pProcess, HRESULT errorHR, DWORD errorCode)
{
	return E_NOTIMPL;
}

HRESULT ManagedCallback::LogMessage(ICorDebugAppDomain * pAppDomain, ICorDebugThread * pThread, LONG lLevel, WCHAR * pLogSwitchName, WCHAR * pMessage)
{
	return E_NOTIMPL;
}

HRESULT ManagedCallback::LogSwitch(ICorDebugAppDomain * pAppDomain, ICorDebugThread * pThread, LONG lLevel, ULONG ulReason, WCHAR * pLogSwitchName, WCHAR * pParentName)
{
	return E_NOTIMPL;
}

HRESULT ManagedCallback::CreateAppDomain(ICorDebugProcess * pProcess, ICorDebugAppDomain * pAppDomain)
{
	return E_NOTIMPL;
}

HRESULT ManagedCallback::ExitAppDomain(ICorDebugProcess * pProcess, ICorDebugAppDomain * pAppDomain)
{
	return E_NOTIMPL;
}

HRESULT ManagedCallback::LoadAssembly(ICorDebugAppDomain * pAppDomain, ICorDebugAssembly * pAssembly)
{
	return E_NOTIMPL;
}

HRESULT ManagedCallback::UnloadAssembly(ICorDebugAppDomain * pAppDomain, ICorDebugAssembly * pAssembly)
{
	return E_NOTIMPL;
}

HRESULT ManagedCallback::ControlCTrap(ICorDebugProcess * pProcess)
{
	return E_NOTIMPL;
}

HRESULT ManagedCallback::NameChange(ICorDebugAppDomain * pAppDomain, ICorDebugThread * pThread)
{
	return E_NOTIMPL;
}

HRESULT ManagedCallback::UpdateModuleSymbols(ICorDebugAppDomain * pAppDomain, ICorDebugModule * pModule, IStream * pSymbolStream)
{
	return E_NOTIMPL;
}

HRESULT ManagedCallback::EditAndContinueRemap(ICorDebugAppDomain * pAppDomain, ICorDebugThread * pThread, ICorDebugFunction * pFunction, BOOL fAccurate)
{
	return E_NOTIMPL;
}

HRESULT ManagedCallback::BreakpointSetError(ICorDebugAppDomain * pAppDomain, ICorDebugThread * pThread, ICorDebugBreakpoint * pBreakpoint, DWORD dwError)
{
	return E_NOTIMPL;
}

HRESULT ManagedCallback::FunctionRemapOpportunity(ICorDebugAppDomain * pAppDomain, ICorDebugThread * pThread, ICorDebugFunction * pOldFunction, ICorDebugFunction * pNewFunction, ULONG32 oldILOffset)
{
	return E_NOTIMPL;
}

HRESULT ManagedCallback::CreateConnection(ICorDebugProcess * pProcess, CONNID dwConnectionId, WCHAR * pConnName)
{
	return E_NOTIMPL;
}

HRESULT ManagedCallback::ChangeConnection(ICorDebugProcess * pProcess, CONNID dwConnectionId)
{
	return E_NOTIMPL;
}

HRESULT ManagedCallback::DestroyConnection(ICorDebugProcess * pProcess, CONNID dwConnectionId)
{
	return E_NOTIMPL;
}

HRESULT ManagedCallback::FunctionRemapComplete(ICorDebugAppDomain * pAppDomain, ICorDebugThread * pThread, ICorDebugFunction * pFunction)
{
	return E_NOTIMPL;
}

HRESULT ManagedCallback::MDANotification(ICorDebugController * pController, ICorDebugThread * pThread, ICorDebugMDA * pMDA)
{
	return E_NOTIMPL;
}

//HRESULT STDMETHODCALLTYPE ManagedCallback::CustomNotification(ICorDebugThread *pThread, ICorDebugAppDomain *pAppDomain)
//{
//	return E_NOTIMPL;
//}