#!/usr/bin/python
#coding:UTF-8

import PIL
from PIL import Image

# old size: 640 x 480
# new size: 600 x ?

oldWidth = 640
oldHeight= 480

newWidth = 600
rat = newWidth / float(oldWidth)
newHeight = int(oldHeight * rat)

img = Image.open("a4.jpg")
img2 = img.resize((newWidth, newHeight),Image.ANTIALIAS)
img2.save("a4_2.jpg")

