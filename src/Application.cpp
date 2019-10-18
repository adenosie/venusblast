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
    // for short length
    using clock = std::chrono::steady_clock;

    auto prev = clock::now();
    auto curr = prev;
    double lag = 0.;

    m_window.setActive(false);
    std::thread render_thread(&Application::render_loop, this);
    
    // i don't know why
    std::this_thread::sleep_for(std::chrono::duration<double>(.1));

    while(m_window.isOpen())
    {
        curr = clock::now();
        lag += std::chrono::duration<double>(curr - prev).count();
        prev = curr;

        process_events();
        update(lag);
    }

    render_thread.join();
}


void Application::render_loop()
{
    m_window.setActive(true);

    while(m_window.isOpen())
    {
        draw();
    }
}


void Application::process_events()
{
    sf::Event e;
    while(m_window.pollEvent(e))
    {
        m_scene.handle_event(e);

        if(e.type == sf::Event::Closed)
            m_window.close();
    }
}


void Application::update(double& lag)
{
    while(lag >= m_scene.tick())
    {
        m_scene.update();
        lag -= m_scene.tick();
    }
}


void Application::draw()
{
    m_window.clear();
    m_window.draw(m_scene);
    m_window.display();
}


}
