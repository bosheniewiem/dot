# Installation
## 1. Install packages
```
$ sudo apt install redshift dhcpcd5 lxappearance gcc libnotify-bin make ffmpeg xorg xinit x11-xserver-utils mpd mpc ncmpcpp iwd feh htop maim xclip alsa-utils pulseaudio pavucontrol rxvt-unicode curl git bspwm sxhkd neovim zsh xbacklight dunst compton
```

## 2. Clone repo
```
$ git clone --bare https://github.com/bosheniewiem/dot.git ~/.config/dot
$ alias dots='git --git-dir ~/.config/dot/ --work-tree ~'
$ dots config --local status.showUntrackedFiles no
$ dots checkout -f
```

## 3. Change shell
```
$ chsh -s /usr/bin/zsh
```

## 4. Install dmenu
```
$ git clone https://github.com/bosheniewiem/dmenu.git
```

## 5. Install doas
```
$ git clone https://github.com/slicer69/doas.git 
```

## 6. Install lemonbar
```
$ git clone https://github.com/drscream/lemonbar-xft.git
```

## 7. Wallpapers
[Wallpaper Collector mega.nz](https://mega.nz/folder/PpohCIpT#tII4Q60AFpgfnEYFywwlow)

## 8. Reload fonts
```
$ fc-cache -fv
```

## 9. Install oh-my-zsh
```
https://github.com/ohmyzsh/ohmyzsh
```

## 10. Delete github repo files from ~

# Everything is done
## Commiting
```
$ dots status
$ dots pull
$ dots add
$ dots commit
$ dots push
```
