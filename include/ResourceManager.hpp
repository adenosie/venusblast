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
public:

    // singleton
    static ResourceManager<R>& instance();

    void load(const std::filesystem::path& filename);
    void remove(const std::filesystem::path& filename);
    
    void refresh(const std::filesystem::path& filename);
    void load_or_refresh(const std::filesystem::path& filename);

    bool contains(const std::filesystem::path& filename) const;

    std::shared_ptr<R> at(const std::filesystem::path& filename) const;
    std::shared_ptr<R> operator[](const std::filesystem::path& filename);

private:

    ResourceManager() = default;
    static std::shared_ptr<R>&& shared_from_path(const std::filesystem::path& filename);

    std::map<std::filesystem::path, std::shared_ptr<R>> m_resources;

};


}

#include "ResourceManager.tcc"
#endif
