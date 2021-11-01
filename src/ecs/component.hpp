#pragma once

namespace ecs {

    //*********************************************************************************************
    //*********************************************************************************************
    //*********************************************************************************************
    class ComponentPrefab {
    public:
        const rtti::Class* component_class() const;
        const Component* component_data() const;

    protected:
        std::unique_ptr<Component> m_component_data;
        rtti::Class* m_component_class = nullptr;
    
    }; // class ComponentPrefab

    //*********************************************************************************************
    //*********************************************************************************************
    //*********************************************************************************************
    class ComponentConfig {
    public:

    }; // class ComponentConfig

    //*********************************************************************************************
    //*********************************************************************************************
    //*********************************************************************************************
    class Component {
    public:
        const uuids::uuid& id() const { return m_id; }
        const AssetRef<ComponentPrefab>& prefab() const { return m_prefab; }
        const AssetRef<ComponentConfig>& config() const { return m_config; }

    private:
        uuids::uuid m_id;
        AssetRef<ComponentPrefab> m_prefab;
        AssetRef<ComponentConfig> m_config;

    }; // class Component

} // namespace ecs
