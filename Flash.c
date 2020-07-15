#include "Flash.h"
uint16_t Flash_Key=0;
void Flash_Enable(void)
{
	if ((Memory(FLASH_BASE_REG,FLASH_BOOTCFG_R))& 0x10) {
		Flash_Key =	0xA442;
	}
	else {
		Flash_Key= 0x71D5;
	} 
}

int Flash_Erase(int blockCount)
{
	
	if (Flash_Key == 0) {
		return -1;// FLash is not enabled
	}
	
	for (int i = 0; i < blockCount; i++) {
	
	Memory(FLASH_BASE_REG,FLASH_ADDRESSE_RE) &= 0xFFFC0000;  
		
		// Blocks are erased on 1KiB boundaries, so multiply the index by 1024
		//	and add this to the base address.
Memory(FLASH_BASE_REG,FLASH_ADDRESSE_RE)|= ((uint32_t)FLASH_BASE_ADDR) + (i*1024);
		
		// Set the ERASE command bit.
Memory(FLASH_BASE_REG,FLASH_CONTOL_R)= (Flash_Key << 16) ;
		Memory(FLASH_BASE_REG,FLASH_CONTOL_R)|= 0x2; 

		// Poll the ERASE bit until it is cleared.
		while (Memory(FLASH_BASE_REG,FLASH_CONTOL_R)& 0x2) {}
	
	}
	
	return 0;
}
	
	int Flash_Write(const void* data, int wordCount)
	{
		
		if (Flash_Key == 0) {
		return -1;// FLash is not enabled
	}
		
		int blockCount = ((wordCount * sizeof(uint32_t)) / 1024) + 1;
	Flash_Erase(blockCount);
	for (int i = 0; i < wordCount; i++) {
	
		// Set the data register.  This the word that will be written.
		Memory(FLASH_BASE_REG,FLASH_DATA_R) = ((volatile uint32_t*)data)[i];
		
		Memory(FLASH_BASE_REG,FLASH_ADDRESSE_RE) &= 0xFFFC0000;  
	Memory(FLASH_BASE_REG,FLASH_ADDRESSE_RE) |= (uint32_t)FLASH_BASE_ADDR + (i * sizeof(uint32_t));
		
		// Trigger a write operation...
		Memory(FLASH_BASE_REG,FLASH_CONTOL_R)= (Flash_Key  << 16);
Memory(FLASH_BASE_REG,FLASH_CONTOL_R)|=0x1;
		// Poll the WRITE bit until it is cleared.
		while (Memory(FLASH_BASE_REG,FLASH_CONTOL_R) & 0x1) {}
			
	}
	
	return 0;
		
	}
	void Flash_Read(void* data, int wordCount)
{
	// Copy the count of bytes into the target data buffer...
	for (int i = 0; i < wordCount; i++) {
		((uint32_t*)data)[i] = FLASH_BASE_ADDR[i];
	}
}
	
