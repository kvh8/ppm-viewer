#pragma once
#include "PpmDocument.hpp"
#include "ImageEffect.hpp"
class VerticalFlipEffect : public ImageEffect
{
public:
	virtual void applyEffect(PpmDocument& doc)
	{
		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0, k = (doc.getWidth() - 1); j < (doc.getWidth() / 2) && k >= (doc.getWidth() / 2); j++, k--)
			{
				Pixel& p = doc[i][j];
				Pixel& q = doc[i][k];

				int front_red = p.red;
				int front_green = p.green;
				int front_blue = p.blue;
				int back_red = q.red;
				int back_green = q.green;
				int back_blue = q.blue;

				p.red = back_red;
				p.green = back_green;
				p.blue = back_blue;
				q.red = front_red;
				q.green = front_green;
				q.blue = front_blue;

				doc[i][j] = p;
				doc[i][k] = q;
			}
		}
	}
};