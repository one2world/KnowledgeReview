
-- premake5.lua
workspace "datastruct"
   configurations { "Debug", "Release" }


project "singlelist"
   kind "ConsoleApp"
   language "C"
   targetdir "../outputs"

   files { 
   		"linklist_main.c", 
   		"linklist.h", 
   		"linklist.c" ,
   	}

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"