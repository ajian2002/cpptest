#include "../../include/chat.h"

extern char configpath[30];
extern char configlist[30];
/*CONFIG*/
extern bool ifdebug;
extern bool ifserverlog;
extern char serverlogpath[30];
extern int defaultport;
//extern char serverip[30];

/* SELF */
extern bool PRINTEXIT;
extern bool DEBUGPRINT;
extern bool WRITE_LOG;
#define JSONMAXLEN 4096

void setconfig(void)
{

    int configfd, configlistfd;
    char bufjson[JSONMAXLEN] = {0};
    char configlistname[10][30];
    int i = 0;
    //读配置key
    if (access(configlist, F_OK) == 0)
    {
        if (access(configlist, R_OK) == 0)
        {
            configlistfd = open(configlist, O_RDONLY);
            while (Readline(configlistfd, configlistname[i], 30))
            {
                configlistname[i][strlen(configlistname[i]) - 1] = '\0';
                i++;
            }
            for (int j = 0; j < i; j++)
            {
                ;
                //DEBUGPRINT("%s", configlistname[j]);
            }
        }
        else
        {
            ;
            PRINTEXIT("can't read configlist");
        }
    }
    else
    {
        ;
        PRINTEXIT("no configlist file");
    }

    //读配置文件
    if (access(configpath, F_OK) == 0)
    {
        if (access(configpath, R_OK) == 0)
        {
            configfd = open(configpath, O_RDONLY);
            if (read(configfd, bufjson, JSONMAXLEN)) //读完
            {
                if (read(configfd, bufjson, JSONMAXLEN) != 0)
                {
                    ;
                    PRINTEXIT("not read all");
                }
                cJSON *configjson = cJSON_Parse(bufjson);
                if (configjson == NULL)
                {
                    ;
                    PRINTEXIT("not json");
                }

                cJSON *item = NULL;
                for (--i; i > -1; i--)
                {
                    item = cJSON_GetObjectItem(configjson, configlistname[i]);
                    if (cJSON_IsBool(item))
                    {
                        if (strcmp(configlistname[i], "ifdebug") == 0)
                            ifdebug = item->valueint;
                        if (strcmp(configlistname[i], "ifserverlog") == 0)
                            ifserverlog = item->valueint;
                    }
                    if (cJSON_IsNumber(item))
                    {
                        if (strcmp(configlistname[i], "defaultport") == 0)
                            defaultport = item->valueint;
                    }
                    if (cJSON_IsString(item))
                    {
                        // if (strcmp(configlistname[i], "serverip") == 0)
                        // {
                        //     memset(serverip, 0, sizeof(serverip));
                        //     strcpy(serverip, item->valuestring);
                        // }
                        if (strcmp(configlistname[i], "serverlogpath") == 0)
                        {
                            memset(serverlogpath, 0, sizeof(serverlogpath));
                            strcpy(serverlogpath, item->valuestring);
                        }
                    }
                }

                cJSON_Delete(configjson);
                //DEBUGPRINT("ifdebug:%d\nifserverlog:%d\nserverlogpath:%s\ndefaultport:%d\nserverip:%s\n", ifdebug, ifserverlog, serverlogpath, defaultport, serverip);
            }
            else
            {
                ;
                PRINTEXIT("read error");
            }
        }
        else
        {
            ;
            PRINTEXIT("can't read config");
        }
    }
    else
    {
        ;
        PRINTEXIT("no config file");
    }
}
