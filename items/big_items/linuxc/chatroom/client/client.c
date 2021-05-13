#include "../include/sdebug.info.h"
#include "../include/wrap.h"

int main(int argc, char **argv)
{
    printf("登录请输入你的用户名\n");
    printf("注册请输入你想要的用户名\n");
    printf("(不超过15个字符)\n");
    char username[20];
    char password[20];
    memset(username, 0, sizeof(username));
    memset(password, 0, sizeof(password));
    scanf("%19s", username);
    if (accessusername(username))
    {
        int errornumber = 0;
    again:
        printf("请输入密码:\n");
        scanf("%19s", password);

        if (accesspassword(password))
        {

            if (useronline(username))
            {
                printf("您的账号已在别处下线\n");
            }

            printf("登录成功\n");
        }
        else
        {
            errornumber++;
            if (errornumber == 3)
            {
                printf("密码错误次数太多，暂时锁定帐号%s,一分钟以后重新登陆\n", username);
                exit(0);
            }
            else
            {
                printf("密码错误\n");
                goto again;
            }
        }
    }
    else //注册
    {
        printf("-----------------注册:\n用户名:%s\n密码:", username);
        scanf("%19s", password);


        //mysql



        printf("-----------------注册成功\n");
        printf("您的用户名\n%s\n您的密码\n%s\n请妥善保管\n", username, password);
    }

    showmainmenu();
}