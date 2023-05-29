#pragma once
#include "imgui.h"
#include "imgui_impl_opengl3.h"
#include "imgui_impl_win32.h"
#include <Windows.h>
#include <gl/GL.h>
#include "MinHook.h"
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

typedef bool (*WINAPI funcWglSwapBuffers)(HDC);
typedef void(*SwapBufferCallback)(HDC);
typedef void(*RENDER)(void);
typedef void(*CONFIG_CALLBACK)(ImGuiIO& io);
bool hookSwapBuffers(HDC hdc);
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
void initHook();
void SetGui(RENDER callback , DWORD button);
void SetSwapHook(SwapBufferCallback callback);
void SetConfig(CONFIG_CALLBACK callbak);
void deleteHook();





