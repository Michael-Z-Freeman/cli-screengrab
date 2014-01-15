cli-screengrab
==============

Requires: Graphics Magick command line utilities ( http://www.graphicsmagick.org/ ), or similiar; alter batch file accordingly. 

Examples of usage: 

Screengrab - http://forum.nasaspaceflight.com/index.php?topic=33743.msg1145651#msg1145651

Ani Gif made from multiple screen grabs (using Gimp) - http://forum.nasaspaceflight.com/index.php?topic=33743.msg1145668#msg1145668

Windows command line screen grab utility. The screen grab does not have to be based on what is on the current monitor as the utility saves a bitmap based on the given Window name. This is useful for full screen windows created by browser video players. 

At the moment the utility is quite basic, but I've been using it successfully. It has proved to be effective at capturing screen shots of live space walks from NASA TV. 

For the moment I'm setting the Window ID in the code and then recompiling but intend to add a command line switch. cli-screengrab puts the screen grab bitmap in the Windows copy/paste buffer. The included batch file then uses Graphics Magick "convert" to "paste" to a JPEG file. I started doing this intending to make cli-screengrab become useful as part of any CLI tool chain. I intend to add the ability to pipe the screen grab to Graphics Magic which is probably a little more elegant than putting it in the past buffer. However that can be useful if wanting to quickly paste into a graphics editor. The user could be allowed to configure this behaviour using a few command line switches. 

cli-screengrab was developed on Linux using MinGW-w64, but should compile in Windows with minimal modification.

Please note that initial commit needs some tidying up but should compile. I have included a Code Blocks build file. 
