#include "itkMesh.h"
#include "itkVariableLengthVector.h"
#include "itksys/SystemTools.hxx"

#include "MeshFileTestHelper.h"

int main(int argc, char ** argv)
{
  if( argc < 3 )
    {
    std::cerr << "Invalid commands, You need input and output mesh file name " << std::endl;
    return EXIT_FAILURE;
    }

  bool IsBinary = false;
  if( argc > 3 ) IsBinary = true;

  const unsigned int dimension = 3;
  typedef itk::VariableLengthVector< float >        PixelType;
  typedef itk::Mesh< PixelType, dimension >         MeshType;

  if( test<   MeshType >( argv[1], argv[2], IsBinary ) ) return EXIT_FAILURE;

  return EXIT_SUCCESS;
  }
	