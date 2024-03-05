workspace "DollHouse"
	architecture "x64"

	configurations 
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "DollHouse"
	location "DollHouse"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "dhpch.h"
	pchsource "DollHouse/src/dhpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include;"
	}

	filter "system:windows"
		cppdialect "C++17" 
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"DH_PLATFORM_WINDOWS",
			"DH_BUILD_DLL",
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "DH_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "DH_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "DH_DIST"
		optimize "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"DollHouse/vendor/spdlog/include;",
		"DollHouse/src"
	}

	links
	{
		"DollHouse"
	}

	filter "system:windows"
		cppdialect "C++17" 
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"DH_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "DH_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "DH_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "DH_DIST"
		optimize "On"

