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

#include "Application.hpp"
#include "Scene/TitleScene.hpp"


namespace vblast
{


Application::Application()
    : Application(std::make_unique<TitleScene>())
{
}


Application::Application(std::unique_ptr<Scene>&& init_scene)
    : m_window(
            sf::VideoMode::getFullscreenModes()[0],
            L"Venusblast",
            sf::Style::Fullscreen
            ),
      m_scene(std::move(init_scene))
{
}


void Application::main_loop()
{
    auto prev = std::chrono::steady_clock::now();
    auto curr = prev;
    double dt = 0.; // delta time

    while(m_window.isOpen())
    {
        curr = std::chrono::steady_clock::now();
        dt = std::chrono::duration<double>(curr - prev).count();
        prev = curr;

        process_events();
        update(dt);
        render();
    }
}


void Application::process_events()
{
    sf::Event event;
    while(m_window.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
            m_window.close();
        
        m_scene->handle_event(event);
    }
}


void Application::update(double dt)
{
    m_scene->update(dt);

    if(m_scene->should_change())
        m_scene = std::move(m_scene->get_target());
    if(m_scene->should_close())
        m_window.close();
}


void Application::render()
{
    m_window.clear();
    m_window.draw(*m_scene);
    m_window.display();
}


}
