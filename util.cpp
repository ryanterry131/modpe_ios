#include "externs.h"

#include "minecraftpe/ItemInstance.h"
#include "minecraftpe/Player.h"

#include <string>
#include <sstream>
#include <cstdint>
#include <cstdlib>


ItemInstance* newItemInstance(int itemId, uint8_t count, uint16_t aux)
{
	// Hack for creating ItemInstances
	if(Item$mItems[itemId] == NULL)
	{
		return NULL;
	}

	ItemInstance* itemStack = (ItemInstance*) malloc(sizeof(ItemInstance));
	ItemInstance$fromItem(itemStack, Item$mItems[itemId]);
	itemStack->count = count;
	itemStack->aux = aux;

	return itemStack;
}

Entity* EntityWrapper(uint64_t uniqueID)
{
	Entity* entity = Level$fetchEntity(MCPE_localplayer->level, uniqueID, false);

	if(entity == NULL)
	{
		entity = MCPE_localplayer;
	}

	return entity;
}

std::string tostr(int num)
{
    std::stringstream ss;
    ss << num;

    return ss.str();
}

std::string tostr64(uint64_t num)
{
    std::stringstream ss;
    ss << num;

    return ss.str();
}

uint64_t strToU64(const std::string& str)
{
	return std::stoull(str, NULL, 0);
}

void VirtualHook(uintptr_t** vtable, short offset, void* hook, void** real)
{
	*real = (void*) vtable[offset];
	vtable[offset] = (uintptr_t*) hook;
}
