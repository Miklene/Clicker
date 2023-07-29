#include <stdio.h> 
#include <Windows.h> 
#include <WinUser.h> 
int main(void)
{
	printf("Hello world!");
	double x_resolution = 65535 / 1920;
	double y_resolution = 65535 / 1080;
	int x = 100 * x_resolution;
	int y = 100 * y_resolution;
	char mes = getchar();
	mouse_event(MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, x, y, 0, 0);
	mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
	mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
	return 0;
}