#pragma once
#include <unordered_map>
#include <memory>
#include <typeindex>
#include <iostream>
#include "Shape.h"
#include "SingleComponent.h"
#include "SharedComponent.h"

// TODO need to remove shape.

/**
 * @class Entity
 * @brief Represents a game owner that can hold multiple components.
 */
class Entity {
public:


    Entity(glm::vec2 position, Shape shape) {
        setPosition(position);
        setShape(shape);
        id = std::to_string(rand() % 1000000000);
    }

    virtual ~Entity() = default;

    Shape getShape() const { return shape; }
    void setShape(Shape shape) { this->shape = shape; }

    glm::vec2 getPosition() const { return position; }
    void setPosition(glm::vec2 position) { 
        this->position = position; 
        this->shape.setGlobalPosition(position + shape.getPosition());
    }

    std::string getId() const { return id; }
    void setId(std::string id) { this->id = id; }

    glm::vec2 position;
    Shape shape;
    std::string id = "default";

    // Add a component to the owner
    template <typename T, typename... Args>
    T& addComponent(Args&&... args) {
        std::unique_ptr<T> component = std::make_unique<T>(*this, std::forward<Args>(args)...);
        T& ref = *component;
        components[std::type_index(typeid(T))] = std::move(component);
        return ref;
    }

    // Retrieve a component of a given type
    template <typename T>
    T* getComponent() {
        auto it = components.find(std::type_index(typeid(T)));
        return (it != components.end()) ? static_cast<T*>(it->second.get()) : nullptr;
    }


    // Add a shared component to the owner
    template <typename T>
    void addSharedComponent(std::shared_ptr<T> component) {
        static_assert(std::is_base_of<SharedComponent, T>::value, "T must derive from Component");
        component->addOwner(*this);
        sharedComponents[std::type_index(typeid(T))] = component;
    }

    // Retrieve a shared component of a given type
    template <typename T>
    std::shared_ptr<T> getSharedComponent() {
        auto it = sharedComponents.find(std::type_index(typeid(T)));
        return (it != sharedComponents.end()) ? std::static_pointer_cast<T>(it->second) : nullptr;
    }

private:


    std::unordered_map<std::type_index, std::shared_ptr<SingleComponent>> components; // Store components by their type
    std::unordered_map<std::type_index, std::shared_ptr<SharedComponent>> sharedComponents;
};
