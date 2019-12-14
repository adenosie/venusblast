#include "SceneManager.hpp"


namespace vblast
{


bool SceneManager::should_close() const
{
    return m_scene->should_close();
}


void SceneManager::handle_event(const sf::Event& event)
{
    m_scene->handle_event(event);
}


void SceneManager::update(double dt)
{
    m_scene->update(dt);

    if(should_close())
        m_scene.reset(nullptr);

    if(Scene* p = m_scene->get_target(); p)
    {
        m_scene.reset(p);
    }
}


void SceneManager::draw(sf::RenderTarget& target, sf::RenderState states) const
{
    target.draw(*m_scene, states);
}


}
