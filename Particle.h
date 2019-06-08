// Particle.h*

#pragma once

#include "Screen.h"

namespace jrv
{
	struct Particle
	{
		double m_x;
		double m_y;

		double randSpeed;

		double randDirection;
	
		Particle();
		~Particle();
		
		void update(int interval);

	};

}

