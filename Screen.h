// Screen.h*

#pragma once
#define SDL_MAIN_HANDLED
#include <SDL.h>

namespace jrv
{
	class Screen
	{
	public:
		const static int SCREEN_WIDTH = 1280;
		const static int SCREEN_HEIGHT = 1024;

	private:
		SDL_Window* m_window;

		SDL_Renderer* m_renderer;

		SDL_Texture* m_texture;

		Uint32* m_buffer;

	public:
		Screen();
		bool init();
		bool processEvents();
		void close();
		void update();
		void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
		void clearScreen();

	};
}


