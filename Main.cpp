#include "game.h"
int main(int argc, char *args[])
{
	game *g = new game();
	g->init("Ammomatics", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1500, 600, false);

	const int FPS = 60;
	const int Frame_Delay = 1000 / FPS; // Expected Time between Frames

	Uint32 FrameStart;
	int frametime;

	long long int count = 0;
	while (g->Is_Running())
	{
		FrameStart = SDL_GetTicks();

		g->HandleEvents();
		if (count % 10 == 0)
		{
			g->generateObstacles();
		}
		g->update();
		g->render();

		frametime = SDL_GetTicks() - FrameStart; // Time between Frames
		if (Frame_Delay > frametime)			 // This will make the overall motion in the game smooth
		{
			SDL_Delay(Frame_Delay - frametime);
		}
		count++;
	}
	// std::cout << count << std::endl;
	g->clean();
	return (0);
}