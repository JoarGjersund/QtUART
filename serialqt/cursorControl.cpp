#include "cursorControl.h"
//#include <Windows.h>


cursorControl::cursorControl()
{

}


cursorControl::~cursorControl()
{
}
/*
void cursorControl::moveCursor(int newx, int newy)
{
	
	Inputs[0].type = INPUT_MOUSE;
	Inputs[0].mi.dx = newx;
	Inputs[0].mi.dy = newy;
	Inputs[0].mi.dwFlags = MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE;

	Inputs[1].type = INPUT_MOUSE;
	Inputs[1].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;

	Inputs[2].type = INPUT_MOUSE;
	Inputs[2].mi.dwFlags = MOUSEEVENTF_LEFTUP;


	SendInput(3, Inputs, sizeof(INPUT));
	


}

int cursorControl::getX()
{
	return Inputs[0].mi.dx;
}

int cursorControl::getY()
{
	return Inputs[0].mi.dy;
}
*/