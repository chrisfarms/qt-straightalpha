qt-straightalpha
================

Sometimes H.264 files in MP4 containers play significantly darker when viewed using Quicktime (or Safari's HTML5 <video> tag which uses Quicktime) on a Windows PC. One reason for this is that Quicktime poorly handles pixel data with alpha information by default.
qt-straightalpha will patch an MP4 file to tell quicktime to use the "Straight Alpha" graphics mode by altering the [vmhd](http://developer.apple.com/mac/library/documentation/QuickTime/QTFF/QTFFChap2/qtff2.html#//apple_ref/doc/uid/TP40000939-CH204-33012) atom.

If you are seeing much darker videos in safari than in other browsers or if areas of white are showing as grey in Quicktime then give this script a go.

This is *not* the same as altering the [colr](http://www.google.com/url?sa=D&q=http%3A%2F%2Fdeveloper.apple.com%2Fquicktime%2Ficefloe%2Fdispatch019.html%23colr) atom as handbrake once did to trigger a change in gamma handling.


Requirements
------------

For the ruby script you will need Ruby.

For the C-version you will need a suitable C build environment.


Ruby Installation
-----------------

None. Just download the qt-straighalpha.rb script and run it with:
ruby ./qt-straightalpha.rb movie.mp4


Native Installation
-------------------

checkout the source, then run:
make && sudo make install


Usage
-----

./qt-straightalpha movie.mp4

Your movie will be patched in place to save rewriting the whole file, so it's recommended that you operate on a copy it is important.


Credits
-------

* Chris Farmiloe, [chrisfarms@gmail.com](mailto:chrisfarms@gmail.com)


License
-------

Copyright (c) 2009-2010 [Chris Farmiloe](http://maybeuseful.posterous.com/)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to
deal in the Software without restriction, including without limitation the
rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER 
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.