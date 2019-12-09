/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
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
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	ball(Vec2(100.0f, 500.0f), Vec2(1.0f * BALL_SPEED, 1.0f * BALL_SPEED)),
	walls(0.0f, 0.0f, Graphics::ScreenWidth - 1, Graphics::ScreenHeight - 1),
	paddle(Vec2(400.0f, 550.0f), PADDLE_WIDTH, PADDLE_HEIGHT, PADDLE_SPEED),
	soundPad(L"Sounds\\arkpad.wav"),
	soundBrick(L"Sounds\\arkbrick.wav")
{
	const Color colors[NUMBER_BRICKS_DOWN] = { Colors::Cyan, Colors::Green, Colors::Magenta, Colors::Yellow, Colors::LightGray, Colors::Red };
	const Vec2 topLeftBricksArray = {25.0f, 25.0f};

	for (size_t y = 0; y < NUMBER_BRICKS_DOWN; y++)
	{
		for (size_t x = 0; x < NUMBER_BRICKS_ACROSS; x++)
		{
			bricks[y * NUMBER_BRICKS_ACROSS + x] = 
				Brick(Rectf(topLeftBricksArray + Vec2(x * BRICK_WIDTH, y * BRICK_HEIGHT), BRICK_WIDTH, BRICK_HEIGHT), colors[y]);
		}
	}
}

void Game::Go()
{
	gfx.BeginFrame();	
	float elapsedTime = ft.Mark();
	while (elapsedTime > 0.0f)
	{
		const float dt = std::min(UPDATE_REFRESH_RATE, elapsedTime);
		UpdateModel(dt);
		elapsedTime -= dt;
	}
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel(float dt)
{
	ball.Update(dt);
	paddle.Update(wnd.kbd, dt);

	float shortestCollisionDistSq;
	size_t shortestCollisionIndex;
	bool hasCollided = false;
	for (size_t i = 0; i < NUMBER_BRICKS; i++)
	{
		if (bricks[i].CheckBallCollision(ball))
		{
			const float currentDistSq = (bricks[i].GetCenterPosition() - ball.GetCenter()).GetLengthSq();
			if (!hasCollided)
			{
				shortestCollisionDistSq = currentDistSq;
				shortestCollisionIndex = i;
				hasCollided = true;
			}
			else
			{
				if (currentDistSq < shortestCollisionDistSq)
				{
					shortestCollisionIndex = i;
					shortestCollisionDistSq = currentDistSq;
				}
			}
		}
	}

	if (hasCollided)
	{
		bricks[shortestCollisionIndex].ExecuteBallCollision(ball);
		paddle.ResetCooldown();
		soundBrick.Play();
	}
	
	if (paddle.DoBallCollision(ball)) soundPad.Play();
	if (paddle.DoWallCollision(walls)) paddle.ResetCooldown();
	if (ball.DoWallCollision(walls))
	{
		paddle.ResetCooldown();
		soundPad.Play();
	}
}

void Game::ComposeFrame()
{
	ball.Draw(gfx);
	paddle.Draw(gfx);
	for (const Brick& b : bricks) b.Draw(gfx);
}
