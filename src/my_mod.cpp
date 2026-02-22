#include <windows.h>
#include "modding_api.h"

constexpr uintptr_t isAtiOffset = 0x110FBB8;

DWORD WINAPI MyModCode(LPVOID) {
    HMODULE hModule = GetModuleHandleA("mio.exe");
    if (!hModule) {
        LogMessage("ERROR: Failed to get mio.exe module handle!");
        return 0;
    }

    const auto baseAddr = reinterpret_cast<uintptr_t>(hModule);
    const auto playerIsAtiPtr = reinterpret_cast<void *>(baseAddr + isAtiOffset);

    while (true) {
        Sleep(10); // Update every 10ms

        if (const f32x3 loc = GetPlayerLocation(); loc.x == -1.0f || loc.y == -1.0f) {
            continue; // Wait until save is loaded
        }

        WriteMemoryTyped(playerIsAtiPtr, static_cast<byte>(1));
        Sleep(1000); // Sleep 1s
    }
    return 0;
}

extern "C" __declspec(dllexport) void ModInit() {
    LogMessage("\"Mio Purple\" mod loaded!");

    // Start monitoring thread
    CreateThread(nullptr, 0, MyModCode, nullptr, 0, nullptr);
}

BOOL APIENTRY DllMain(HMODULE, DWORD, LPVOID) {
    // Mods don't need to do anything in DllMain
    return TRUE;
}
