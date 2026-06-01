// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class NavesUSFX_012026 : ModuleRules
{
	public NavesUSFX_012026(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"NavesUSFX_012026",
			"NavesUSFX_012026/Variant_Platforming",
			"NavesUSFX_012026/Variant_Platforming/Animation",
			"NavesUSFX_012026/Variant_Combat",
			"NavesUSFX_012026/Variant_Combat/AI",
			"NavesUSFX_012026/Variant_Combat/Animation",
			"NavesUSFX_012026/Variant_Combat/Gameplay",
			"NavesUSFX_012026/Variant_Combat/Interfaces",
			"NavesUSFX_012026/Variant_Combat/UI",
			"NavesUSFX_012026/Variant_SideScrolling",
			"NavesUSFX_012026/Variant_SideScrolling/AI",
			"NavesUSFX_012026/Variant_SideScrolling/Gameplay",
			"NavesUSFX_012026/Variant_SideScrolling/Interfaces",
			"NavesUSFX_012026/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
