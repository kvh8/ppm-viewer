#pragma once
#include "PpmDocument.hpp"
#include "ImageEffect.hpp"
class RandomNoiseEffect : public ImageEffect
{
public:
	virtual void applyEffect(PpmDocument& doc)
	{
		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				Pixel& p = doc[i][j];
				int random_red = (rand() % 20 + (-10));
				int random_green = (rand() % 20 + (-10));
				int random_blue = (rand() % 20 + (-10));
				p.red = p.red + random_red;
				p.green = p.green + random_green;
				p.blue = p.blue + random_blue;

				if (p.red < 0 || p.green < 0 || p.blue < 0)
				{
					p.red = 0;
					p.green = 0;
					p.blue = 0;
				}
				else if (p.red > 255 || p.green > 255 || p.blue > 255)
				{
					p.red = 255;
					p.green = 255;
					p.blue = 255;
				}
				else
				{
					p.red;
					p.green;
					p.blue;
				}

				doc[i][j] = p;
			}
		}
	}
};