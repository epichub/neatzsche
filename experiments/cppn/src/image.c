#include <tiffio.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "image.h"


int
write_image ( double *image )
{
  int result = 0;
  unsigned char raster[ROWS][COLS];

  for ( int x=0; x<ROWS; x++ )
    for ( int y=0; y<COLS; y++ )
      raster[x][y] = (unsigned char)(image[AT(x,y)] * 255);

  TIFF* tif = TIFFOpen ( "result.tiff", "w" );

  if ( tif )
    {
      TIFFSetField ( tif, TIFFTAG_IMAGEWIDTH, COLS );
      TIFFSetField ( tif, TIFFTAG_IMAGELENGTH, ROWS );
      TIFFSetField ( tif, TIFFTAG_BITSPERSAMPLE, 8 );
      TIFFSetField ( tif, TIFFTAG_SAMPLESPERPIXEL, 1 );
      TIFFSetField ( tif, TIFFTAG_PHOTOMETRIC, 1 );
      TIFFSetField ( tif, TIFFTAG_PLANARCONFIG, 1 );
   
      for ( int r = 0; r < ROWS; r++)
	if ( TIFFWriteScanline ( tif, raster[r], r, 1 ) != 1 )
	  {
	    result = -1;
	    break;
	  }
    }
  else
    result = -1;

  TIFFClose ( tif );
  return result;
}
int
write_image_coords ( char * filename , double *image , int mx , int my )
{
  int result = 0;
  unsigned char raster[mx][my];

  for ( int x=0; x<mx; x++ )
    for ( int y=0; y<my; y++ )
      raster[x][y] = (unsigned char)(image[(x*my)+y] * 255);

  TIFF* tif = TIFFOpen ( filename, "w" );

  if ( tif )
    {
      TIFFSetField ( tif, TIFFTAG_IMAGEWIDTH, my );
      TIFFSetField ( tif, TIFFTAG_IMAGELENGTH, mx );
      TIFFSetField ( tif, TIFFTAG_BITSPERSAMPLE, 8 );
      TIFFSetField ( tif, TIFFTAG_SAMPLESPERPIXEL, 1 );
      TIFFSetField ( tif, TIFFTAG_PHOTOMETRIC, 1 );
      TIFFSetField ( tif, TIFFTAG_PLANARCONFIG, 1 );
   
      for ( int r = 0; r < mx; r++)
	if ( TIFFWriteScanline ( tif, raster[r], r, 1 ) != 1 )
	  {
	    result = -1;
	    break;
	  }
    }
  else
    result = -1;

  TIFFClose ( tif );
  return result;
}


int
read_image ( double *& image , const char * name, int * sizes)
{
  int result = 0;
  std::cout << "opening: " << name << std::endl;
  TIFF* tif = TIFFOpen( name, "r");
  if ( tif )
    {
      int cols, rows;


      TIFFGetField ( tif, TIFFTAG_IMAGEWIDTH,  &cols );
      TIFFGetField ( tif, TIFFTAG_IMAGELENGTH, &rows );
      image  = (double*)calloc(rows*cols,sizeof(double));
      unsigned char raster[rows][cols];
      sizes[0] = cols;
      sizes[1] = rows;

      for ( int r = 0; (r < rows); r++ ){
	if ( TIFFReadScanline ( tif, raster[r], r, 1 ) != 1 )
	  {
	    result = -1;
	    break;
	  }
	else{
	}
      }


      TIFFClose ( tif );
	
      if ( result == -1 )
	fputs ( "I/O error\n", stderr );
      else
	{
	  for ( int x=0; x<rows; x++ ){
	    for ( int y=0; y<cols; y++ ){
	      std::cout << (double)raster[x][y] / (double)255;
	      image[(x*cols)+y] = raster[x][y] / (double)255;
	    }
	    std::cout << std::endl;
	  }
	}
    }
  else
    {
      result = -1;
    }

  return result;
}
