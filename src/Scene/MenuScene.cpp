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

#include "Scene/MenuScene.hpp"
#include "Scene/TitleScene.hpp"
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Color.hpp>


namespace vblast
{


void MenuScene::handle_event(const sf::Event& event)
{
    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        notice_change<TitleScene>();
}


void MenuScene::update(double dt)
{
    
}


void MenuScene::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.clear(sf::Color::Cyan);
}


}
