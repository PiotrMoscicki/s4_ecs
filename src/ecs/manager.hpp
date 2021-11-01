#pragma once

#include <vector>

namespace ecs {

    class AssetRefBase {};

    template <typename T>
    class AssetRef : public AssetRefBase {};

    template <typename T>
    class AssetId : public AssetRef<T> {};

    template <typename T>
    class AssetPath : public AssetRef<T> {};

    

    class EntityRefBase {};

    template <typename T>
    class EntityRef : public EntityRefBase {};

    template <typename T>
    class EntityId : public EntityRef<T> {};

    template <typename T>
    class EntityPath : public EntityRef<T> {};


    class ComponentRefBase {};

    template <typename T>
    class ComponentRef : public ComponentRefBase {};

    template <typename T>
    class ComponentId : public ComponentRef<T> {};

    template <typename T>
    class ComponentPath : public ComponentRef<T> {};


    class Entity {};
    class EntityPrefab {};
    class EntityConfig {};
    class Component {};
    class ComponentPrefab {};
    class ComponentConfig {};

    class Manager {
    public:
        // create entity
        EntityId<Entity> create_entity();
        template <typename ENT>
        EntityId<ENT> create_entity();
        EntityId<Entity> create_entity(const AssetRef<EntityPrefab>& pfb);
        EntityId<Entity> create_entity(const AssetRef<EntityConfig>& cfg);
        template <typename SRC>
        EntityId<typename SRC::Entity> create_entity(const AssetRef<SRC>& src);
        
        // get entity
        bool is_valid(const EntityRefBase& ent) const;
        Entity* get_entity(const EntityRefBase& ent);
        template <typename ENT>
        EntityId<ENT*> get_entities();
        std::vector<Entity*> get_entities(const AssetRef<EntityPrefab>& pfb);
        std::vector<Entity*> get_entities(const AssetRef<EntityConfig>& cfg);
        template <typename SRC>
        std::vector<typename SRC::Entity*> get_entities(const AssetRef<SRC>& src);

        // delete entity
        void delete_entity(const EntityRefBase& ent);
        template <typename ENT>
        void delete_entities();
        void delete_entities(const AssetRef<EntityPrefab>& pfb);
        void delete_entities(const AssetRef<EntityConfig>& cfg);
        template <typename SRC>
        void delete_entities(const AssetRef<SRC>& src);



        // add component
        template <typename CMP>
        ComponentId<CMP> add_component();
        ComponentId<Component> add_component(const EntityRefBase& ent, const AssetRef<ComponentPrefab>& pfb);
        ComponentId<Component> add_component(const EntityRefBase& ent, const AssetRef<ComponentConfig>& cfg);
        template <typename SRC>
        ComponentId<typename SRC::Component> add_component(const EntityRefBase& ent, const AssetRef<SRC>& src);
        
        // get component
        bool is_valid(const ComponentRefBase& cmp) const;
        Component* get_component(const ComponentRefBase& cmp);
        template <typename CMP>
        CMP* get_component(const EntityRefBase& ent);
        Component* get_component(const EntityRefBase& ent, const AssetRef<ComponentPrefab>& pfb);
        Component* get_component(const EntityRefBase& ent, const AssetRef<ComponentConfig>& cfg);
        template <typename SRC>
        typename SRC::Component* get_component(const EntityRefBase& ent, const AssetRef<SRC>& src);

        // remove component
        void remove_component(const ComponentRefBase& cmp);
        template <typename CMP>
        void remove_component(const EntityRefBase& ent);
        void remove_component(const EntityRefBase& ent, const AssetRef<ComponentPrefab>& pfb);
        void remove_component(const EntityRefBase& ent, const AssetRef<ComponentConfig>& cfg);
        template <typename SRC>
        void remove_component(const EntityRefBase& ent, const AssetRef<SRC>& src);
    };

} // namespace ecs
