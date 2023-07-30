#include "main_window.h"

#include <Windows.h>
#include <WinUser.h>

static const wchar_t CLASS_NAME[] = L"Sample Window Class";
static const wchar_t WINDOW_NAME[] = L"Clicker";
RECT rect;
HDC hdc;
HWND labelScreenResolution;

void MainWindow_Init(void)
{
	HINSTANCE hinstance = GetModuleHandleW(NULL);

	WNDCLASS wcl;
	memset(&wcl, 0, sizeof(WNDCLASS));
	wcl.lpfnWndProc = DefWindowProc;
	wcl.hInstance = hinstance;
	wcl.lpszClassName = CLASS_NAME;
	
	RegisterClass(&wcl);

	//Создать окно
	HWND hwnd;
	hwnd = CreateWindowEx(0, CLASS_NAME, WINDOW_NAME, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hinstance, NULL);


	/*if (hwnd == NULL)
	{
		return 0;
	}*/
	ShowWindow(hwnd, SW_SHOWNORMAL);

	HWND btn = CreateWindowEx(0, L"button", L"Quit", WS_VISIBLE | WS_CHILD, 200, 200, 100, 50, hwnd, NULL, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);

	labelScreenResolution = CreateWindowEx(0, L"static", L"Разрешение экрана:", WS_VISIBLE | WS_CHILD, 10, 10, 175, 40, hwnd, NULL, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);	
}

void MainWindow_Cycle(void)
{
	MSG msg;
	if (GetMessage(&msg, NULL, 0, 0))
	{
		DispatchMessage(&msg);
	}
}

void MainWindow_SetLabelScreenResolutionText(char text[])
{
	SetWindowText(labelScreenResolution, text);
}
