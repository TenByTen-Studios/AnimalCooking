#pragma once
#include "Component.h"
#include "Texture.h"

class Transform;

class SliderBehaviour : public Component
{
protected:
	Texture* sliderBackground;
	Texture* sliderMovePoint;
	Transform* transform;

public:
	SliderBehaviour() : Component(ecs::SliderBehaviour), sliderBackground(nullptr), sliderMovePoint(nullptr), transform(nullptr) {}

	void update();
};

