@echo off
cd "d:\Incoming\spacewalk\"
d:
FOR /L %%G IN (1, 1, 999) DO (
     "Hello World Key Detection.exe"
	 gm convert clipboard: exp38_antares_launch_%%G.jpg
)