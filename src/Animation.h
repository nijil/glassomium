/*
   Glassomium - web-based TUIO-enabled window manager
   http://www.glassomium.org

   Copyright 2012 The Glassomium Authors

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/
   
#ifndef ANIMATION_H
#define ANIMATION_H

#include "stdafx.h"
#include "UIManager.h"
#include "AnimatedObject.h"

using namespace pt;

class Animation{
public:
	Animation(AnimatedObject *object, void(*animationEndedCallback)(AnimatedObject *));
	virtual ~Animation();
	
	void start();
	virtual void animate() = 0;
	void notifyAnimationEnded();
	void postAnimate();
protected:
	void(*animationEndedCallback)(AnimatedObject *);
	AnimatedObject *object;
	sf::Thread *thread;
};

#endif
