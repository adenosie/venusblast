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

#include "Scene.hpp"


namespace vblast
{


bool Scene::should_close() const
{
    return m_close;
}


bool Scene::should_change() const
{
    return m_target != nullptr;
}


std::unique_ptr<Scene>&& Scene::get_target()
{
    return std::move(m_target);
}


void Scene::notice_close(bool flag)
{
    m_close = flag;
}


void Scene::notice_change(std::unique_ptr<Scene>&& target)
{
    m_target = std::move(target);
}


}
