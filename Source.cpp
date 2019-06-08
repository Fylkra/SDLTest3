// Source.cpp* -> This application will be used to learn how to use external libraries and to create a simple particle explosion graphic.

#include <iostream>
#include <time.h>
#include "Screen.h"
#include "Swarm.h"
#include "Particle.h"

int main(int argc, char* argv[])
{

	srand(time(NULL)); /* Seeding the random */

	jrv::Screen screen;


	// SDL Initialization test

	if (screen.init() == false)
	{
		std::cout << "Error initializing SDL! " << std::endl;
	}
	else
	{
		std::cout << "SDL successfully initialized! " << std::endl;
	}

	jrv::Swarm swarm;

	// Primary Loop/s

	while (true)
	{
		int elapsed = SDL_GetTicks();

		// Update Particles

		screen.clearScreen();

		swarm.update(elapsed);


		//Draw Particles 


		const int HALF_WIDTH = jrv::Screen::SCREEN_WIDTH / 2;

		const int HALF_HEIGHT = jrv::Screen::SCREEN_HEIGHT / 2;

		Uint8 red = std::abs(cos(elapsed * 0.000157) * 256);

		Uint8 green = std::abs(sin(elapsed * 0.000155) * 256);

		Uint8 blue = std::abs(sin(elapsed * 0.00053) * 256);

		const jrv::Particle* const p_particles = swarm.getParticles();

		for (int i = 0; i < jrv::Swarm::N_PARTICLES; i++)
		{
			jrv::Particle particle = p_particles[i];

			int x = (particle.m_x + 1) * (HALF_WIDTH);

			int y = particle.m_y * HALF_WIDTH + HALF_HEIGHT;

			screen.setPixel(x, y, red, green, blue);
		}

		//Draw the Screen

		screen.update();

		//Check for Messages and Events

		if (screen.processEvents() == false)
		{
			break;
		}

	}

	screen.close();



	return 0;
}