//-------------------------------------------------------------------------------------------------------------------
/*!	\brief	Exemple4
*	\file	main.cpp
*///-----------------------------------------------------------------------------------------------------------------

/*---- ITK Includes ----*/
#include <itkImage.h>
#include <itkImageRegionConstIterator.h>

/*---- QT Includes ----*/
#include <qdebug.h>


int main(int p_argc, char* p_argv[])
{
	//Typedef to define a image type
	typedef itk::Image<unsigned char, 2> UCharImageType;

	//Create the reader to read an image


	//Write dimensions and spacing
	qDebug() << "Dimensions X :" << reader->GetOutput()->GetLargestPossibleRegion().GetSize()[0];
    //...


	//Create an iterator to check if the image contains the rectangle
	itk::ImageRegionConstIterator<UCharImageType> iterator(reader->GetOutput(), reader->GetOutput()->GetLargestPossibleRegion());
	
	//Initialize iterator to begin (GoToBegin())
	
	
	int nbPixels = 0;

	while(!iterator.IsAtEnd())
	{
		//Check if pixel = 255


		//Increment iterator
		++iterator;
	}

	qDebug() << "Nb pixels equal to 255 :" << nbPixels;

	return 0;
} 
