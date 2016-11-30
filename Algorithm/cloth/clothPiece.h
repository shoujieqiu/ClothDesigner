#pragma once

#include <set>
#include <string>
#include <memory>
class ObjMesh;
namespace ldp
{
	class TransformInfo;
	class PanelPolygon;
	class ClothPiece
	{
	public:
		ClothPiece();
		~ClothPiece();

		const ObjMesh& mesh3d()const { return *m_mesh3d; }
		ObjMesh& mesh3d() { return *m_mesh3d; }
		const ObjMesh& mesh3dInit()const { return *m_mesh3dInit; }
		ObjMesh& mesh3dInit() { return *m_mesh3dInit; }
		const ObjMesh& mesh2d()const { return *m_mesh2d; }
		ObjMesh& mesh2d() { return *m_mesh2d; }
		const PanelPolygon& panel()const { return *m_panel; }
		PanelPolygon& panel() { return *m_panel; }
		const TransformInfo& transformInfo()const { return *m_transfromInfo; }
		TransformInfo& transformInfo() { return *m_transfromInfo; }

		std::string getName()const { return m_name; }
		std::string setName(std::string name); // return a unique name

		ClothPiece* clone()const;
		ClothPiece* lightClone()const;
	public:
		static std::string generateUniqueName(std::string nameHints);
	private:
		std::shared_ptr<ObjMesh> m_mesh3d;
		std::shared_ptr<ObjMesh> m_mesh3dInit;
		std::shared_ptr<ObjMesh> m_mesh2d;
		std::shared_ptr<PanelPolygon> m_panel;
		std::shared_ptr<TransformInfo> m_transfromInfo;
		std::string m_name;
		static std::set<std::string> s_nameSet;
	};
}