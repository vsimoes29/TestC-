//-------------------------------------------------------------------------------------------------------------------
/*!	\brief 	Implementation of class View3D
*	\file	View3D.cpp
*///-----------------------------------------------------------------------------------------------------------------

#include "View3D.h"

/*---- Internal Includes ----*/
#include "ApplicationData.h"

/*---- VTK Includes ----*/
#include <vtkActor.h>
#include <vtkPolyDataMapper.h>
#include <vtkRenderWindow.h>

#include <QDebug>

//-----------------------------------------------------------------------------------------------------------------
View3D::View3D(QWidget * p_parent)
: QVTKWidget(p_parent), m_renderer(vtkSmartPointer<vtkRenderer>::New())
//-----------------------------------------------------------------------------------------------------------------
{
	m_ui.setupUi(this);
}

//-----------------------------------------------------------------------------------------------------------------
View3D::~View3D()
//-----------------------------------------------------------------------------------------------------------------
{
	//Not necessary to delete children View3D, Qt will do it automatically
}

//-----------------------------------------------------------------------------------------------------------------
void View3D::initData()
//-----------------------------------------------------------------------------------------------------------------
{
	//Add renderer
	m_ui.view->GetRenderWindow()->AddRenderer(m_renderer);

	//Set background color
	m_renderer->SetBackground(1, 1, 1);

	//Render
	m_renderer->Render();
	update();

	//Create mapper and actor for Scapula Mesh - Ex9 - VTK
	//Use mapper->ScalarVisibilityOff() to take into account actor color
	//TODO

	//Create mapper and actor for Humerus Mesh - Ex9 - VTK
	//Use mapper->ScalarVisibilityOff() to take into account actor color
	//TODO

	//Add actor in renderer
	//TODO

	m_renderer->ResetCamera();
}
