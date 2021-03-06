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
   
#ifndef TWOFINGERGESTURE_H
#define TWOFINGERGESTURE_H

#include "stdafx.h"
#include "Gesture.h"

class TwoFingerGesture : public Gesture {
public:
	TwoFingerGesture(Phase phase);
	~TwoFingerGesture();

	static TwoFingerGesture *recognize(TouchGroup &, Gesture::Phase phase);
	virtual Type getGestureType(){ return TWOFINGER; }

	/** Return the location of the first touch (range 0..1) */
	sf::Vector2f getFirstTouchLocation() const { return firstTouchLocation; }

	/** Return the location of the second touch (range 0..1) */
	sf::Vector2f getSecondTouchLocation() const { return secondTouchLocation; }

private:
	sf::Vector2f firstTouchLocation;
	sf::Vector2f secondTouchLocation;
	void fillGestureData(const TouchGroup &touchGroup);
};

#endif
