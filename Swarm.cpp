// Swarm.cpp*

#include "Swarm.h"


jrv::Swarm::Swarm()
{
	mp_particles = new Particle[N_PARTICLES];
}

jrv::Swarm::~Swarm()
{
	delete[] mp_particles;
}

void jrv::Swarm::update()
{
	for (int i = 0; i < N_PARTICLES; i++)
	{
		mp_particles[i].update();

	}
}



