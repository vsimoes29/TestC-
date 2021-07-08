//-------------------------------------------------------------------------------------------------------------------
/*!	\brief	Exemple11
*	\file	main.cpp
*///-----------------------------------------------------------------------------------------------------------------

/*---- VTK Includes ----*/
#include <vtkActor.h>
#include <vtkPlane.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkSTLReader.h>
#include <vtkSmartPointer.h>

/*---- QT Includes ----*/
#include <qdebug.h>


int main(int p_argc, char* p_argv[])
{
    // Read STL file
	vtkSmartPointer<vtkSTLReader> readerScapula = vtkSmartPointer<vtkSTLReader>::New();
	readerScapula->SetFileName("/home/vsimoes/Documents/Formations/Donnees/CoursISEN/Data/scapula.stl");
	readerScapula->Update();

	// Create mapper for the scapula
	vtkSmartPointer<vtkPolyDataMapper> mapperScapula = vtkSmartPointer<vtkPolyDataMapper>::New();
	mapperScapula->SetInputData(readerScapula->GetOutput());

	// Create actor related to previous mapper
	vtkSmartPointer<vtkActor> actorScapula = vtkSmartPointer<vtkActor>::New();
	actorScapula->SetMapper(mapperScapula);
	actorScapula->GetProperty()->SetColor(0.87, 0.83, 0.69);

	//Define Clip plane
    vtkSmartPointer<vtkPlane> plane = //...

	//Clip the scapula
    vtkSmartPointer<vtkClipPolyData> clipper = //...

	// Create mapper for the Clip
    vtkSmartPointer<vtkPolyDataMapper> mapperClip = //...

	// Create actor related to previous mapper
    vtkSmartPointer<vtkActor> actorClip = //...

	actorClip->GetProperty()->SetColor(0.87, 0.83, 0.69);
	
	
	// Read STL file
	vtkSmartPointer<vtkSTLReader> readerHumerus = vtkSmartPointer<vtkSTLReader>::New();
	readerHumerus->SetFileName("/home/vsimoes/Documents/Formations/Donnees/CoursISEN/Data/humerus.stl");
	readerHumerus->Update();

	// Create mapper for the humerus
	vtkSmartPointer<vtkPolyDataMapper> mapperHumerus = vtkSmartPointer<vtkPolyDataMapper>::New();
	mapperHumerus->SetInputData(readerHumerus->GetOutput());

	// Create actor related to previous mapper
	vtkSmartPointer<vtkActor> actorHumerus = vtkSmartPointer<vtkActor>::New();
	actorHumerus->SetMapper(mapperHumerus);
	actorHumerus->GetProperty()->SetColor(0.87, 0.83, 0.69);

	// Create renderer
	vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();

	// Set background color
	renderer->SetBackground(1, 1, 1);

	// Create render window
	vtkSmartPointer<vtkRenderWindow> renderWindow = vtkSmartPointer<vtkRenderWindow>::New();
	// Associate the renderer to the window
	renderWindow->AddRenderer(renderer);

	// Create window interactor
	vtkSmartPointer<vtkRenderWindowInteractor> interactorWindow = vtkSmartPointer<vtkRenderWindowInteractor>::New();
	interactorWindow->SetRenderWindow(renderWindow);

	// Add actor to renderer
	//renderer->AddActor(actorScapula);
	renderer->AddActor(actorHumerus);
	//Add ActorClip

	// Start rendering
	renderWindow->Render();

	// Start interactor
	interactorWindow->Start();

	return 0;
}
