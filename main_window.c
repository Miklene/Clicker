#include "main_window.h"

#include <Windows.h>
#include <WinUser.h>

static const wchar_t CLASS_NAME[] = L"Sample Window Class";
static const wchar_t WINDOW_NAME[] = L"Clicker";

void MainWindow_Init(void)
{
	HINSTANCE hinstance = GetModuleHandleW(NULL);

	WNDCLASS wcl;
	memset(&wcl, 0, sizeof(WNDCLASS));
	wcl.lpfnWndProc = DefWindowProc;
	wcl.hInstance = hinstance;
	wcl.lpszClassName = CLASS_NAME;
	
	RegisterClass(&wcl);

	HWND hwnd;
	hwnd = CreateWindowEx(0, CLASS_NAME, WINDOW_NAME, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hinstance, NULL);
	/*if (hwnd == NULL)
	{
		return 0;
	}*/
	ShowWindow(hwnd, SW_SHOWNORMAL);
}

void MainWindow_Cycle(void)
{
	MSG msg;
	if (GetMessage(&msg, NULL, 0, 0))
	{
		DispatchMessage(&msg);
	}
}
