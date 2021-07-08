//-------------------------------------------------------------------------------------------------------------------
/*!	\brief	Exemple3
*	\file	main.cpp
*///-----------------------------------------------------------------------------------------------------------------

/*---- VTK Includes ----*/
#include <vtkActor.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkSmartPointer.h>
#include <vtkSphereSource.h>

/*---- QT Includes ----*/
#include <qdebug.h>


int main(int p_argc, char* p_argv[])
{
	// Create a sphere - ex1
	vtkSmartPointer<vtkSphereSource> sphereObject = vtkSmartPointer<vtkSphereSource>::New();
	sphereObject->SetCenter(20, 30, 40);
	sphereObject->SetRadius(50);
	sphereObject->SetPhiResolution(10);
	sphereObject->SetThetaResolution(10);
	sphereObject->Update();



	// Create renderer - ex2
	//vtkSmartPointer<vtkRenderer> renderer =
	// Set background color - SetBackgroundColor(R[0-1],G[0-1],B[0-1]);

	// Create render window
	//vtkSmartPointer<vtkRenderWindow> renderWindow = 
	// Associate the renderer to the window - Add renderer method


	// Start rendering - Method Render()

	return 0;
}
