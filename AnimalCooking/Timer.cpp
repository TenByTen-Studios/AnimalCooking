#include "Timer.h"
#include "SDL_macros.h"

Timer::Timer(): 
	game_(SDLGame::instance()),
	texture_(nullptr),
	time_(0),
	startedTime_(0),  
	timerEnd_(false), 
	timerStarted_(false),
	pos_(), 
	size_(Vector2D(0, 5)), 
	rot_(0),
	renderer_(game_->getRenderer())
{

}

Timer::~Timer() {
}

void Timer::update() {
	if (timerStarted_ && !timerEnd_) {
		if (game_->getTime() - startedTime_ >= time_) {
			timerEnd_ = true;
		}
		size_.setX((game_->getTime() - startedTime_)/100);
	}
}

void Timer::draw() {
	SDL_Rect rect = RECT(pos_.getX(), pos_.getY(), size_.getX(), size_.getY());

	SDL_SetRenderDrawColor(renderer_, 255, 0, 0, 255);
	SDL_RenderFillRect(renderer_, &rect);
}


void Timer::timerStart() {
	if (!timerStarted_) {
		timerStarted_ = true;
		startedTime_ = game_->getTime();
	} 
}

void Timer::timerReset() {
	startedTime_ = 0;
	timerStarted_ = false;
	timerEnd_ = false;
}

void LevelTimer::draw()
{
	SDL_Rect outline = RECT(pos_.getX(), pos_.getY(), (game_->getTime() - time_) / 100, size_.getY());

	Timer::draw();

	SDL_SetRenderDrawColor(renderer_, 255, 255, 255, 255);
	SDL_RenderDrawRect(renderer_, &outline);
}
