#include "Scene.hpp"


namespace vblast
{


bool Scene::should_close() const
{
    return m_close;
}


Scene* Scene::get_target() const
{
    return m_target;
}


void Scene::post_closed(bool flag)
{
    m_close = flag;

    if(flag)
        m_target = nullptr;
}


void Scene::set_target(Scene* target)
{
    if(!target || target == this)
        return;

    m_close = false;
    m_target = target;
}


}
