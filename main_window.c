#include "main_window.h"

#include <string.h>

#include <Windows.h>
#include <WinUser.h>

static const wchar_t CLASS_NAME[] = L"Sample Window Class";
static const wchar_t WINDOW_NAME[] = L"Clicker";
RECT rect;
HDC hdc;
HWND labelScreenResolution;
HWND clickerList;

static wchar_t clickInfo[CLICK_INFO_SIZE][100];

static int clickinfo_counter;

void MainWindow_Init(void)
{
	clickinfo_counter = 0;

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

	labelScreenResolution = CreateWindowEx(0, L"STATIC", L"Разрешение экрана:", WS_VISIBLE | WS_CHILD, 10, 10, 175, 40, hwnd, NULL, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);

	clickerList = CreateWindowEx(0, L"LISTBOX", NULL, WS_VISIBLE | WS_CHILD | WS_VSCROLL | ES_AUTOVSCROLL | WS_BORDER, 50, 50, 175, 40, hwnd, NULL, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);
	/*for (int i = 0; i < 2; i++)
	{
		int pos = (int)SendMessage(clickerList, LB_ADDSTRING, 0,
			(LPARAM)clickInfo[i]);
		// Set the array index of the player as item data.
		// This enables us to retrieve the item from the array
		// even after the items are sorted by the list box.
		SendMessage(clickerList, LB_SETITEMDATA, pos, (LPARAM)i);
	}*/
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

void MainWindow_AddItemToClickerList(char *item)
{
	int i;
	if (clickinfo_counter < CLICK_INFO_SIZE)
	{
		for (i = 0; i < strlen(item); i++)
		{
			clickInfo[clickinfo_counter][i] = item[i];
		}
		int pos = (int)SendMessage(clickerList, LB_ADDSTRING, 0,
			(LPARAM)clickInfo[clickinfo_counter]);
		SendMessage(clickerList, LB_SETITEMDATA, pos, (LPARAM)clickinfo_counter);
		clickinfo_counter++;
	}
	
}

static void MainWindow_DisplayClickInfoItems(void)
{
	for (int i = 0; i < clickinfo_counter; i++)
	{
		int pos = (int)SendMessage(clickerList, LB_ADDSTRING, 0,
			(LPARAM)clickInfo[i]);
		// Set the array index of the player as item data.
		// This enables us to retrieve the item from the array
		// even after the items are sorted by the list box.
		SendMessage(clickerList, LB_SETITEMDATA, pos, (LPARAM)i);
	}
}