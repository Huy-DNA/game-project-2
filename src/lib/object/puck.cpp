#include "object/puck.hpp"
#include "sprite.hpp"
#include "vector2d.hpp"
#include <SDL_rect.h>
#include <SDL_render.h>

Puck::Puck(Sprite sprite, Vector2d pos, float radius)
    : Object{sprite, pos, Vector2d{0, 0}, Vector2d{0, 0}, 0.05},
      _radius{radius} {}

bool Puck::doesCollide(const Bat &bat) const { return bat.doesCollide(*this); }

void Puck::setVelocity(const Vector2d v) {
  this->Object::setVelocity(v.cap(1));
}

float Puck::getSize() const { return _radius; }

Vector2d Puck::getCollisionPoint(const Bat &bat) const {
  return bat.getCollisionPoint(*this);
}
