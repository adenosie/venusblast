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

#ifndef VBLAST_COMPOSITOR
#define VBLAST_COMPOSITOR

#include <memory>
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Audio/SoundBuffer.hpp"
#include "ResourceManager.hpp"
#include "Scene.hpp"


namespace vblast
{


class Compositor
{
public:

    Compositor();

    void handle_event(const sf::Event& event);
    void update(double dt);

    void render_into(
            sf::RenderTarget& target,
            const sf::RenderStates& states = sf::RenderStates::Default
            ) const;

    bool should_close() const;

private:

    void switch_scene(std::unique_ptr<Scene>&& scene);

    void notify_close(bool flag = true);

    bool m_close = false;

    ResourceManager<sf::Texture> m_textures;
    ResourceManager<sf::SoundBuffer> m_audios;

    std::unique_ptr<Scene> m_scene;
};


}

#endif
