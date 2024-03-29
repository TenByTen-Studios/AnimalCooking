#pragma once
#include "Component.h"
#include "Transform.h"
#include "Entity.h"

class InteractionRect :	public Component
{
public:
	InteractionRect() ;
	~InteractionRect(){}

	void init() override;
	void update() override;

	void setDir	(double x, double y) { dir_.set(Vector2D(x, y)); }
	Vector2D getPos() { return pos_; }
	Vector2D getdir() { return dir_; }
	double getW() { return size_.getX(); }
	double getH() { return size_.getX(); }

private:
	double radius;
	Vector2D pos_;
	Vector2D dir_;
	Vector2D size_;
	Transform* tr_;
};

