namespace Hooks
{
	class hkCreateDirectory_Mods
	{
	private:
		static std::int32_t CreateDirectory(const char* a_name, void*)
		{
			if (!_stricmp(a_name, "Creations") || !_stricmp(a_name, "Mods"))
				return 0;
			return _CreateDirectory(a_name, nullptr);
		}

		inline static REL::THook _CreateDirectory{ REL::ID(443417), 0x06, CreateDirectory };
	};

	class hkCreateDirectory_ShaderCache
	{
	private:
		static std::int32_t CreateDirectory(const char*, void*)
		{
			return 0;
		}

		inline static REL::THook _CreateDirectory{ REL::ID(77226), 0x9DE, CreateDirectory };
	};
}

namespace Tweaks
{
	class hkMagicEffectDescription
	{
	private:
		static void* Append(void* a_this, const char*)
		{
			return _Append0(a_this, "<br>");
		}

		inline static REL::THook _Append0{ REL::ID(51906), 0x0C5, Append };  // Inventory
		inline static REL::THook _Append1{ REL::ID(52072), 0x442, Append };  // ActiveEffects
	};
}

/*
namespace
{
	void MessageHandler(SKSE::MessagingInterface::Message* a_msg)
	{
		switch (a_msg->type)
		{
		case SKSE::MessagingInterface::kPostLoad:
			break;
		default:
			break;
		}
	}
}
*/

SKSE_PLUGIN_LOAD(const SKSE::LoadInterface* a_SKSE)
{
	SKSE::Init(a_SKSE, { .trampoline = true });
	// SKSE::GetMessagingInterface()->RegisterListener(MessageHandler);
	return true;
}
