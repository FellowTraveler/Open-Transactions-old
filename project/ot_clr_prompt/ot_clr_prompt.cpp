// ot_clr_prompt.cpp : main project file.

#include "stdafx.h"

using namespace System;
using namespace otapicli;

int main(array<System::String ^> ^args)
{
    Console::WriteLine(L"Hello World");
	Console::ReadLine();

	otapi_wrap a;
	a.LoadWallet();

	Console::ReadLine();

    return 0;
}
