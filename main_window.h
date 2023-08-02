#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <Windows.h>

#define CLICK_INFO_SIZE  25

void MainWindow_Init(void);
void MainWindow_Cycle(void);
void MainWindow_SetLabelScreenResolutionText(char text[]);
void MainWindow_AddItemToClickerList(char* item);
static void MainWindow_DisplayClickInfoItems(void);
#endif
