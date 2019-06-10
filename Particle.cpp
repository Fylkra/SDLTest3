// Particle.cpp*

#include "Particle.h"
#include <iostream>

jrv::Particle::Particle() : m_x(0), m_y(0)
{
	randDirection = (2 * M_PI * rand()) / RAND_MAX;

	randSpeed = (0.008 * rand()) / RAND_MAX;

	randSpeed *= randSpeed;
}

jrv::Particle::~Particle()
{

}

void jrv::Particle::update(int interval)
{
	randDirection += interval * 0.0002; // this changes the "spin". At 0, radiating from 0 with no twist.

	double xVelocity = randSpeed * cos(randDirection);

	double yVelocity = randSpeed * sin(randDirection);

	m_x += xVelocity * interval;

	m_y += yVelocity * interval;
};

