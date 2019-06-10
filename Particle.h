// Particle.h*

#pragma once

#include "Screen.h"

namespace jrv
{
	struct Particle
	{
		double m_x;
		double m_y;


	private:
		double randSpeed;
		double randDirection;

	public:

		Particle();
		~Particle();
		void update(int interval);

	};

}

