#pragma once
#include <TDocStd_Document.hxx>
#include <XCAFDoc_ShapeTool.hxx>
#include <XCAFDoc_ColorTool.hxx>
#include "DocumentCommon.h"
#include <set>

class ImportOCAF
{
public:
	ImportOCAF(Handle_TDocStd_Document h, DocumentCommon* d, const std::string& name);
	~ImportOCAF();
	void loadShapes();

private:
	void loadShapes(const TDF_Label& label, const TopLoc_Location&, const std::string& partname, const std::string& assembly, bool isRef);
	void createShape(const TDF_Label& label, const TopLoc_Location&, const std::string&);
	void createShape(const TopoDS_Shape& label, const TopLoc_Location&, const std::string&);
	//virtual void applyColors(Part::Feature*, const std::vector<App::Color>&) {}

private:
	Handle_TDocStd_Document pDoc;
	DocumentCommon* doc;
	Handle_XCAFDoc_ShapeTool aShapeTool;
	Handle_XCAFDoc_ColorTool aColorTool;
	std::string default_name;
	std::set<int> myRefShapes;
	static const int HashUpper = INT_MAX;
};

