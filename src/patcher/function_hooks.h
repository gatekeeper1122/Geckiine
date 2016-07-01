#ifndef _FUNCTION_HOOKS_H_
#define _FUNCTION_HOOKS_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
//#define MAX_CLIENT 32
#define MASK_FD 0x0fff00ff

/*struct bss_t {
    int global_sock;
    int socket_fs[MAX_CLIENT];
    void *pClient_fs[MAX_CLIENT];
    volatile int lock;
    char mount_base[255];
    char save_base[255];
	void* file_replacer;
	char update_path[50];
	char save_dir_common[7];
    char save_dir_user[9];
};*/
	
struct fs_async_t {
	void (*callback)(int status, int command, void *request, void *response, void *context);
	void *context;
	void *queue;
};

//#define bss_ptr (*(struct bss_t **)0x100000e4)
//#define bss (*bss_ptr)

void PatchMethodHooks(void);
void RestoreInstructions(void);
unsigned int GetAddressOfFunction(const char * functionName,unsigned int library);
int isDynamicFunction(unsigned int physicalAddress);
void PatchSDK(void);

#ifdef __cplusplus
}
#endif

#endif /* _FS_H */
