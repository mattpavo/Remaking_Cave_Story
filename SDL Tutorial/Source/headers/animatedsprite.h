#pragma once
#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

#include "sprite.h"
#include "globals.h"
#include <map>
#include <string>
#include <vector>

class Graphics;

/* AnimatedSprite class
* Holds logic for animating sprites
*/
class AnimatedSprite : public Sprite {
public:
	AnimatedSprite();
	AnimatedSprite(Graphics &graphics, const std::string &filepath,
		int sourceX, int sourceY, int width, int height,
		float posX, float posY, float timeToUpdate);

	/*void playAnimation
	Plays the animation provided if it's not already playing
	*/
	void playAnimation(std::string animation, bool once = false);

	/* void update
	Updates the animated sprite (timer)
	*/
	void update(int elapsedTime);

	/* void draw
	Draws the sprite to the screen
	*/
	void draw(Graphics &graphics, int x, int y);

protected:
	double _timetoUpdate;
	bool _currentAnimationOnce;
	std::string _currentAnimation;

	/* void addAnimation
	Adds an animation to the map of animations for the sprite
	*/
	void addAnimation(int frames, int x, int y, std::string name, int width, int height, Vector2 offset);

	/* void resetAnimation
	Resets all animations associated with this sprite
	*/
	void resetAnimation();

	/* void stopAnimation
	Stops the current animation
	*/
	void stopAnimation();

	/* void setVisible
	Changes the visibility of the current sprite
	*/
	void setVisible(bool visible);

	/* void animationDone
	Logic that happens when an animation ends
	*/
	virtual void animationDone(std::string currentAnimation) = 0;

	/* void setupAnimation
	A required function that sets up all animations for a sprite
	*/
	virtual void setupAnimations() = 0;

private:
	// holds animations
	std::map<std::string, std::vector<SDL_Rect> > _animations;

	std::map<std::string, Vector2> _offsets;

	int _frameIndex;
	double _timeElapsed = 0.0;
	bool _visible;

};

#endif 