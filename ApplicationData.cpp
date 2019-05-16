//-------------------------------------------------------------------------------------------------------------------
/*!	\brief 	Implementation of class ApplicationData
*	\file	ApplicationData.cpp
*///-----------------------------------------------------------------------------------------------------------------

#include "ApplicationData.h"

/*---- ITK Includes ----*/
#include <itkGDCMImageIO.h>
#include <itkImageFileReader.h>
#include <itkImageRegionConstIterator.h>
#include <itkBinaryThresholdImageFilter.h>

/*---- QT Includes ----*/
#include <QDebug>
#include <QDir>
#include <QFileInfo>
#include <QStringList>

/*---- VTK Includes ----*/
#include <vtkImageFlip.h>
#include <vtkPointData.h>
#include <vtkShortArray.h>
#include <vtkMarchingCubes.h>
#include <vtkUnsignedCharArray.h>

//Initialize static variable
ApplicationData * ApplicationData::m_instance = 0;

//-----------------------------------------------------------------------------------------------------------------
ApplicationData::ApplicationData() :
		m_scapula(vtkPolyData::New()), m_humerus(vtkPolyData::New())
//-----------------------------------------------------------------------------------------------------------------
{
}

//-----------------------------------------------------------------------------------------------------------------
ApplicationData::~ApplicationData()
//-----------------------------------------------------------------------------------------------------------------
{
	m_scapula->Delete();
	m_humerus->Delete();
}

//-----------------------------------------------------------------------------------------------------------------
void ApplicationData::loadDirectory(const QString & p_dirPath)
//-----------------------------------------------------------------------------------------------------------------
{
	m_dirPath = p_dirPath;

	//List files in a directory

	//Create the list of string to store files path
	QStringList filesList;

	// TODO ... Use Qt to list files in the directory
	// TODO Check if file is readable

	m_rawImages.clear();

	//Read Dicom Image
	double positionZ = 0.;
	for(int i = 0 ; i < filesList.size() ; ++i)
	{
		//try to read the ITK file and save the image
		try
		{
			qDebug() << "Reading image " << i << "with path:" << filesList[i];
			//Try to read the ITK file and save the image - Ex4 et Ex5 ITK - itk::ImageFileReader and itk::GDCMImageIO
			//TODO

			//Save read image in the list: m_rawImages
			//TODO
			//For the first two images, we get the image position (0020, 0032).
			//From the difference, we compute the spacingZ
			if(i <= 1)
			{
				std::string currentPosition;
				//Read currentPosition (0020, 0032) using GDCMImageIO - Refer to Ex5 - ITK
				//TODO
				const double currentPositionZ = QString(currentPosition.c_str()).trimmed().split("\\").last().toDouble();
				qDebug() << QString(currentPosition.c_str()) << positionZ;
				if(i == 1)
				{
					m_spacingZ = currentPositionZ - positionZ;
				}
				else positionZ = currentPositionZ;
			}

		}
		//In case of non-image file
		catch(itk::ExceptionObject & ex)
		{
			qDebug() << "Error with file" << filesList[i] << ":" << ex.what();
		}

	}

	//TODO
	//Get dimensionX/Y - Refer to Ex1 - ITK
	//m_dimensionX = ...;
	//m_dimensionY = ...;

	//TODO
	//Get spacing X/Y
	//m_spacingX = ...;
	//m_spacingY = ...;

	//TODO
	//Get dimensionZ
	//m_dimensionZ = ...;

	//Build the vtkImageData containing the raw volume - Ex12 VTK
	//VTKImageData should have dimension X, Y and Z as well as SpacingX, Y and Z of the volume
	//Ex12 was a volume of 100x100x100
	m_rawVTKData = vtkSmartPointer<vtkImageData>::New();
	//TODO
	//m_rawVTKData->SetDimensions(...);
	//m_rawVTKData->SetSpacing(...);
	//m_rawVTKData->SetExtent(...);

	//Create scalars to fill the vtkImageData
	vtkSmartPointer<vtkShortArray> scalars = vtkSmartPointer<vtkShortArray>::New();
	//Set number of values = number of voxel in 3D volume
	//TODO
	//scalars->SetNumberOfValues(...);

	int offset  = 0;
	//Iterate over all images and fill the scalars
	for(int z = 0 ; z < m_rawImages.size() ; ++z)
	{
		//Create const ITK iterator on each image
		//In the while, set the value of each pixel to the scalars using variable offset
		//Ex3 - ITK
		//TODO
	}

	m_rawVTKData->GetPointData()->SetScalars(scalars);

	vtkSmartPointer<vtkImageFlip> flipper = vtkSmartPointer<vtkImageFlip>::New();
	flipper->SetFilteredAxis(1);
	flipper->SetInputData(m_rawVTKData);
	flipper->Update();

	m_rawVTKData = flipper->GetOutput();
}

//-----------------------------------------------------------------------------------------------------------------
void ApplicationData::segmentData()
//-----------------------------------------------------------------------------------------------------------------
{
	//Segment from 2 to 2 for Scapula using segmentData(2, 2)
	m_scapula->Delete();
	//TODO

	//Segment from 0 to 1 for Humerus using segmentData(1, 1)
	m_humerus->Delete();
	//TODO
}

//-----------------------------------------------------------------------------------------------------------------
vtkPolyData * ApplicationData::segmentData(const int p_lowerThreshold, const int p_upperThreshold) const
//-----------------------------------------------------------------------------------------------------------------
{
	QList<UCharImageType::Pointer> binaryImages;

	//Apply threshold on each raw images
	//Same as ITKReader with itk::BinaryThresholdImageFilter
	//See Exo6 ITK
	for(int z = 0 ; z < m_rawImages.size() ; ++z)
	{
		//Create thresholder and save outpout in binaryImages
		//TODO
	}

	//Build Image Data for input of marching cubes - Refer to Ex12 VTK and similar to line 113
	vtkSmartPointer<vtkImageData> binaryVTKData = vtkSmartPointer<vtkImageData>::New();
	//TODO
	//binaryVTKData->SetDimensions(...);
	//binaryVTKData->SetSpacing(...);
	//binaryVTKData->SetExtent(...);

	//Create scalars to fill the vtkImageData
	vtkSmartPointer<vtkUnsignedCharArray> scalars = vtkSmartPointer<vtkUnsignedCharArray>::New();
	//TODO
	//scalars->SetNumberOfValues(...);

	int offset  = 0;
	//Iterate over all images and fill the scalars
	//For loop on binary images with ITK const iterator (refer to line 125)
	//TODO

	binaryVTKData->GetPointData()->SetScalars(scalars);

	//Apply the marching cubes - Ex12 VTK
	//TODO

	//Return resulting mesh
	vtkPolyData * mesh = vtkPolyData::New();
	//TODO
	//DeepCopy output of MarchingCubes

	return mesh;
}
