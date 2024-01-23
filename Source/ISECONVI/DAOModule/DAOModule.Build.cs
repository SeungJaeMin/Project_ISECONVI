// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class DAOModule : ModuleRules
{
	public DAOModule(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core" });
	}
}
