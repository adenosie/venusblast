/*
 * Copyright 2019 Adenosie
 *
 * This file is part of Venusblast.
 *
 * Venusblast is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * Venusblast is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Venusblast.  If not, see <https://www.gnu.org/licenses/>.
 * 
 * Author:
 *     Adenosie <adenosiez@gmail.com>
 */

#ifndef VBLAST_SCENE
#define VBLAST_SCENE

#include "SFML/Window/Event.hpp"
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/RenderStates.hpp"


namespace vblast
{


class Scene
{
public:

    virtual void handle_event(const sf::Event& event) = 0;
    virtual Scene* update(double dt) = 0;

    virtual void render_into(sf::RenderTarget& target, const sf::RenderStates& states) const = 0;
};


}

#endif
