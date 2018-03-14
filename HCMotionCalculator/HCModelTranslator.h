#pragma once
#include "Bullet3Common/b3AlignedObjectArray.h"
#include "LinearMath/btScalar.h"
#include "BulletCollision/CollisionShapes/btConvexHullShape.h"
#include "TopoDS_Shape.hxx"


struct GLInstanceVertex
{
	btScalar xyzw[4];
	btScalar normal[3];
	btScalar uv[2];
};
struct GLInstanceGraphicsShape
{
	b3AlignedObjectArray<GLInstanceVertex>*	m_vertices;
	int m_numvertices;
	b3AlignedObjectArray<int>* m_indices;
	int m_numIndices;
	btScalar m_scaling[4];

	GLInstanceGraphicsShape()
		:m_vertices(0),
		m_indices(0)
	{

	}

	virtual ~GLInstanceGraphicsShape()
	{
		delete m_vertices;
		delete m_indices;
	}
};

class HCModelTranslator
{
public:
	HCModelTranslator();
	~HCModelTranslator();
	static btConvexHullShape* createConvexShapeFromTopoDS(TopoDS_Shape aShape);
};

