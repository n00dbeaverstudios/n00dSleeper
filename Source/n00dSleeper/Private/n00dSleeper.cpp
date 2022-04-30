/* © Copyright 2020-2021 | n00dbeaver Studios */

#include "n00dSleeper.h"

#define LOCTEXT_NAMESPACE "Fn00dSleeperModule"

void Fn00dSleeperModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void Fn00dSleeperModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(Fn00dSleeperModule, n00dSleeper)