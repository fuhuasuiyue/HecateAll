#include "HCModelTranslator.h"
#include "BRepMesh_IncrementalMesh.hxx"
#include "TopExp_Explorer.hxx"
#include "TopoDS.hxx"



HCModelTranslator::HCModelTranslator()
{
}


HCModelTranslator::~HCModelTranslator()
{
}

btConvexHullShape* HCModelTranslator::createConvexShapeFromTopoDS(TopoDS_Shape aShape)
{
	//TriangleList* pResultTriList = new TriangleList;;
	GLInstanceGraphicsShape* glMesh = new GLInstanceGraphicsShape;
	glMesh->m_scaling[0] = 1;
	glMesh->m_scaling[1] = 1;
	glMesh->m_scaling[2] = 1;
	glMesh->m_scaling[3] = 1;
	glMesh->m_indices = new b3AlignedObjectArray<int>();
	glMesh->m_vertices = new b3AlignedObjectArray<GLInstanceVertex>();

	BRepMesh_IncrementalMesh(aShape, 1);
	TopExp_Explorer faceExplorer;
	for (faceExplorer.Init(aShape, TopAbs_FACE); faceExplorer.More(); faceExplorer.Next())
	{
		TopLoc_Location loc;

		TopoDS_Face aFace = TopoDS::Face(faceExplorer.Current());
		Handle_Poly_Triangulation triFace = BRep_Tool::Triangulation(aFace, loc);
		// 获得当前面在世界坐标系中的转换，即当前面坐标系的值
		gp_Trsf tempTrsf = loc.Transformation();
		Standard_Integer nTriangles = triFace->NbTriangles();
		gp_Pnt vertex1;
		gp_Pnt vertex2;
		gp_Pnt vertex3;

		Standard_Integer nVertexIndex1 = 0;
		Standard_Integer nVertexIndex2 = 0;
		Standard_Integer nVertexIndex3 = 0;
		TColgp_Array1OfPnt nodes(1, triFace->NbNodes());
		Poly_Array1OfTriangle triangles(1, triFace->NbTriangles());
		nodes = triFace->Nodes();
		triangles = triFace->Triangles();
		int index = 0;
		for (Standard_Integer i = 1; i <= nTriangles; i++)
		{
			Poly_Triangle aTriangle = triangles.Value(i);
			aTriangle.Get(nVertexIndex1, nVertexIndex2, nVertexIndex3);
			vertex1 = nodes.Value(nVertexIndex1);
			vertex2 = nodes.Value(nVertexIndex2);
			vertex3 = nodes.Value(nVertexIndex3);
			// 转换到世界坐标系
			vertex1.Transform(tempTrsf);
			vertex2.Transform(tempTrsf);
			vertex3.Transform(tempTrsf);
			gp_XYZ vector12(vertex2.XYZ() - vertex1.XYZ());
			gp_XYZ vector13(vertex3.XYZ() - vertex1.XYZ());
			gp_XYZ normal = vector12.Crossed(vector13);
			Standard_Real rModulus = normal.Modulus();
			if (rModulus > gp::Resolution())
			{
				normal.Normalize();
			}
			else
			{
				normal.SetCoord(0., 0., 0.);
			}
			GLInstanceVertex v0, v1, v2;
			v0.uv[0] = v1.uv[0] = v2.uv[0] = 0.5;
			v0.uv[1] = v1.uv[1] = v2.uv[1] = 0.5;
			v0.xyzw[0] = vertex1.X();
			v0.xyzw[0] = vertex1.Y();
			v0.xyzw[0] = vertex1.Z();

			v1.xyzw[0] = vertex2.X();
			v1.xyzw[0] = vertex2.Y();
			v1.xyzw[0] = vertex2.Z();

			v2.xyzw[0] = vertex3.X();
			v2.xyzw[0] = vertex3.Y();
			v2.xyzw[0] = vertex3.Z();

			v0.xyzw[3] = v1.xyzw[3] = v2.xyzw[3] = 0.f;

			glMesh->m_vertices->push_back(v0);
			glMesh->m_vertices->push_back(v1);
			glMesh->m_vertices->push_back(v2);

			glMesh->m_indices->push_back(index++);
			glMesh->m_indices->push_back(index++);
			glMesh->m_indices->push_back(index++);

		}
	}
	const GLInstanceVertex& v = glMesh->m_vertices->at(0);
	btConvexHullShape* pReturnshape = new btConvexHullShape((const btScalar*)(&(v.xyzw[0])), glMesh->m_numvertices, sizeof(GLInstanceVertex));
	return pReturnshape;
}
