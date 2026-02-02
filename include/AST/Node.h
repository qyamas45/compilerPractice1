#ifndef COMPILERPRACTICE1_NODE_H
#define COMPILERPRACTICE1_NODE_H

#include <string>
#include <vector>
#include <memory>

#include "Types/Type.h"

class Node {
public:
    // Constructor
    explicit Node(Type type, std::string objectClassName = "")
        : nodeType(type), objectClassName(std::move(objectClassName)) {}

    // Add child node
    void addChild(std::shared_ptr<Node> child) {
        children.push_back(std::move(child));
    }

    // Getters
    [[nodiscard]] const Type& getType()const { return nodeType; }
    [[nodiscard]] const std::string& getObjectClassName() const { return objectClassName; }
    [[nodiscard]] const std::vector<std::shared_ptr<Node>>& getChildren() const {
        return children;
    }

private:
    Type nodeType;
    std::string objectClassName;
    std::vector<std::shared_ptr<Node>> children;
};

#endif // COMPILERPRACTICE1_NODE_H
