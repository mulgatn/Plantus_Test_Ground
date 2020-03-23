// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PlantusTestGround/PlantusTestGroundGameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePlantusTestGroundGameModeBase() {}
// Cross Module References
	PLANTUSTESTGROUND_API UClass* Z_Construct_UClass_APlantusTestGroundGameModeBase_NoRegister();
	PLANTUSTESTGROUND_API UClass* Z_Construct_UClass_APlantusTestGroundGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_PlantusTestGround();
// End Cross Module References
	void APlantusTestGroundGameModeBase::StaticRegisterNativesAPlantusTestGroundGameModeBase()
	{
	}
	UClass* Z_Construct_UClass_APlantusTestGroundGameModeBase_NoRegister()
	{
		return APlantusTestGroundGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_APlantusTestGroundGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_APlantusTestGroundGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_PlantusTestGround,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APlantusTestGroundGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "PlantusTestGroundGameModeBase.h" },
		{ "ModuleRelativePath", "PlantusTestGroundGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_APlantusTestGroundGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APlantusTestGroundGameModeBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_APlantusTestGroundGameModeBase_Statics::ClassParams = {
		&APlantusTestGroundGameModeBase::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_APlantusTestGroundGameModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_APlantusTestGroundGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_APlantusTestGroundGameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_APlantusTestGroundGameModeBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(APlantusTestGroundGameModeBase, 1886204092);
	template<> PLANTUSTESTGROUND_API UClass* StaticClass<APlantusTestGroundGameModeBase>()
	{
		return APlantusTestGroundGameModeBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_APlantusTestGroundGameModeBase(Z_Construct_UClass_APlantusTestGroundGameModeBase, &APlantusTestGroundGameModeBase::StaticClass, TEXT("/Script/PlantusTestGround"), TEXT("APlantusTestGroundGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(APlantusTestGroundGameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
