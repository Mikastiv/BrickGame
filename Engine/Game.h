/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "FrameTimer.h"
#include "Brick.h"
#include "Ball.h"
#include "Sound.h"
#include "Paddle.h"
#include <vector>

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel(float dt);
	/********************************/
	/*  User Functions              */
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	static constexpr float UPDATE_REFRESH_RATE = 0.0025f;
	static constexpr int NUMBER_BRICKS_ACROSS = 15;
	static constexpr int NUMBER_BRICKS_DOWN = 6;
	static constexpr int NUMBER_BRICKS = NUMBER_BRICKS_ACROSS * NUMBER_BRICKS_DOWN;
	static constexpr float BRICK_WIDTH = 50.0f;
	static constexpr float BRICK_HEIGHT = 25.0f;
	static constexpr float BALL_SPEED = 300.0f;
	static constexpr float PADDLE_WIDTH = 100.0f;
	static constexpr float PADDLE_HEIGHT = 15.0f;
	static constexpr float PADDLE_SPEED = 400.0f;

	FrameTimer ft;
	Rectf walls;
	Brick bricks[NUMBER_BRICKS];
	Paddle paddle;
	Sound soundPad;
	Sound soundBrick;
	std::vector<Ball*> balls;
	/********************************/
};