#ifndef PHYSICS_ENGINE_H
#define PHYSICS_ENGINE_H

#include "PhysicsObject.h"
#include <btBulletDynamicsCommon.h>

class PhysicsEngine {
public:
    PhysicsEngine();
    ~PhysicsEngine();

    void initialize();
    void addObject(PhysicsObject* object);
    void removeObject(PhysicsObject* object);
    void stepSimulation(float deltaTime);

private:
    btDefaultCollisionConfiguration* collisionConfiguration;
    btCollisionDispatcher* dispatcher;
    btBroadphaseInterface* overlappingPairCache;
    btSequentialImpulseConstraintSolver* solver;
    btDiscreteDynamicsWorld* dynamicsWorld;
};

#endif // PHYSICSENGINE_H
