#!/usr/bin/python
#coding:UTF-8

import PIL,glob
from PIL import Image

# list all image files:

imgfiles = glob.glob("*.jpg") 

def_maxsize = 620

for imgf in imgfiles:
	img = Image.open(imgf)
	oldWidth = img.size[0]
	oldHeight= img.size[1]
	maxOldSize = max(oldWidth,oldHeight)
	if maxOldSize > def_maxsize:
		print imgf
		print oldWidth,oldHeight

		rat = def_maxsize / float(maxOldSize)

		newWidth  = int(oldWidth * rat)
		newHeight = int(oldHeight * rat)
	else:
		newWidth  = oldWidth
		newHeight = oldHeight

	img2 = img.resize((newWidth, newHeight),Image.ANTIALIAS)
	newimgf = "newimgs/" + imgf
	img2.save(newimgf)

