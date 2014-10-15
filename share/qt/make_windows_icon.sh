#!/bin/bash
# create multiresolution windows icon
ICON_SRC=../../src/qt/res/icons/diamond.png
ICON_DST=../../src/qt/res/icons/diamond.ico
convert ${ICON_SRC} -resize 16x16 diamond-16.png
convert ${ICON_SRC} -resize 32x32 diamond-32.png
convert ${ICON_SRC} -resize 48x48 diamond-48.png
convert diamond-16.png diamond-32.png diamond-48.png ${ICON_DST}

