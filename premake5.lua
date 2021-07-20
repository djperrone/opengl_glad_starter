workspace "opengl_glad_starter"
	architecture "x64"
	startproject "opengl_glad_starter"

	configurations
	{
		"Debug",
		"Release"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- include directories relative to root folder (solution directory)

IncludeDir = {}
IncludeDir["GLFW"] = "opengl_glad_starter/vendor/GLFW/include"
IncludeDir["Glad"] = "opengl_glad_starter/vendor/Glad/include"
--IncludeDir["ImGui"] = "opengl_glad_starter/vendor/imgui"
IncludeDir["stb_image"] = "opengl_glad_starter/vendor/stb_image"

include "opengl_glad_starter/vendor/GLFW"
include "opengl_glad_starter/vendor/Glad"
--include "opengl_glad_starter/vendor/imgui"

project "opengl_glad_starter"
	location "opengl_glad_starter"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"
	

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")	

	--pchheader "hzpch.h"
	--pchsource "opengl_glad_starter/src/hzpch.cpp"

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"	
	}

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/stb_image/**.h",
		"%{prj.name}/vendor/stb_image/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",		
		"%{prj.name}/vendor/spdlog/include",		
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		--"%{IncludeDir.ImGui}",	
		"%{IncludeDir.stb_image}"
	}

	links
	{
		"GLFW",
		"Glad",
		--"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{			
			"GLFW_INCLUDE_NONE"		
		}

	filter "configurations:Debug"			
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"
