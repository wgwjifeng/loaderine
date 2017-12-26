#pragma once

#include "peconv.h"
#include "buffered_dll_resolver.h"

extern HANDLE  (WINAPI *kernel32_OpenProcess)(
    _In_ DWORD dwDesiredAccess,
    _In_ BOOL bInheritHandle,
    _In_ DWORD dwProcessId
);

extern BOOL (WINAPI *kernel32_WriteProcessMemory)(
    _In_ HANDLE hProcess,
    _In_ LPVOID lpBaseAddress,
    _In_reads_bytes_(nSize) LPCVOID lpBuffer,
    _In_ SIZE_T nSize,
    _Out_opt_ SIZE_T * lpNumberOfBytesWritten
);

HMODULE load_kernel32(buffered_dlls_resolver *my_resolver);

bool init_kernel32_func(HMODULE lib);
