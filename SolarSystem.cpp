#include <FL/gl.h>
#include <FL/glut.h>
#include "SolarSystem.h"

#define SEGMENTS 20

SolarSystem::SolarSystem(){

}

SolarSystem::~SolarSystem(){

}

// Render this with push and pop operations
// or alternatively implement helper functions
// for each of the planets with parameters.
void SolarSystem::render(){
	
	// Some ideas for constants that can be used for
	// rotating the planets.
	static float rotation = 0.1;
	static float orbitSpeed = 0.15;
	static float moonOrbitX = 0.1;
	static float moonOrbitY = 0.1;
	static float moonOrbitSpeed = 1;

	glPushMatrix();

		// The Sun
		glPushMatrix();
				glRotatef(orbitSpeed,0,0,1);
			glColor3f(0.96f,0.85f,0.26f);
			glutSolidSphere(0.12, SEGMENTS, SEGMENTS);
		glPopMatrix();

		// y = green, x = red, z = blue

		float ring1    = 0.19;
		float ring2   = 0.3;
		float ring3    = 0.4;
		float ring4   = 0.5;
		float ring5    = 0.7;
		float ring6    = 0.9;

		// one
		glPushMatrix();
			glRotatef(orbitSpeed * 6, 0, 1, 0);
			glTranslatef(-ring1, 0, 0);
			glColor3f(0.60f,0.10f,0.9f);
			glScalef(.3f, .3f, .3f);
			glutSolidSphere(0.1, SEGMENTS, SEGMENTS);
		glPopMatrix();

		// two
		glPushMatrix();
			glRotatef(orbitSpeed * 5, 0, 1, 0);
			glTranslatef(-ring2, 0, 0);
			glColor3f(0.80f,0.40f,0.2f);
			glScalef(.5f, .5f, .5f);
			glutSolidSphere(0.1, SEGMENTS, SEGMENTS);
		glPopMatrix();
		
		// three
		glPushMatrix();
			glRotatef(orbitSpeed * 4, 0, 1, 0);
			glTranslatef(-ring3, 0, 0);
			glColor3f(0.40f,0.10f,0.2f);
			glScalef(.4f, .4f, .4f);
			glutSolidSphere(0.1, SEGMENTS, SEGMENTS);
		glPopMatrix();

		// four
		glPushMatrix();
			glRotatef(orbitSpeed * 3, 0, 1, 0);
			glTranslatef(-ring4, 0, 0);
			glColor3f(0,0.80f,0.25f);
			glScalef(.5f, .5f, .5f);
			glutSolidSphere(0.1, SEGMENTS, SEGMENTS);
		glPopMatrix();

		// five
		glPushMatrix();
			glRotatef(orbitSpeed * 2, 0, 1, 0);
			glTranslatef(-ring5, 0, 0);	
			glColor3f(1.0f,0.4f,0.4f);
			glScalef(.7f, .7f, .7f);
			glutSolidSphere(0.1, SEGMENTS, SEGMENTS);
			glPushMatrix();
				glRotatef(orbitSpeed * 4, 0, 0, 1);
				glTranslatef(-ring1, 0, 0);	
				glColor3f(0.9f, 0.9f, 0.9f);
				glScalef(0.4f, 0.4f, 0.4f);
				glutSolidSphere(0.1, SEGMENTS, SEGMENTS);
			glPopMatrix();
			glPushMatrix();
				glRotatef(orbitSpeed * 6, 1, 1, 0);
				glTranslatef(-ring1, 0, 0);	
				glColor3f(0.5f, 0.5f, 0.5f);
				glScalef(0.3f, 0.3f, 0.3f);
				glutSolidSphere(0.1, SEGMENTS, SEGMENTS);
			glPopMatrix();
		glPopMatrix();

		// six
		glPushMatrix();
			glRotatef(orbitSpeed, 0, 1, 0);
			glTranslatef(-ring6, 0, 0);
			glColor3f(0.30f, 0.50f, 0.9f);
			glutSolidSphere(0.1, SEGMENTS, SEGMENTS);
			glPushMatrix();
				glRotatef(orbitSpeed * 5, 0, 0, 1);
				glTranslatef(-ring1, 0, 0);	
				glColor3f(0.7f, 0.7f, 0.7f);
				glScalef(0.3f, 0.3f, 0.3f);
				glutSolidSphere(0.1, SEGMENTS, SEGMENTS);
			glPopMatrix();
		glPopMatrix();


	// Add more planets, moons, and rings here!	

	glPopMatrix();

	rotation+= 0.01;
	orbitSpeed+=0.2;
	moonOrbitX+=moonOrbitSpeed;
	moonOrbitY+=moonOrbitSpeed;

}

void SolarSystem::draw_circle(float radius) {
	float x, y;

	glDisable(GL_LIGHTING);
	glBegin(GL_LINES);
	glColor4f(0.5f, 0.5f, 0.5f, 0.8f);

	x = (float)radius * cos(359 * PI / 180.0f);
	y = (float)radius * sin(359 * PI / 180.0f);
	for (int j = 0; j < 360; j++)
	{
		glVertex3f(x, 0, y);
		x = (float)radius * cos(j * PI / 180.0f);
		y = (float)radius * sin(j * PI / 180.0f);
		glVertex3f(x, 0, y);
	}
	glEnd();
	glEnable(GL_LIGHTING);
}

void SolarSystem::draw_orbits() {
	draw_circle(0.2f);
	draw_circle(0.3f);
	draw_circle(0.4f);
	draw_circle(0.5f);
	draw_circle(0.7f);
	draw_circle(0.9f);
}
