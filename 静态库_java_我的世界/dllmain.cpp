// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"
#include "opengl_imgui/include/imgui_opengl_hook.h"


#pragma comment(lib , "opengl32.lib")
#pragma comment(lib , "libMinHook.x64.lib")
#pragma comment(lib , "opengl_imgui_x64.lib")

void ren()
{
    ImGui::Begin("pain1929");
    ImGui::End();
}

void run()
{
    initHook();
    SetGui(ren, VK_INSERT);
}
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        run();
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

