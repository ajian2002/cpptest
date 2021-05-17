#!/usr/bin/python3
##!/bin/sh
import os,subprocess
# cmd="cd /tmp && mkdir aa && cd "

# file=open('/etc/pacman.d/mirrorlist','r+')
# file.write("Server = http://mirrors.163.com/archlinux/$repo/os/$arch\n")
# file.write("Server = http://mirrors.bfsu.edu.cn/archlinux/$repo/os/$arch\n")
# file.write("Server = https://mirrors.bfsu.edu.cn/archlinux/$repo/os/$arch\n")
# file.write("Server = http://mirrors.cqu.edu.cn/archlinux/$repo/os/$arch\n")
# file.write("Server = https://mirrors.cqu.edu.cn/archlinux/$repo/os/$arch\n")
# file.write("Server = http://mirrors.dgut.edu.cn/archlinux/$repo/os/$arch\n")
# file.write("Server = https://mirrors.dgut.edu.cn/archlinux/$repo/os/$arch\n")
# file.write("Server = http://mirrors.hit.edu.cn/archlinux/$repo/os/$arch\n")
# file.close()



print(' ping baidu.com .....')
cmd="ping -c 3 baidu.com "
res = subprocess.run(cmd, shell=True,check=True,stdout=subprocess.DEVNULL)
if(res.returncode!=0):
    print('[error]'+cmd)
    exit(res.returncode)
else:
    print('[success]'+cmd)
cmd ='timedatectl set-ntp true'
res = subprocess.run(cmd, shell=True,check=True,stdout=subprocess.DEVNULL)
if(res.returncode!=0):
    print('[error]'+cmd)
    exit(res.returncode)
else:
    print('[success]'+cmd)






# pacstrap /mnt base base-devel linux linux-firmware linux-headers 
# pacstrap /mnt base base-devel linux-firmware  
# pacstrap /mnt linux linux-headers
# genfstab -U /mnt >> /mnt/etc/fstab
# 
# arch-chroot /mnt
# 
# 
# ln -sf /usr/share/zoneinfo/Asia/Shanghai /etc/localtime
# hwclock --systohc --utc
# nano /etc/locale.gen
# #en_US.UTF-8 UTF-8、#zh_CN.UTF-8 UTF-8、#zh_TW.UTF-8 UTF-8
#  locale-gen
# echo LANG=en_US.UTF-8 > /etc/locale.conf
#   echo myhostname > /etc/hostname
# pacman -S grub  efibootmgr dosfstools

# pacman -S os-prober  ntfs-3g
# 
# grub-install --target=x86_64-efi --efi-directory=/boot --bootloader-id=grub --recheck
# grub-mkconfig -o /boot/grub/grub.cfg

# EDITOR=nano visudo
## %wheel ALL=(ALL) ALL
# passwd
# useradd -m -G wheel username
# passwd username

# 桌面环境



################################

# 字体
# # pacman -S noto-fonts noto-fonts-cjk noto-fonts-emoji noto-fonts-extra
# 
# # pacman -S adobe-source-han-sans-cn-fonts
# # pacman -S adobe-source-han-serif-cn-fonts
# pacman -S ttf-sarasa-gothic

# pacman -S networkmanager
# systemctl enable NetworkManager

# 重启
#
#/etc/pacman.conf
#
# [archlinuxcn]
# Server = https://repo.archlinuxcn.org/$arch
#
#$ sudo pacman -Syy && sudo pacman -S archlinuxcn-keyring
# $ sudo pacman -S archlinuxcn-mirrorlist-git
#
# /etc/pacman.d/mirrorlist
#Server = https://repo.archlinuxcn.org/$arch
# Include = /etc/pacman.d/archlinuxcn-mirrorlist
# 
# 
# /etc/pacman.d/archlinuxcn-mirrorlist
# 
# 
# 
#  sudo pacman -S fcitx fcitx-im fcitx-libpinyin kcm-fcitx
#  ||kDE
#  sudo pacman -S kcm-fcitx
# 
# ~/.pam_environment
#
# GTK_IM_MODULE DEFAULT=fcitx
#QT_IM_MODULE  DEFAULT=fcitx
# XMODIFIERS    DEFAULT=@im=fcitx
# 
# 
# 
# 
# $ sudo pacman -S bluez bluez-utils pulseaudio-bluetooth
#$ sudo modprobe btusb
#$ sudo systemctl enable bluetooth.service
#$ sudo systemctl start bluetooth.service
# 
# 
# ~/.config/locale.conf
# #
# LANG=zh_CN.UTF-8
# LC_CTYPE="zh_CN.UTF-8"
# LC_NUMERIC="zh_CN.UTF-8"
# LC_TIME="zh_CN.UTF-8"
# LC_COLLATE="zh_CN.UTF-8"
# LC_MONETARY="zh_CN.UTF-8"
# LC_MESSAGES="zh_CN.UTF-8"
# LC_PAPER="zh_CN.UTF-8"
# LC_NAME="zh_CN.UTF-8"
# LC_ADDRESS="zh_CN.UTF-8"
# LC_TELEPHONE="zh_CN.UTF-8"
# LC_MEASUREMENT="zh_CN.UTF-8"
# LC_IDENTIFICATION="zh_CN.UTF-8"
# LC_ALL=


#  sudo pacman -S zsh oh-my-zsh-git zsh-syntax-highlighting zsh-autosuggestions autojump
# $ sudo chsh -s /bin/zsh username
# $ sudo ln -s /usr/share/zsh/plugins/zsh-syntax-highlighting /usr/share/oh-my-zsh/custom/plugins/
# $ sudo ln -s /usr/share/zsh/plugins/zsh-autosuggestions /usr/share/oh-my-zsh/custom/plugins/
# $ zsh








# ~/.zshrc
# autojump git zsh-syntax-highlighting zsh-autosuggestions









