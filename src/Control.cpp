//
//  Control.cpp
//  Steuerung des Characters
//
//  Created by Sandra Tieben on 20.02.18.
//  Copyright © 2018 Philipp Lensing. All rights reserved.
//


#include "Control.h"

Control::Control() {
	
}

Control::Control(GLFWwindow* pWin):pWindow(pWin) {
	
}

Control::~Control() {
	
}

float Control::readForwardBackward() {
	forwardBackward = 0.0f;
	float speed = (glfwGetKey(pWindow, GLFW_KEY_LEFT_SHIFT ) == GLFW_PRESS) ? ADDSPEED : 0.0f;
	
	// Move forward
	if (glfwGetKey(pWindow, GLFW_KEY_UP ) == GLFW_PRESS){
		speed += RUNSPEED;
		forwardBackward += speed;
	}
	// Move backward
	if (glfwGetKey(pWindow, GLFW_KEY_DOWN ) == GLFW_PRESS){
		speed += RUNSPEED;
		forwardBackward -= speed;
	}
	return forwardBackward;
}

float Control::readLeftRight(){
	leftRight = 0.0f;
	if (glfwGetKey(pWindow, GLFW_KEY_RIGHT ) == GLFW_PRESS){
		leftRight -= ROTATIONSPEED;
	}
	if (glfwGetKey(pWindow, GLFW_KEY_LEFT ) == GLFW_PRESS){
		leftRight += ROTATIONSPEED;
	}
	return leftRight;
}

float Control::readJump(Tank* character) {
	if(!character->getIsInAir() && glfwGetKey(pWindow, GLFW_KEY_SPACE ) == GLFW_PRESS){
		character->setIsInAir(true);
		jumpPower = JUMPPOWER;
	}
	return jumpPower;
}

void Control::handleJump(Tank* character)
{
	if(character->getLatestPosition().Y <= TERRAIN_HEIGHT + DELTA || character->getPalette() != NULL){
		character->setIsInAir(false);
		jumpPower = 0.0f;
	} else {
		jumpPower += GRAVITY * 0.1f;
		std::cout << "DownForce " << jumpPower << std::endl;
	}
}
