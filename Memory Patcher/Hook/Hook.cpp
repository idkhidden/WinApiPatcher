
#include <iostream>
#include <Windows.h>

using namespace std;


void patch()
{
    cout << "\n[+] Hooking Started!";

    HMODULE Kernel32 = GetModuleHandle("kernel32.dll");
    HMODULE Ntdll = GetModuleHandle("ntdll.dll");
    HMODULE User32 = GetModuleHandle("user32.dll");

    FARPROC EzIsDebuggerPresent = GetProcAddress(Kernel32, "IsDebuggerPresent");
    FARPROC EzCreatRemoteDebugger = GetProcAddress(Kernel32, "CheckRemoteDebuggerPresent");
    FARPROC EzGetTickCount64 = GetProcAddress(Kernel32, "GetTickCount64");
    FARPROC EzGetTickCount = GetProcAddress(Kernel32, "GetTickCount");
    FARPROC EzDebugBreak = GetProcAddress(Kernel32, "DebugBreak");


  
    FARPROC EzDbgUiRemoteBreakin = GetProcAddress(Ntdll, "DbgUiRemoteBreakin");
    FARPROC EzDbgActiveProcess = GetProcAddress(Ntdll, "NtDebugActiveProcess");
    FARPROC EzQueryInformationProcess = GetProcAddress(Ntdll, "NtQueryInformationProcess");
    FARPROC EzSetInformationProcess = GetProcAddress(Ntdll, "NtSetInformationProcess");
    FARPROC EzObject = GetProcAddress(Ntdll, "NtQueryObject");
    FARPROC EzAdjustPrivilege = GetProcAddress(Ntdll, "RtlAdjustPrivilege");
    FARPROC EzRaiseHardError = GetProcAddress(Ntdll, "NtRaiseHardError");

    FARPROC EzBlockInput = GetProcAddress(User32, "BlockInput");
    FARPROC EzFindWindowA = GetProcAddress(User32, "FindWindowA");
    FARPROC EzFindWindowW = GetProcAddress(User32, "FindWindowW");
    FARPROC EzFindWindow = GetProcAddress(User32, "FindWindow");


    unsigned char patch[] = { 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 };
    DWORD old;

    if (EzIsDebuggerPresent)
    {
       VirtualProtect(EzIsDebuggerPresent, sizeof(BYTE), PAGE_EXECUTE_READWRITE, &old);
       memcpy(EzIsDebuggerPresent, patch, sizeof(patch));
       VirtualProtect(EzIsDebuggerPresent, sizeof(BYTE),old,&old);
    }
    if (EzCreatRemoteDebugger)
    {
        VirtualProtect(EzCreatRemoteDebugger, sizeof(BYTE), PAGE_EXECUTE_READWRITE, &old);
        memcpy(EzCreatRemoteDebugger, patch, sizeof(patch));
        VirtualProtect(EzCreatRemoteDebugger, sizeof(BYTE), old, &old);
    }
    if (EzGetTickCount)
    {
        VirtualProtect(EzGetTickCount, sizeof(BYTE), PAGE_EXECUTE_READWRITE, &old);
        memcpy(EzGetTickCount, patch, sizeof(patch));
        VirtualProtect(EzGetTickCount, sizeof(BYTE), old, &old);
    }
    if (EzGetTickCount64)
    {
        VirtualProtect(EzGetTickCount64, sizeof(BYTE), PAGE_EXECUTE_READWRITE, &old);
        memcpy(EzGetTickCount64, patch, sizeof(patch));
        VirtualProtect(EzGetTickCount64, sizeof(BYTE), old, &old);
    }
    if (EzDebugBreak)
    {
        VirtualProtect(EzDebugBreak, sizeof(BYTE), PAGE_EXECUTE_READWRITE, &old);
        memcpy(EzDebugBreak, patch, sizeof(patch));
        VirtualProtect(EzDebugBreak, sizeof(BYTE), old, &old);

    }



    if (EzDbgUiRemoteBreakin)
    {
        VirtualProtect(EzDbgUiRemoteBreakin, sizeof(BYTE), PAGE_EXECUTE_READWRITE, &old);
        memcpy(EzDbgUiRemoteBreakin, patch, sizeof(patch));
        VirtualProtect(EzDbgUiRemoteBreakin, sizeof(BYTE), old, &old);
    }
    if (EzDbgActiveProcess)
    {
        VirtualProtect(EzDbgActiveProcess, sizeof(BYTE), PAGE_EXECUTE_READWRITE, &old);
        memcpy(EzDbgActiveProcess, patch, sizeof(patch));
        VirtualProtect(EzDbgActiveProcess, sizeof(BYTE), old, &old);
    }
    if (EzQueryInformationProcess)
    {
        VirtualProtect(EzQueryInformationProcess, sizeof(BYTE), PAGE_EXECUTE_READWRITE, &old);
        memcpy(EzQueryInformationProcess, patch, sizeof(patch));
        VirtualProtect(EzQueryInformationProcess, sizeof(BYTE), old, &old);
    }
    if (EzSetInformationProcess)
    {
        VirtualProtect(EzSetInformationProcess, sizeof(BYTE), PAGE_EXECUTE_READWRITE, &old);
        memcpy(EzSetInformationProcess, patch, sizeof(patch));
        VirtualProtect(EzSetInformationProcess, sizeof(BYTE), old, &old);
    }
    if (EzObject)
    {
        VirtualProtect(EzObject, sizeof(BYTE), PAGE_EXECUTE_READWRITE, &old);
        memcpy(EzObject, patch, sizeof(patch));
        VirtualProtect(EzObject, sizeof(BYTE), old, &old);
    }
    if (EzAdjustPrivilege)
    {
        VirtualProtect(EzAdjustPrivilege, sizeof(BYTE), PAGE_EXECUTE_READWRITE, &old);
        memcpy(EzAdjustPrivilege, patch, sizeof(patch));
        VirtualProtect(EzAdjustPrivilege, sizeof(BYTE), old, &old);
    }
    if (EzRaiseHardError)
    {
        VirtualProtect(EzRaiseHardError, sizeof(BYTE), PAGE_EXECUTE_READWRITE, &old);
        memcpy(EzRaiseHardError, patch, sizeof(patch));
        VirtualProtect(EzRaiseHardError, sizeof(BYTE), old, &old);
    }



    if (EzBlockInput)
    {
        VirtualProtect(EzBlockInput, sizeof(BYTE), PAGE_EXECUTE_READWRITE, &old);
        memcpy(EzBlockInput, patch, sizeof(patch));
        VirtualProtect(EzBlockInput, sizeof(BYTE), old, &old);
    }
    if (EzFindWindowA)
    {
        VirtualProtect(EzFindWindowA, sizeof(BYTE), PAGE_EXECUTE_READWRITE, &old);
        memcpy(EzFindWindowA, patch, sizeof(patch));
        VirtualProtect(EzFindWindowA, sizeof(BYTE), old, &old);
    }
    if (EzFindWindowW)
    {
        VirtualProtect(EzFindWindowW, sizeof(BYTE), PAGE_EXECUTE_READWRITE, &old);
        memcpy(EzFindWindowW, patch, sizeof(patch));
        VirtualProtect(EzFindWindowW, sizeof(BYTE), old, &old);
    }
    if (EzFindWindow)
    {
        VirtualProtect(EzFindWindow, sizeof(BYTE), PAGE_EXECUTE_READWRITE, &old);
        memcpy(EzFindWindow, patch, sizeof(patch));
        VirtualProtect(EzFindWindow, sizeof(BYTE), old, &old);
    }

    cout << "\n[+] Successfully Patched\n";
 
}

BOOL APIENTRY DllMain( HMODULE hModule,DWORD  ul_reason_for_call,LPVOID lpReserved)
{
    
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        SetConsoleTitle(TEXT("Patcher | ReverseSec"));
        Sleep(500);
        CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)patch, nullptr, 0, nullptr);
        break;
    }
    return TRUE;
}

