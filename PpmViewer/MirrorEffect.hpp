#pragma once
#include "PpmDocument.hpp"
#include "ImageEffect.hpp"
class MirrorEffect : public ImageEffect
{
public:
	virtual void applyEffect(PpmDocument& doc)
	{
		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0, k = (doc.getWidth() - 1); j < doc.getWidth() && k > 0; j++, k--)
			{
				Pixel& p = doc[i][j];
				Pixel& q = doc[i][k];

				p.red = q.red;
				p.green = q.green;
				p.blue = q.blue;

				doc[i][j] = p;
				doc[i][k] = q;
			}
		}
	}
};