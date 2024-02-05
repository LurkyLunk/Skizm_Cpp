// PhysicsObject.h
#ifndef PHYSICS_OBJECT_H
#define PHYSICS_OBJECT_H

#include <bullet/btBulletDynamicsCommon.h>

class PhysicsObject {
public:
    PhysicsObject(btScalar mass, btCollisionShape* shape);
    ~PhysicsObject();

    btRigidBody* getRigidBody() const;

private:
    btCollisionShape* collisionShape;
    btRigidBody* rigidBody;
    btDefaultMotionState* motionState;
};

#endif // PHYSICS_OBJECT_H
