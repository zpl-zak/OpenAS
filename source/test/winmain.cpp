/*
	The MIT License

	Copyright (c) 2014 Aurora Internet

	Permission is hereby granted, free of charge, to any person
	obtaining a copy of this software and associated documentation
	files (the "Software"), to deal in the Software without
	restriction, including without limitation the rights to use,
	copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the
	Software is furnished to do so, subject to the following
	conditions:

	The above copyright notice and this permission notice shall be
	included in all copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.
*/

#include<Windows.h>
#include <stdio.h>
#include <io.h>
#include <fcntl.h>

#include<system\oas_game.h>

using namespace OpenAS::System;

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nShowCmd)
{
	// Enable console
	//
	AllocConsole();

    HANDLE handle_out = GetStdHandle(STD_OUTPUT_HANDLE);
    int hCrt = _open_osfhandle((long) handle_out, _O_TEXT);
    FILE* hf_out = _fdopen(hCrt, "w");
    setvbuf(hf_out, NULL, _IONBF, 1);
    *stdout = *hf_out;

    HANDLE handle_in = GetStdHandle(STD_INPUT_HANDLE);
    hCrt = _open_osfhandle((long) handle_in, _O_TEXT);
    FILE* hf_in = _fdopen(hCrt, "r");
    setvbuf(hf_in, NULL, _IONBF, 256);
    *stdin = *hf_in;

	// Test code
	//
	Game g = Game("OpenAS Test Window");
	//g.dlltest();


	if(g.GetEntityManager()->CreateEntity("Player","playerscript",OpenAS::Util::Vector3D(0.0f,0.0f,0.0f),OpenAS::Util::Vector3D(0.0f,.0f,.0f),"PlayerModel")==-1){
		printf("ah");
	}
	g.GetEntityManager()->CreateEntity("Auto","",OpenAS::Util::Vector3D(0.0f,0.0f,5.0f),OpenAS::Util::Vector3D(0.0f,.0f,.0f),"AutoModel");
	g.GetEntityManager()->CreateEntity("Enemy","",OpenAS::Util::Vector3D(0.0f,0.0f,5.0f),OpenAS::Util::Vector3D(0.0f,.0f,.0f),"EnemyModel");

	g.GetEntityManager()->DestroyEntity(g.GetEntityManager()->GetEntityByName("Auto")->GetID());

	//std::cout <<  g.GetEntityManager()->GetEntityCount();

	//g.GetLogManager()->AddLog("TestEntity",g.GetEntityManager()->GetEntityByName("Enemy")->GetEntityName(),time(NULL),1,"entity.txt");
	//g.GetLogManager()->AddErrorLog("ERR_SUCCESS","",time(NULL),1,"openlog.txt");
	system("pause>nul");
	return 0;
}