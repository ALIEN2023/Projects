#include <ctime>
#include "Game.h"
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    Game g;
    g.PlayGame();

    return 0;
}