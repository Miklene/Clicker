#include <stdio.h> 
#include <Windows.h> 
#include <WinUser.h> 
#include "main_window.h"


int main(void)
{
	//printf("Hello world!");
	double x_resolution = 65535 / 1920;
	double y_resolution = 65535 / 1080;
	int x = 100 * x_resolution;
	int y = 100 * y_resolution;

	MainWindow_Init();
	//MainWindow_SetLabelScreenResolutionText(L"Разрешение экрана: 1920x1080");
	MainWindow_AddItemToClickerList("Click1");
	MainWindow_AddItemToClickerList("Click2");
	MainWindow_AddItemToClickerList("Click3");
	while (1)
	{
		MainWindow_Cycle();
	}

	/*char mes = getchar();
	mouse_event(MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, x, y, 0, 0);
	mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
	mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);*/

	
	return 0;
}