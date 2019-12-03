#pragma once
#include "PpmDocument.hpp"
#include "ImageEffect.hpp"
class HighContrastEffect : public ImageEffect
{
public:
	virtual void applyEffect(PpmDocument& doc)
	{
		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				Pixel& p = doc[i][j];
				
				if (p.red > (255 / 2) || p.green > (255 / 2) || p.blue > (255 / 2))
				{
					p.red = 255;
					p.green = 255;
					p.blue = 255;
				}
				else
				{
					p.red = 0;
					p.green = 0;
					p.blue = 0;
				}


				
				doc[i][j] = p;
			}
		}
	}
};