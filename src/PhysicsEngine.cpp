#include "PhysicsEngine.h"
#include "PhysicsObject.h"
#include <btBulletDynamicsCommon.h>

PhysicsEngine::PhysicsEngine() {
    // Initialize Bullet Physics components
    collisionConfiguration = new btDefaultCollisionConfiguration();
    dispatcher = new btCollisionDispatcher(collisionConfiguration);
    overlappingPairCache = new btDbvtBroadphase();
    solver = new btSequentialImpulseConstraintSolver;
    dynamicsWorld = nullptr;  // Initialized in 'initialize'
}

void PhysicsEngine::initialize() {
    // Create the dynamics world
    dynamicsWorld = new btDiscreteDynamicsWorld(dispatcher, overlappingPairCache, solver, collisionConfiguration);

    // Set gravity (assuming Y-axis as up)
    dynamicsWorld->setGravity(btVector3(0, -10, 0));
}

PhysicsEngine::~PhysicsEngine() {
    // Clean up Bullet Physics
    delete dynamicsWorld;
    delete solver;
    delete overlappingPairCache;
    delete dispatcher;
    delete collisionConfiguration;
}

void PhysicsEngine::addObject(PhysicsObject* object) {
    if (object) {
        btRigidBody* body = object->getRigidBody();
        if (body) {
            dynamicsWorld->addRigidBody(body);
        }
    }
}

void PhysicsEngine::removeObject(PhysicsObject* object) {
    if (object) {
        btRigidBody* body = object->getRigidBody();
        if (body) {
            dynamicsWorld->removeRigidBody(body);
        }
    }
}

void PhysicsEngine::stepSimulation(float deltaTime) {
    if (dynamicsWorld) {
        dynamicsWorld->stepSimulation(deltaTime, 10);
    }
}

// Other methods as needed...
