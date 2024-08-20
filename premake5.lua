workspace "Eevee"
	architecture "x64"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

	startproject "Sandbox"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Eevee/vendor/GLFW/include"
IncludeDir["Glad"] = "Eevee/vendor/Glad/include"
IncludeDir["ImGUI"] = "Eevee/vendor/imgui"
IncludeDir["glm"] = "Eevee/vendor/glm"

group "Dependencies"
	include "Eevee/vendor/GLFW"
	include "Eevee/vendor/Glad"
	include "Eevee/vendor/imgui"
group ""

project "Eevee"
	location "Eevee"
	kind "SharedLib"
	language "C++"
	staticruntime "Off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "evpch.h"
	pchsource "%{prj.name}/src/evpch.cpp"

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	postbuildcommands {
	 ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
	}

	includedirs {
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGUI}",
		"%{IncludeDir.glm}"
	}

	links {
		"GLFW",
		"opengl32.lib",
		"dwmapi.lib",
		"Glad",
		"ImGUI"
	}

	filter "system:windows"
	cppdialect "C++17"
	systemversion "latest"

	defines {
		"EV_PLATFORM_WINDOWS",
		"EV_BUILD_DLL",
		"GLFW_INCLUDE_NONE",
		"EV_ENABLE_ASSERTS"
	}

	filter "configurations:Debug"
		defines "EV_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:RELEASE"
		defines "EV_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "EV_DIST"
		runtime "Release"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "consoleApp"
	staticruntime "Off"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"

	}

	includedirs {
		"Eevee/vendor/spdlog/include",
		"Eevee/src",
		"Eevee/vendor",
		"%{IncludeDir.glm}"
	}

	links {
		"Eevee"
	}

	filter "system:windows"
	cppdialect "C++17"
	systemversion "latest"

	defines {
		"EV_PLATFORM_WINDOWS",
	}

	filter "configurations:Debug"
		defines "EV_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:RELEASE"
		defines "EV_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "EV_DIST"
		runtime "Release"
		optimize "On"