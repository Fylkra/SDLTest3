// Particle.cpp*

#include "Particle.h"
#include <iostream>

jrv::Particle::Particle() : m_x(0), m_y(0)
{
	randDirection = (2 * M_PI * rand()) / RAND_MAX;

	randSpeed = (0.001 * rand()) / RAND_MAX;
}

jrv::Particle::~Particle()
{

}

void jrv::Particle::update()
{
	double xVelocity = randSpeed * cos(randDirection);

	double yVelocity = randSpeed * sin(randDirection);

	m_x += xVelocity;

	m_y += yVelocity;
};

