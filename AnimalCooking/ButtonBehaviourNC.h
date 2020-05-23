#pragma once
#include "Component.h"
#include "Transform.h"
#include "MapConfig.h"
#include <functional>
class ButtonRenderer;
class AnimalCooking;

class ButtonBehaviourNC : public Component{
public:
	ButtonBehaviourNC(Entity * infoBox, levelInfo info);
	ButtonBehaviourNC(bool profilechooser, const string& name = "");
	void setButtonRenderer(ButtonRenderer* bR) { bRenderer_ = bR; }

	void init() override;
	void update() override; 
	const bool& getFocusByMouse() { return focusedByMouse_; }
	const bool& getFocusByController() { return focusedByController_; }
	void setFocusByController(bool f);
	void action();
	inline bool isActive() { return active_; }
	inline void setActive(bool active) { active_ = active; }

	inline const string& getName() const { return name_; }

private:
	levelInfo mapInfo_;
	Entity* infoBox_;
	bool active_;
	bool focusedByMouse_, focusedByController_;
	int action_;
	Transform* ownerTransform_;
	AnimalCooking* ac_;
	ButtonRenderer* bRenderer_;

	string name_;
};