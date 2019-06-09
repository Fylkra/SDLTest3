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
		const static int N_PARTICLES = 10000;

	private:
		jrv::Particle* mp_particles;
		int lastTime;

	public:
		const jrv::Particle* const getParticles()
		{
			return mp_particles;
		}

		void update(int elapsed);
	};

}


