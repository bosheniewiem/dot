# Installation
## 1. Install packages
```
$ sudo xbps-install xorg xinit nvidia iwd zsh pulseaudio alsa-utils feh rxvt-unicode bspwm sxhkd openbox dunst libnotify neovim void-repo-multilib void-repo-nonfree void-repo-multilib-nonfree lxappearance lxappearance-obconf redshift firefox xtools 
<<<<<<< HEAD
```
=======
``
>>>>>>> 8771b5951692ba20c232b6030e5973382854844f

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

## 4. Install lemonbar
```
$ git clone https://github.com/drscream/lemonbar-xft.git
```

## 5. Reload fonts
```
$ fc-cache -fv
```

## 6. Install oh-my-zsh
```
$ sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"
```

## 7. Build picom
```
https://github.com/ibhagwan/picom
https://github.com/ibhagwan/picom-ibhagwan-template - for void users
```

## 8. Build dmenu from ~/.config/dmenu

## 9. remove xorg-fonts (void users cuz of ugly firefox fonts rendering)

# Everything is done
## Commiting
```
$ dots status
$ dots pull
$ dots add
$ dots commit
$ dots push
```
