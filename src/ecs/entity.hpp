#pragma once

namespace ecs {

    //*********************************************************************************************
    //*********************************************************************************************
    //*********************************************************************************************
    class EntityPrefab {
    public:
        const rtti::Class* entity_class() const;
        const Entity* entity_data() const;

    protected:
        std::unique_ptr<Entity> m_entity_data;
        rtti::Class* m_entity_class = nullptr;
    
    }; // class EntityPrefab

    //*********************************************************************************************
    //*********************************************************************************************
    //*********************************************************************************************
    class EntityConfig {
    public:

    }; // class EntityConfig

    //*********************************************************************************************
    //*********************************************************************************************
    //*********************************************************************************************

    class Entity {
    public:
        const uuids::uuid& id() const { return m_id; }
        const AssetRef<EntityPrefab>& prefab() const { return m_prefab; }
        const AssetRef<EntityConfig>& config() const { return m_config; }

    private:
        uuids::uuid m_id;
        AssetRef<EntityPrefab> m_prefab;
        AssetRef<EntityConfig> m_config;

    }; // class Entity

} // namespace ecs
