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

#include "Application.hpp"


namespace vblast
{


Application::Application()
    : m_window(sf::VideoMode(1280, 720), L"Venusblast")
{
    m_window.setVerticalSyncEnabled(true);
}


void Application::main_loop()
{
    auto prev = std::chrono::steady_clock::now();
    auto curr = prev;
    double interval = 0.;

    while(m_window.isOpen())
    {
        curr = std::chrono::steady_clock::now();
        interval = std::chrono::duration<double>(curr - prev).count();
        prev = curr;

        process_events();
        update(interval);
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
        
        m_comp.handle_event(event);
    }
}


void Application::update(double dt)
{
    m_comp.update(dt);

    if(m_comp.should_close())
        m_window.close();
}


void Application::render()
{
    m_window.clear();
    m_comp.render_into(m_window);
    m_window.display();
}


}
