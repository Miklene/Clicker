#include <stdio.h> 
#include <Windows.h> 
#include <WinUser.h> 

LRESULT WndProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam)
{
	if (message == WM_DESTROY)
		PostQuitMessage(0);
	return DefWindowProcA(hwnd, message, wparam, lparam);
}
const wchar_t CLASS_NAME[] = L"Sample Window Class";
const wchar_t WINDOW_NAME[] = L"Clicker";

int main(void)
{
	//printf("Hello world!");
	double x_resolution = 65535 / 1920;
	double y_resolution = 65535 / 1080;
	int x = 100 * x_resolution;
	int y = 100 * y_resolution;
	HINSTANCE hinstance = GetModuleHandleW(NULL);
	//WinMain(hinstance, NULL, GetCommandLineW(), 0);
	/*char mes = getchar();
	mouse_event(MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, x, y, 0, 0);
	mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
	mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);*/

	WNDCLASS wcl;
	memset(&wcl, 0, sizeof(WNDCLASS));
	wcl.lpfnWndProc = DefWindowProc;
	wcl.hInstance = hinstance;
	wcl.lpszClassName = CLASS_NAME;
	//wcl.lpfnWndProc = DefWindowProcA;
	RegisterClass(&wcl);

	HWND hwnd;
	hwnd = CreateWindowEx(0, CLASS_NAME, WINDOW_NAME, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hinstance, NULL);
	if (hwnd == NULL)
	{
		return 0;
	}
	ShowWindow(hwnd, SW_SHOWNORMAL);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		DispatchMessage(&msg);
	}
	return 0;
}