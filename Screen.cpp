// Screen.cpp*


#include <iostream>
#include "Screen.h"

using namespace std;

jrv::Screen::Screen() :

	m_window(NULL),

	m_renderer(NULL),

	m_texture(NULL),

	m_buffer(NULL)
{

}

bool jrv::Screen::init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)/* This does a test to confirm that SDL is correctly installed and linked to the cpp file */
	{
		return false;
	}


	m_window = SDL_CreateWindow("Particle Fire Explosion!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);


	if (m_window == NULL) /* If window doesn't open this closes all resources. */
	{
		SDL_DestroyWindow(m_window);
		SDL_Quit();

		return false;
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);

	if (m_renderer == NULL)
	{

		SDL_DestroyWindow(m_window);
		SDL_DestroyRenderer(m_renderer);
		SDL_Quit();

		return false;
	}

	m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

	if (m_texture == NULL)
	{

		SDL_DestroyTexture(m_texture);
		SDL_DestroyWindow(m_window);
		SDL_Quit();

		return false;

	}

	m_buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

	memset(m_buffer, 0x00, SCREEN_HEIGHT * SCREEN_WIDTH * sizeof(Uint32));

	for (int i = 0; i < SCREEN_HEIGHT * SCREEN_WIDTH; i++)
	{
		m_buffer[i] = 0x00000000;
	}



	return true;
}

bool jrv::Screen::processEvents()
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			return false;
		}

	}
	return true;
}

void jrv::Screen::close()
{
	delete[] m_buffer;

	SDL_DestroyTexture(m_texture);

	SDL_DestroyRenderer(m_renderer);

	SDL_DestroyWindow(m_window);

	SDL_Quit();
}

void jrv::Screen::update()
{
	SDL_UpdateTexture(m_texture, NULL, m_buffer, SCREEN_WIDTH * sizeof(Uint32));

	SDL_RenderClear(m_renderer);

	SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);

	SDL_RenderPresent(m_renderer);
}

void jrv::Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) // This function performs a Bit Shift and places each value then moves 8 bits to the "right".
{

	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT) // This skips any particle that is outside of range TODO: confirm lower range as x <= 0?
	{
		return;
	}

	Uint32 color = 0;

	color += red;

	color <<= 8;

	color += green;

	color <<= 8;

	color += blue;

	color <<= 8;

	color += 0xFF; // <- Color "Alpha" see SDL documentation for implementation.

	m_buffer[(y * SCREEN_WIDTH) + x] = color;

}

void jrv::Screen::clearScreen()
{
	memset(m_buffer, 0x00, SCREEN_HEIGHT * SCREEN_WIDTH * sizeof(Uint32));

}
