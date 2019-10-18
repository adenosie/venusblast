/*
 * Copyright 2019 Jinyoung Maeng
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
 *     Jinyoung Maeng <adenosiez@gmail.com>
 */

#ifndef VBLAST_SCENE_HPP
#define VBLAST_SCENE_HPP

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Drawable.hpp>

namespace vblast
{


class Scene : public sf::Drawable
{
public:

    enum State
    {
        Normal = 0,
        Navigate = 1 << 31
    };

    enum Type
    {
        Empty = 0,
        Title,
        Gameplay
    };

    virtual void handle_event(const sf::Event& event) = 0;
    virtual void update() = 0;

    inline double tick() const
    {
        return m_tick;
    }

    inline void notify(int state)
    {
        m_state = state;
    }

    inline int get_state() const
    {
        return m_state;
    }

protected:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates state) const = 0;

private:

    const double m_tick = 1. / 120.;
    int m_state = Normal;
};


}

#endif
