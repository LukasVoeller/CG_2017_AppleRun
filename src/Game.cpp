//
//  Game.cpp
//  Spiellogik
//
//  Created by Sandra Tieben on 20.02.18.
//  Copyright © 2018 Philipp Lensing. All rights reserved.
//

#include "Game.h"

Game::Game() {
	
}

Game::~Game() {
	
}

bool Game::start(Tank* character, CoinList coins) {
	std::cout << "Init Game..." << std::endl;
	
	CoinList::iterator it;
	// alle gesammelten Coins wieder positionieren
	for(it = coins.begin(); it != coins.end(); ++it){
		if((*it)->isCollected()) {
			(*it)->setCollected(false);
			std::cout << "reset" << std::endl;
			Matrix t;
			
			(*it)->setLocalTransform(Vector((*it)->getLatestPosition().X, 0, (*it)->getLatestPosition().Z), Vector(0, 1, 0), 0);
		}
	}
	//Figur wieder auf den Startpunkt
	Matrix m;
	m = m.translation(START_POS_X, START_POS_Y, START_POS_Z);
	character->transform(m);
	
	character->setHovering(false);
	character->setIsInAir(false);
	
	return true;
}