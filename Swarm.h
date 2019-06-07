#pragma once
// Swarm.h

#include "Particle.h"

namespace jrv
{
	class Swarm
	{
	public:
		Swarm();
		~Swarm();
		const static int N_PARTICLES = 5000;

	private:
		jrv::Particle* mp_particles;

	public:
		const jrv::Particle* const getParticles()
		{
			return mp_particles;
		}

		void update();
	};

}


