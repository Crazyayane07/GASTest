// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GASTest : ModuleRules
{
	public GASTest(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
