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

#include "TitleScene.hpp"
#include "MenuScene.hpp"


namespace vblast
{


TitleScene::TitleScene()
{
    auto& textures = ResourceManager<sf::Texture>::instance();

    m_tex_bg = textures["resources/title_bg.png"];
    m_background.setTexture(*m_tex_bg);
}


void TitleScene::handle_event(const sf::Event& event)
{
    if(event.type == sf::Event::KeyPressed)
    {
        if(event.key.code == sf::Keyboard::Escape)
            notice_close();
        else
            notice_change<MenuScene>();
    }
}


void TitleScene::update(double dt)
{
    
}


void TitleScene::render_into(sf::RenderTarget& target, const sf::RenderStates& states) const
{
    target.draw(m_background);
}


}
