// Swarm.cpp*

#include "Swarm.h"


jrv::Swarm::Swarm() : lastTime(0)
{
	mp_particles = new Particle[N_PARTICLES];
}

jrv::Swarm::~Swarm()
{
	delete[] mp_particles;
}

void jrv::Swarm::update(int elapsed)
{
	int interval = elapsed - lastTime;

	for (int i = 0; i < N_PARTICLES; i++)
	{
		mp_particles[i].update(interval);
	}

	lastTime = elapsed;
}



