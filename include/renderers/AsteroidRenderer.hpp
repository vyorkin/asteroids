#pragma once

#include "Base.hpp"
#include "renderers/Renderer.hpp"
#include "components/Position.hpp"
#include "components/Geometry.hpp"
#include "components/appearance/AsteroidAppearance.hpp"

class AsteroidRenderer: public Renderer {
    public:
        virtual void render(Entity* entity, const float delta) override;
};
