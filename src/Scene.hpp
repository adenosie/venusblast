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

#ifndef VBLAST_SCENE
#define VBLAST_SCENE

#include <memory>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Drawable.hpp>


namespace vblast
{


class Scene : public sf::Drawable
{
public:

    // NOTE: every function should work well regardless
    // whether notice_close() or notice_change() is called
    virtual void handle_event(const sf::Event& event) = 0;
    virtual void update(double dt) = 0;

    bool should_close() const;
    bool should_change() const;

    // the pointer will be moved after the function is called
    std::unique_ptr<Scene>&& get_target();

protected:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

    void notice_close(bool flag = true);
    void notice_change(std::unique_ptr<Scene>&& target);

    template <typename S, typename... A>
    void notice_change(A... args);

private:

    bool m_close = false;
    std::unique_ptr<Scene> m_target = nullptr;

};


template <typename S, typename... A>
inline void Scene::notice_change(A... args)
{
    notice_change(std::make_unique<S>(args...));
}


}

#endif
