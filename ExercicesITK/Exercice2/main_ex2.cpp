//-------------------------------------------------------------------------------------------------------------------
/*!	\brief	Exemple2
*	\file	main.cpp
*///-----------------------------------------------------------------------------------------------------------------

/*---- ITK Includes ----*/
#include <itkImage.h>
#include <itkImageRegionConstIterator.h>

/*---- QT Includes ----*/
#include <qdebug.h>


int main(int p_argc, char* p_argv[])
{
    //EXERCICE 1
	//Typedef to define a image type
	typedef itk::Image<unsigned char, 2> UCharImageType;

	//Create image
	UCharImageType::Pointer image = UCharImageType::New();

	//Define starting point (0, 0)
	UCharImageType::IndexType startIndex;
	startIndex[0] = 0;
	startIndex[1] = 0;

	//Define image size
	UCharImageType::SizeType size;
	size[0] = 512;
	size[1] = 512;

	//Define image region
	UCharImageType::RegionType region;
	region.SetIndex(startIndex);
	region.SetSize(size);

	//Set the region to the image
	image->SetRegions(region);

	//Set image origin (where it starts in a 2D/3D referentiel)
	UCharImageType::PointType origin;
	origin[0] = 0;
	origin[1] = 0;
	image->SetOrigin(origin);

	//Set image spacing
	UCharImageType::SpacingType spacing;
	spacing[0] = 0.5;
	spacing[1] = 0.5;
	image->SetSpacing(spacing);

	//Allocate the image in memory
	image->Allocate();

	//Check image
	qDebug() << "Dimension X:" << image->GetLargestPossibleRegion().GetSize()[0];
	qDebug() << "Dimension Y:" << image->GetLargestPossibleRegion().GetSize()[1];
	qDebug() << "Spacing X:" << image->GetSpacing()[0];
	qDebug() << "Spacing Y:" << image->GetSpacing()[1];
	qDebug() << "Origin X:" << image->GetOrigin()[0];
	qDebug() << "Origin Y:" << image->GetOrigin()[1];

	//START EXERCICE 2

	//Create const iterator for the iteration on the entire image
	itk::ImageRegionConstIterator<UCharImageType> globalIterator(image, image->GetLargestPossibleRegion());

	//Initialize iterator to beginning

	//Iterate over the entire image to count the number of pixels


    while () //Iterator IsAtEnd()
	{
		//To print the pixel value - Method Get


		//Increment number of pixels


		//Increment iterator
	}

	qDebug() << "Number of pixels (512, 512) =" << nbPixels;

	//Create a region for iterate over a part of the image
	UCharImageType::RegionType regionForIteration;

	//Define starting pixel for iteration
	UCharImageType::IndexType startingPixel;

	//Define size of region for iteration

	//Create non const iterator to fill the image with the rectangle

	nbPixels = 0;

    while()
	{
		//Set a value to the pixel - Method Set

		//Increment number of set pixels

		//Increment iterator

	}

	qDebug() << "Number of pixels set:" << nbPixels;

	//Access to a specific pixel - GetPixel(index)


	return 0;
} 
