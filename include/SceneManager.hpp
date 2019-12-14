#ifndef VENUSBLAST_SCENEMANAGER_HPP
#define VENUSBLAST_SCENEMANAGER_HPP

#include <memory>
#include "Scene.hpp"

namespace vblast
{


class SceneManager : public sf::Drawable
{
public:

    bool should_close() const;

    void handle_event(const sf::Event& event);
    void update(double dt);

protected:

    virtual void draw(sf::RenderTarget& target, sf::RenderState states) const;

private:

    std::unique_ptr<Scene> m_scene;
}


}

#endif
