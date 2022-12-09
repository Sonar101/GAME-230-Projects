/* My Classes */
#include "Game.h"

/* Namespaces */
using namespace gm;

/* Functions */
// Main, our applicaiton entry function
int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    Game game;

    game.run();

    // The game has exited normally so send a normal exit status integer back
    return 0;
}