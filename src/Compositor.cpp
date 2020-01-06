/*
 * Copyright 2019-2020 Adenosie
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

#include "Compositor.hpp"
#include "TitleScene.hpp"


namespace vblast
{


Compositor::Compositor()
    : m_scene(std::make_unique<TitleScene>())
{
}


void Compositor::handle_event(const sf::Event& event)
{
    m_scene->handle_event(event);
}


void Compositor::update(double dt)
{
    m_scene->update(dt);

    if(m_scene->should_change())
        m_scene = std::move(m_scene->get_target());
}


void Compositor::render_into(
        sf::RenderTarget& target,
        const sf::RenderStates& states
        ) const
{
    m_scene->render_into(target, states);
}


bool Compositor::should_close() const
{
    return m_scene->should_close();
}


}
