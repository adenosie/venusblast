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
#ifndef VBLAST_RESOURCEMANAGER
#define VBLAST_RESOURCEMANAGER

#include <memory>
#include <filesystem>
#include <map>


namespace vblast
{


template <typename R>
class ResourceManager
{
private:

    static std::shared_ptr<R>&& shared_from_path(const std::filesystem::path& filename)
    {
        if constexpr(
                !std::is_same_v<R, std::filesystem::path> &&
                std::is_constructible_v<R, const std::filesystem::path&>
                )
        {
            return std::make_shared<R>(filename);
        }
        else // for SFML resources (sf::Texture and sf::SoundBuffer)
        {
            // there will be an error right here if R isn't a resource type
            R* resource = new R();
            resource->load_from_file(filename.c_str());

            return std::shared_ptr<R>(resource);
        }
    }

public:

    void load(const std::filesystem::path& filename)
    {
        // !m_resources.contains(filename) in C++20
        if(auto it = m_resources.find(filename); it == m_resources.end())
            m_resources.insert(std::make_pair(filename, std::move(shared_from_path(filename))));
    }


    void remove(const std::filesystem::path& filename)
    {
        // m_resources.contains(filename)
        if(auto it = m_resources.find(filename); it != m_resources.end())
            m_resources.erase(it);
    }


    void refresh(const std::filesystem::path& filename)
    {
        // m_resources.contains(filename)
        if(auto it = m_resources.find(filename); it != m_resources.end())
            *it = std::move(shared_from_path(filename));
    }


    void load_or_refresh(const std::filesystem::path& filename)
    {
        m_resources.insert_or_assign(std::make_pair(filename, std::move(shared_from_path(filename))));
    }


    bool contains(const std::filesystem::path& filename) const noexcept
    {
        return m_resources.find(filename) != m_resources.end();
    }


    std::shared_ptr<R> at(const std::filesystem::path& filename) const
    {
        if(auto it = m_resources.find(filename); it != m_resources.end())
            return *it;
        else
            return nullptr;
    }

    std::shared_ptr<R> operator[](const std::filesystem::path& filename)
    {
        if(auto it = m_resources.find(filename); it != m_resources.end())
        {
            return *it;
        }
        else
        {
            it = m_resources.insert(std::make_pair(filename, shared_from_path(filename))).first;
            return *it;
        }
    }

private:

    std::map<std::filesystem::path, std::shared_ptr<R>> m_resources;

};


}
#endif
