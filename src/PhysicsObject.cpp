// PhysicsObject.cpp
#include "PhysicsObject.h"

PhysicsObject::PhysicsObject(btScalar mass, btCollisionShape* shape)
    : collisionShape(shape) {
    btAssert((!shape || shape->getShapeType() != INVALID_SHAPE_PROXYTYPE) && "Invalid collision shape!");

    btVector3 localInertia(0, 0, 0);
    if (mass != 0.f) {
        collisionShape->calculateLocalInertia(mass, localInertia);
    }

    motionState = new btDefaultMotionState();
    btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, motionState, shape, localInertia);
    rigidBody = new btRigidBody(rbInfo);
}

PhysicsObject::~PhysicsObject() {
    delete rigidBody;
    delete motionState;
}

btRigidBody* PhysicsObject::getRigidBody() const {
    return rigidBody;
}
