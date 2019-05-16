//-------------------------------------------------------------------------------------------------------------------
/*!	\brief	Exemple10
*	\file	main.cpp
*///-----------------------------------------------------------------------------------------------------------------

/*---- VTK Includes ----*/
#include <vtkActor.h>
#include <vtkCutter.h>
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

	//Define cut plane
	vtkSmartPointer<vtkPlane> plane = vtkSmartPointer<vtkPlane>::New();
	plane->SetOrigin(0, 0, 0);
	plane->SetNormal(0, 0, 1);

	//Cut the scapula
	vtkSmartPointer<vtkCutter> cutter = vtkSmartPointer<vtkCutter>::New();
	cutter->SetInputData(reader1->GetOutput());
	cutter->SetCutFunction(plane);
	cutter->Update();

	// Create mapper for the cut
	vtkSmartPointer<vtkPolyDataMapper> mapperCut = vtkSmartPointer<vtkPolyDataMapper>::New();
	mapperCut->SetInputData(cutter->GetOutput());

	// Create actor related to previous mapper
	vtkSmartPointer<vtkActor> actorCut = vtkSmartPointer<vtkActor>::New();
	actorCut->SetMapper(mapperCut);
	actorCut->GetProperty()->SetColor(1, 0, 0);

    //Define cut plane
	vtkSmartPointer<vtkPlane> plane2 = vtkSmartPointer<vtkPlane>::New();
	plane2->SetOrigin(0, 0, 0);
	plane2->SetNormal(0, 1, 0);

	//Cut the scapula
	vtkSmartPointer<vtkCutter> cutter2 = vtkSmartPointer<vtkCutter>::New();
	cutter2->SetInputData(reader1->GetOutput());
	cutter2->SetCutFunction(plane2);
	cutter2->Update();

	// Create mapper for the cut
	vtkSmartPointer<vtkPolyDataMapper> mapperCut2 = vtkSmartPointer<vtkPolyDataMapper>::New();
	mapperCut2->SetInputData(cutter2->GetOutput());

	// Create actor related to previous mapper
	vtkSmartPointer<vtkActor> actorCut2 = vtkSmartPointer<vtkActor>::New();
	actorCut2->SetMapper(mapperCut2);
	actorCut2->GetProperty()->SetColor(0, 1, 0);

    //Define cut plane
	vtkSmartPointer<vtkPlane> plane3 = vtkSmartPointer<vtkPlane>::New();
	plane3->SetOrigin(0, 0, 0);
	plane3->SetNormal(1, 1, 0);

	//Cut the scapula
	vtkSmartPointer<vtkCutter> cutter3 = vtkSmartPointer<vtkCutter>::New();
	cutter3->SetInputData(reader1->GetOutput());
	cutter3->SetCutFunction(plane3);
	cutter3->Update();

	// Create mapper for the cut
	vtkSmartPointer<vtkPolyDataMapper> mapperCut3 = vtkSmartPointer<vtkPolyDataMapper>::New();
	mapperCut3->SetInputData(cutter3->GetOutput());

	// Create actor related to previous mapper
	vtkSmartPointer<vtkActor> actorCut3 = vtkSmartPointer<vtkActor>::New();
	actorCut3->SetMapper(mapperCut3);
	actorCut3->GetProperty()->SetColor(0, 0, 1);


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
	renderer->AddActor(actorCut);
	renderer->AddActor(actorHumerus);
	renderer->AddActor(actorCut2);
	renderer->AddActor(actorCut3);

	// Start rendering
	renderWindow->Render();

	// Start interactor
	interactorWindow->Start();

	return 0;
}
