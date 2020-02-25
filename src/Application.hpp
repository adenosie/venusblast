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

#ifndef VBLAST_APPLICATION
#define VBLAST_APPLICATION

#include <chrono>
#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Scene.hpp"

namespace vblast
{


class Application
{
public:

    Application();
    Application(std::unique_ptr<Scene>&& init_scene);

    void main_loop();

private:

    void process_events();
    void update(double dt);
    void render();

    sf::RenderWindow m_window;

    std::unique_ptr<Scene> m_scene;
};


}

#endif
