#pragma once
#include "PpmDocument.hpp"
#include "ImageEffect.hpp"
class GreyscaleEffect : public ImageEffect
{
public:
	virtual void applyEffect(PpmDocument& doc)
	{
		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				Pixel& p = doc[i][j];
				int average = 0;

				average = (p.red + p.green + p.blue) / 3;

				if (p.red != average || p.green != average || p.blue != average)
				{
					p.red = average;
					p.green = average;
					p.blue = average;
				}
				
				doc[i][j] = p;
			}
		}
	}
};