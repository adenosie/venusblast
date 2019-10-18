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

#ifndef VBLAST_APPLICATION_HPP
#define VBLAST_APPLICATION_HPP

#include <chrono>
#include <thread>
#include "SFML/Graphics/RenderWindow.hpp"
#include "GameScene.hpp"

namespace vblast
{


class Application
{
public:

    Application();

    void main_loop();

private:

    void render_loop();

    void process_events();
    void update(double& lag);
    void draw();

    sf::RenderWindow m_window;
    GameScene m_scene;    
};


}

#endif
