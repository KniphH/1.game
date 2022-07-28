#pragma once
#include <Windows.h>
#include <conio.h>
void cls() {
  HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  DWORD writtenWord = 0;
  if(!GetConsoleScreenBufferInfo(hStdout, &csbi))
    return;
  if(!GetConsoleScreenBufferInfo(hStdout, &csbi))
    return;
  if (!FillConsoleOutputAttribute(hStdout,
                                  csbi.wAttributes,
                                  csbi.dwSize.X * csbi.dwSize.Y,
                                  { 0,0 },&writtenWord))
    return;
  SetConsoleCursorPosition(hStdout, { 0,0 });
}
