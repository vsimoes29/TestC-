//-------------------------------------------------------------------------------------------------------------------
/*!	\brief	Exemple5
*	\file	main.cpp
*///-----------------------------------------------------------------------------------------------------------------

/*---- VTK Includes ----*/
#include <vtkActor.h>
#include <vtkPolyDataMapper.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkSmartPointer.h>
#include <vtkSphereSource.h>

/*---- QT Includes ----*/
#include <qdebug.h>


int main(int p_argc, char* p_argv[])
{

	vtkSmartPointer<vtkSphereSource> sphereObject = vtkSmartPointer<vtkSphereSource>::New();
	sphereObject->SetCenter(20, 30, 40);
	sphereObject->SetRadius(50);
	sphereObject->SetPhiResolution(100);
	sphereObject->SetThetaResolution(100);
	sphereObject->Update();

	// Create mapper for the sphere
	vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
	mapper->SetInputData(sphereObject->GetOutput());

	// Create actore related to previous mapper
	vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
	actor->SetMapper(mapper);

	// Create renderer
	vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();

	// Set background color
	renderer->SetBackground(0.5, 0, 1);

	// Create render window
	vtkSmartPointer<vtkRenderWindow> renderWindow = vtkSmartPointer<vtkRenderWindow>::New();
	// Associate the renderer to the window
	renderWindow->AddRenderer(renderer);

	// Create window interactor
	vtkSmartPointer<vtkRenderWindowInteractor> interactorWindow = vtkSmartPointer<vtkRenderWindowInteractor>::New();
	interactorWindow->SetRenderWindow(renderWindow);

	// Add actor to renderer
	renderer->AddActor(actor);

	// Get active camera and modify camera - Method GetActiveCamera

	// Add a light in the scene
	//vtkSmartPointer<vtkLight> light = 
	//Set Position and Intensity
	//Add light to renderer

	// Start rendering
	renderWindow->Render();

	// Start interactor
	interactorWindow->Start();

	return 0;
}
