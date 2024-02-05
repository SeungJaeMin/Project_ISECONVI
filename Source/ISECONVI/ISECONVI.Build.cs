// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ISECONVI : ModuleRules
{
	public ISECONVI(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(
			new string[] {
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore", 
			"HeadMountedDisplay",
			"EnhancedInput"
			}
		);
		PublicIncludePaths.AddRange(
			new string[] {
				"ISECONVI"

			}
		);


		DynamicallyLoadedModuleNames.AddRange(
			new string[] {
			}
		);

		// Generate compile errors if using DrawDebug functions in test/shipping builds.
		PublicDefinitions.Add("SHIPPING_DRAW_DEBUG_ERROR=1");
	}
}
