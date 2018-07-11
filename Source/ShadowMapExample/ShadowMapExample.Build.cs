// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ShadowMapExample : ModuleRules
{
	public ShadowMapExample(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "Slate","SlateCore", "InputCore", "AIModule", "HeadMountedDisplay", "ShadowMapMaterialFunction", "UMG" });
	}
}
