# LemonCpp

This is a fork of the original Lemon Parser from the [SQLite project](http://www.hwaci.com/sw/lemon/)
The grammar notation and parameters can be found [here](http://www.hwaci.com/sw/lemon/lemon.html)

###### Differences with the original lemon
* The main difference is that instead of generating .c and .h files it generates an .hpp header with the class allowing to perform all the parsing operations and obviouslly a .cpp fle with its body.
* All the objects must be passed as pointers (otherwise there will be an error at compilation time) and the all Lemon functions are set as static to avoid calling them from outside the source (you must always pass through the generated class).
* This class is named LPParse or LP + the prefix you set with the %name directive (check original Lemon [documentation](http://www.hwaci.com/sw/lemon/lemon.html)).

A self-explanotary example is included with the source.

###### New directive
%include_hpp allows adding code on top of the generated header file; if tokens use types defines in an include file its inclusion must be added here too

###### Updates
* 2016/03/18 Added %include_hpp directive
* 2016/03/04 Created LemonCpp project

