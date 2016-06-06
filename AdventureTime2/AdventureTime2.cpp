// AdventureTime2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Game.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int _tmain(int argc, _TCHAR* argv[])
{
	AdventureTime::Game g;
	g.play();

	_CrtDumpMemoryLeaks(); //Visual studio specific
	return 0;
}

