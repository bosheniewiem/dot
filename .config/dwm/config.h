/* See LICENSE file for copyright and license details. */
#include <X11/XF86keysym.h>

/* appearance */
static const unsigned int borderpx  = 5;        /* border pixel of windows */
static const unsigned int snap      = 0;        /* snap pixel */
static const unsigned int gappih    = 18;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 18;       /* vert inner gap between windows */
static const unsigned int gappoh    = 18;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 18;       /* vert outer gap between windows and screen edge */
static const int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int vertpad            = 16;       /* vertical padding of bar */
static const int sidepad            = 70;       /* horizontal padding of bar */
static const char *fonts[]          = { "kiwi:pixelsize=12",
                                        "waffle:pixelsize=12" };
/* colorbar */
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { "#fff", "#fff", "#D4D8E9" },           // Border normal
	[SchemeSel]  = { "#fff", "#fff", "#82a0bf"  },          // Border selected
	[SchemeStatus]  = { "#dfdfdf", "#2e3440",  "#000"  },   // Statusbar right
	[SchemeTagsSel]  = { "#2e3440", "#82a0bf",  "#fff"  },  // Tagbar left selected
    [SchemeTagsNorm]  = { "#dfdfdf", "#2e3440",  "#fff"  }, // Tagbar left unselected
    [SchemeInfoSel]  = { "#2e3440", "#82a0bf",  "#fff"  },  // infobar middle  selected 
    [SchemeInfoNorm]  = { "#2e3440", "#82a0bf",  "#fff"  }, // infobar middle  unselected 
};

/* autostart */
static char* const autostart[][6] = { /* please replace 2 with maximum number of arguments from autostart array */
    { "xrdb", "/home/bosheniewiem/.config/x/Xresources", NULL },
    { "sh", "-c", "feh --bg-fill --no-fehbg /home/bosheniewiem/.local/share/tmp/wallpapers/1.jpg", NULL },
    { "dwmbar", NULL},
    { "xset", "b", "off", NULL },
    { "setxkbmap", "pl", NULL },
    { "xset", "r", "rate", "200", "25", NULL },
    { "xsetroot", "-cursor_name", "left_ptr", NULL },
    { "picom", "--config", "/home/bosheniewiem/.config/compositor/config", NULL },
    { "start-pulseaudio-x11", NULL },
    { "mpd", NULL},
    { "dunst", NULL },
    { "redshift", "-P", "-O", "4700k", NULL }
};

/* workspaces */
static const char *tags[] = { " 1 ", " 2 ", " 3 ", " 4 ", " 5 ", " 6 ", " 7 ", " 8 ", " 9 " };
/* static const char *tags[] = { "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  " }; */
/* static const char *tags[] = { "  ", "  ", "  ", "  ", "  ", "  " }; */

/* rules */
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     iscentered   isfloating   monitor */
      {NULL,      NULL,       NULL,       0,            1,           0,           -1}, 
      { "microsoft teams - preview",     NULL,   NULL,       0,       0,       1,       -1},
};

/* layout(s) */
static const float mfact     = 0.5;  /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define ALTKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },
#define STACKKEYS(MOD,ACTION) \
    { MOD, XK_j,     ACTION##stack, {.i = INC(+1) } }, \
    { MOD, XK_k,     ACTION##stack, {.i = INC(-1) } }, \
    { MOD, XK_grave, ACTION##stack, {.i = PREVSEL } }, \
    { MOD, XK_q,     ACTION##stack, {.i = 0 } }, \
    { MOD, XK_a,     ACTION##stack, {.i = 1 } }, \
    { MOD, XK_z,     ACTION##stack, {.i = 2 } }, \
    { MOD, XK_x,     ACTION##stack, {.i = -1 } },

/* helper for spawning shell commands*/
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "launcher", NULL };
static const char *termcmd[]  = { "st", NULL };

/* Keybinds */
static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_d,      spawn,          {.v = dmenucmd} },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
    { MODKEY,                       XK_t,      spawn,          SHCMD("themes") },
    { MODKEY,                       XK_x,      spawn,          SHCMD("record") },
    { MODKEY|ShiftMask,             XK_x,      spawn,          SHCMD("pkill ffmpeg") },
    { MODKEY,                       XK_k,      spawn,          SHCMD("notify-send 'This is a notification'") },
    { 0,                            XK_Print,  spawn,          SHCMD("cheese") },
    { ALTKEY,                       XK_Print,  spawn,          SHCMD("cheese -s") },
    { 0,                            XF86XK_MonBrightnessDown,       spawn,      SHCMD("brightnessctl s 5%-") },
    { 0,                            XF86XK_MonBrightnessUp,         spawn,      SHCMD("brightnessctl s +5%") },
    { 0,                            XF86XK_AudioRaiseVolume,        spawn,      SHCMD("pactl set-sink-volume @DEFAULT_SINK@ +1%") },
    { 0,                            XF86XK_AudioLowerVolume,        spawn,      SHCMD("pactl set-sink-volume @DEFAULT_SINK@ -1%") },
    { 0,                            XF86XK_AudioMute,               spawn,      SHCMD("pactl set-sink-mute @DEFAULT_SINK@ toggle") },
	{ MODKEY|ShiftMask,             XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_r,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_c,      togglebar,      {0} },
	{ MODKEY,                       XK_f,      fullscreen,     {0} },
	{ MODKEY,                       XK_space,  togglefloating, {0} },


    { MODKEY,                       XK_a,      setlayout,      {.v = &layouts[0]} },
    { MODKEY,                       XK_s,      setlayout,      {.v = &layouts[1]} },
    { MODKEY,                       XK_z,      setlayout,      {.v = &layouts[2]} },
    { MODKEY,                       XK_q,      setlayout,      {0} },

    
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_Escape,    quit,       {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

